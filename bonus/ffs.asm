BITS 64

SECTION .text
GLOBAL ffs

ffs:
    XOR RCX, RCX
    CMP RDI, 0
    JE end
    INC RCX
    MOV RAX, RDI
    JMP check_bit

check_bit:
    TEST RAX, 1
    JNZ end
    INC RCX
    SHR RAX, 1
    JMP check_bit

end:
    MOV RAX, RCX
    RET
