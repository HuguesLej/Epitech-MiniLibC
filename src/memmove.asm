BITS 64

SECTION .text
GLOBAL memmove

memmove:
    CMP RDX, 0
    JE end
    XOR RCX, RCX
    JMP copy_src

copy_src:
    CMP RCX, RDX
    JE reinit_rcx
    MOV AL, BYTE [RSI + RCX]
    MOV BYTE [R8 + RCX], AL
    INC RCX
    JMP copy_src

reinit_rcx:
    XOR RCX, RCX
    MOV RSI, R8
    JMP move_loop

move_loop:
    CMP RCX, RDX
    JE end
    MOV AL, BYTE [R8 + RCX]
    MOV BYTE [RDI + RCX], AL
    INC RCX
    JMP move_loop

end:
    MOV RAX, RDI
    RET
