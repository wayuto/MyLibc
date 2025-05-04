#ifndef MALLOC_H
#define MALLOC_H

#define ALIGNMENT 16

#include "string.h"
#include "stddef.h"

extern int brk(void *addr);
typedef struct block_meta {
    size_t size;
    struct block_meta *next;
    int free;
} block_meta;
static block_meta *free_list = NULL;
static void *current_break = NULL;

void *sbrk(long long increment) {
    if (current_break == NULL) sbrk(0);
    void *old_break = current_break;

    if (brk(old_break + increment) == 0) {
        current_break += increment;
        return old_break;
    } else {
        return (void*)-1;
    }
}

void split_block(block_meta *block, size_t size) {
    block_meta *new_block = (block_meta *)((char*)block + sizeof(block_meta) + size);
    new_block->size = block->size - size - sizeof(block_meta);
    new_block->free = 1;
    new_block->next = block->next;
    block->size = 0;
    block->next = new_block;
}

void *request_memory(size_t size) {
    block_meta *block = sbrk(sizeof(block_meta) + size);
    if (block == (void*)-1) return NULL;
    block->size = size;
    block->free = 0;
    block->next = NULL;
    return (void*)(block + 1);
}

void coalesce_block() {
    block_meta *curr = free_list;
    while (curr && curr->next) {
        if ((char*)curr + sizeof(block_meta) + curr->size == (char*)curr->next) {
            curr->size += sizeof(block_meta) + curr->size;
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
}

void *malloc(size_t size) {
    if (size <= 0) return NULL;
    size = (size + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
    block_meta *block = free_list;
    block_meta **prev = &free_list;

    while (block) {
        if (block->free && block->size >= size) {
            if (block->size > size + sizeof(block_meta)) split_block(block, size);
            block->free = 0;
            return (void*)(block + 1);
        }
        prev = &block->next;
        block = block->next;
    }

    return request_memory(size);
}

void free(void *ptr) {
    if (!ptr) return;
    block_meta *block = (block_meta *)(ptr - 1);
    block->free = 1;

    coalesce_block();
}

void *realloc(void *ptr, size_t size) {
    if (!ptr) return malloc(size);
    if (!size) {
        free(ptr);
        return NULL;
    }

    block_meta *block = (block_meta *)(ptr - 1);
    if (block->size >= size) {
        if (block->size > size + sizeof(block_meta))
            split_block(block, size);
        return ptr;
    }

    void* new_ptr = malloc(size);
    if (new_ptr) {
        memcpy(new_ptr, ptr, size);
        free(ptr);
    }

    return new_ptr;
}

#endif // MALLOC_H