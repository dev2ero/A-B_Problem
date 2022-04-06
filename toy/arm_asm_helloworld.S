.section .data
hello:
    .ascii "hello world\n"
    .equ len, . - hello

.section .text
.global _start
_start:
    mov r0, #1
    ldr r1, =hello
    mov r2, #len
    mov r7, #4
    swi #0

exit:
    mov r0, #0
    mov r7, #1
    swi #0