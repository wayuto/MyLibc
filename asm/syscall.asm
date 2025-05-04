section .text
    global execv, exit, fork, waitid

exit:
    mov rax, 60
    syscall
    ret

execv:
    mov rax, 59
    mov rsi, rsi
    mov rdi, rdi
    mov rdx, rdx
    syscall
    ret

fork:
    mov rax, 57
    mov rsi, rsi
    mov rdi, rdi
    mov rdx, rdx
    syscall
    ret

waitid:
    mov rax, 61
    mov rsi, rsi
    mov rdi, rdi
    mov rdx, rdx
    syscall
    ret