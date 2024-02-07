BITS 64

SECTION .text
GLOBAL strlen

strlen:
    MOV RCX, -1
    CALL loop
    MOV RAX, RCX
    RET

loop:
    INC RCX
    CMP BYTE [RDI + RCX], 0
    JNE loop
    RET
