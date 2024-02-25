BITS 64

SECTION .text
GLOBAL rindex

rindex:
    XOR RCX, RCX

go_to_end_of_str:
    CMP BYTE [RDI + RCX], 0
    JE search_char
    INC RCX
    JMP go_to_end_of_str

search_char:
    CMP BYTE [RDI + RCX], SIL
    JE end
    CMP RCX, 0
    JE end_zero
    DEC RCX
    JMP search_char

end:
    LEA RAX, [RDI + RCX]
    RET

end_zero:
    XOR RAX, RAX
    RET
