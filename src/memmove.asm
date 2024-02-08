BITS 64

SECTION .text
GLOBAL memmove

memmove:
    PUSH RBP
    MOV RBP, RSP
    CMP RDX, 0
    JE end
    SUB RSP, RDX
    XOR RCX, RCX
    JMP copy_src

copy_src:
    CMP RCX, RDX
    JE reinit_rcx
    MOV AL, BYTE [RSI + RCX]
    MOV BYTE [RSP + RCX], AL
    INC RCX
    JMP copy_src

reinit_rcx:
    XOR RCX, RCX
    JMP move_loop

move_loop:
    CMP RCX, RDX
    JE end
    MOV AL, BYTE [RSP + RCX]
    MOV BYTE [RDI + RCX], AL
    INC RCX
    JMP move_loop

end:
    MOV RAX, RDI
    LEAVE
    RET
