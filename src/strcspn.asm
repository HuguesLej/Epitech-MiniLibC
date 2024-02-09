BITS 64

SECTION .text
GLOBAL strcspn

strcspn:
    XOR RCX, RCX
    XOR RDX, RDX

char_cmp:
    MOV R8B, BYTE [RDI + RDX]
    MOV R9B, BYTE [RSI + RCX]

    CMP R8B, 0
    JE end

    CMP R9B, 0
    JE next_rdi_char

    CMP R8B, R9B
    JE end

    INC RCX
    JMP char_cmp

next_rdi_char:
    XOR RCX, RCX
    INC RDX
    JMP char_cmp

end:
    MOV RAX, RDX
    RET
