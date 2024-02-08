BITS 64

SECTION .text
GLOBAL strncmp

strncmp:
    XOR RCX, RCX
    JMP loop

loop:
    CMP RCX, RDX
    JE end_zero

    MOV R8B, BYTE [RDI]
    MOV R9B, BYTE [RSI]

    CMP R8B, 0
    JE calc_diff
    CMP R9B, 0
    JE calc_diff

    CMP R8B, R9B
    JNE calc_diff

    INC RDI
    INC RSI
    INC RCX

    JMP loop

calc_diff:
    SUB R8B, R9B
    MOVSX RAX, R8B
    RET

end_zero:
    MOV RAX, 0
    RET
