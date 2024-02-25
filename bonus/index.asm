BITS 64

SECTION .text
GLOBAL index

index:
    CMP BYTE [RDI], SIL
    JE end
    CMP BYTE [RDI], 0
    JE end_zero
    INC RDI
    JMP index

end:
    MOV RAX, RDI
    RET

end_zero:
    XOR RAX, RAX
    RET
