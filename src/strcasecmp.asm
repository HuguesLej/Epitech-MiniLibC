BITS 64

SECTION .text
GLOBAL strcasecmp

strcasecmp:
    MOV R8B, BYTE [RDI]
    MOV R9B, BYTE [RSI]

    CMP R8B, 0
    JE check_case_r8
    CMP R9B, 0
    JE check_case_r8

    CMP R8B, R9B
    JNE check_case_r8

    JMP increase_strings

check_case_r8:
    CMP R8B, 'A'
    JL check_case_r9
    CMP R8B, 'Z'
    JG check_case_r9
    ADD R8B, 32
    JMP check_case_r9

check_case_r9:
    CMP R9B, 'A'
    JL calc_diff
    CMP R9B, 'Z'
    JG calc_diff
    ADD R9B, 32
    JMP case_compare

case_compare:
    CMP R8B, R9B
    JNE calc_diff
    JMP increase_strings

increase_strings:
    INC RDI
    INC RSI
    JMP strcasecmp

calc_diff:
    SUB R8B, R9B
    MOVSX RAX, R8B
    RET
