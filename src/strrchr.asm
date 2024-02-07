BITS 64

SECTION .text
GLOBAL strrchr

strrchr:
    XOR RCX, RCX
    JMP compare

compare:
    CMP BYTE [RDI], SIL
    JE store_ptr
    JMP inc_ptr

store_ptr:
    MOV RAX, RDI
    INC RCX
    JMP inc_ptr

inc_ptr:
    CMP BYTE [RDI], 0
    JE end
    INC RDI
    JMP compare

end:
    CMP RCX, 0
    JE end_zero
    RET

end_zero:
    XOR RAX, RAX
    RET
