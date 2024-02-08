BITS 64

SECTION .text
GLOBAL strcmp

strcmp:
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
    JMP strcmp

calc_diff:
    SUB R8B, R9B
    MOVSX RAX, R8B
    RET
