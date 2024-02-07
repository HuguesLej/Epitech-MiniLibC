BITS 64

SECTION .text
GLOBAL memcpy

memcpy:
    XOR RCX, RCX
    JMP loop

loop:
    CMP RCX, RDX
    JE end
    MOV AL, BYTE [RSI + RCX]
    MOV BYTE [RDI + RCX], AL
    INC RCX
    JMP loop

end:
    MOV RAX, RDI
