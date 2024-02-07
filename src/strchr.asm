BITS 64

SECTION .text
GLOBAL strchr

strchr:
    CMP BYTE [RDI], SIL
    JE end
    CMP BYTE [RDI], 0
    JE end_zero
    INC RDI
    JMP strchr

end:
    MOV RAX, RDI
    RET

end_zero:
    MOV RAX, 0
    RET
