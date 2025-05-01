section .text
    global open, read, write, close

open:
    mov rax, 2
    mov rdi, rdi
    mov rsi, rsi
    mov rdx, rdx
    syscall
    ret

read:
    mov rax, 0
    mov rdi, rdi
    mov rsi, rsi
    mov rdx, rdx
    syscall
    ret

write:
    mov rax, 1
    mov rdi, rdi
    mov rsi, rsi
    mov rdx, rdx
    syscall
    ret

close:
    mov rax, 3
    syscall
    ret