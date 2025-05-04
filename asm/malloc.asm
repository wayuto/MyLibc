section .text
    global brk

brk:
    mov rax, 12
    mov rdi, rdi
    mov rsi, rsi
    mov rdx, rdx
    syscall
    ret