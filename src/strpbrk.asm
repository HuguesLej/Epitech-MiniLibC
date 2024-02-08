BITS 64

SECTION .text
GLOBAL strpbrk

strpbrk:
    XOR RCX, RCX
    XOR RAX, RAX
    MOV R8B, BYTE [RDI]
    MOV R9B, BYTE [RSI]
    CMP R8B, 0
    JE end
    CMP R9B, 0
    JE end

char_cmp:
    MOV R8B, BYTE [RDI]
    MOV R9B, BYTE [RSI + RCX]

    CMP R8B, 0
    JE end

    CMP R9B, 0
    JE next_rdi_char

    CMP R8B, R9B
    JE store_rdi

    INC RCX
    JMP char_cmp

next_rdi_char:
    XOR RCX, RCX
    INC RDI
    JMP char_cmp

store_rdi:
    MOV RAX, RDI

end:
    RET
