BITS 64

SECTION .text
GLOBAL index

index:
    CMP BYTE [RDI], SIL
    JE end
    INC RDI
    JMP index

end:
    MOV RAX, RDI
    RET
