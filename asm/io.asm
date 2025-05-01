section .text
    global couts
    global cins

couts:
    push rbx
    mov rbx, rdi

    xor rcx, rcx
    .loop:
        cmp byte [rbx + rcx], 0
        je .end_loop
        inc rcx
        jmp .loop
    .end_loop:

        mov rax, 1
        mov rdi, 1
        mov rsi, rbx
        mov rdx, rcx
        syscall

    pop rbx
    ret


cins:
    push rbp
    mov rbp, rsp

    mov rax, 0
    mov rsi, rdi
    mov rdi, 0
    mov rdx, 1024
    syscall

    mov rcx, rax
    dec rcx
    .f_nl:
        cmp byte [rsi + rcx], 0xa
        je .r_nl
        dec rcx
        jns .f_nl

        mov byte [rsi + rax], 0
        jmp .done

    .r_nl:
        mov byte [rsi + rcx], 0

    .done:
        pop rbp
        ret

exit:
    mov rax, 60
    syscall
    ret