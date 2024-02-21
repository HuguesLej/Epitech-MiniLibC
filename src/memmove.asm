BITS 64

SECTION .text
GLOBAL memmove

memmove:
    CMP RDX, 0
    JE end
    CMP RSI, 0
    JE verify_snd_str
    JMP choose_loop

verify_snd_str:
    CMP RDI, 0
    JE end
    JMP choose_loop

choose_loop:
    XOR RCX, RCX
    CMP RDI, RSI
    JLE move_inc
    JMP move_dec

move_inc:
    CMP RCX, RDX
    JE end
    MOV AL, BYTE [RSI + RCX]
    MOV BYTE [RDI + RCX], AL
    INC RCX
    JMP move_inc

move_dec:
    CMP RDX, 0
    JE end
    MOV AL, BYTE [RSI + RDX - 1]
    MOV BYTE [RDI + RDX - 1], AL
    DEC RDX
    JMP move_dec

end:
    MOV RAX, RDI
    RET
