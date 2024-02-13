BITS 64

SECTION .text
GLOBAL strstr

strstr:
    XOR RAX, RAX
    XOR RCX, RCX
    XOR RDX, RDX
    MOV R9B, BYTE [RSI]
    CMP R9B, 0
    JE rsi_zero
    MOV R8B, BYTE [RDI]
    CMP R8B, 0
    JE end

char_cmp:
    MOV R8B, BYTE [RDI + RCX]
    MOV R9B, BYTE [RSI]

    CMP R8B, 0
    JE end

    CMP R8B, R9B
    JE store_rdi

    JMP return_to_char_cmp

store_rdi:
    LEA RAX, [RDI + RCX]
    MOV R10, RCX

cmp_needle:
    MOV R8B, BYTE [RDI + R10]
    MOV R9B, BYTE [RSI + RDX]

    CMP R9B, 0
    JE end

    CMP R8B, 0
    JE end_zero

    CMP R8B, R9B
    JNE return_to_char_cmp

    INC R10
    INC RDX
    JMP cmp_needle

return_to_char_cmp:
    INC RCX
    XOR RDX, RDX
    XOR RAX, RAX
    JMP char_cmp

rsi_zero:
    MOV RAX, RDI
    JMP end

end_zero:
    XOR RAX, RAX

end:
    RET
