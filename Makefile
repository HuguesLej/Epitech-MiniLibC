##
## EPITECH PROJECT, 2023
## MinilibC
## File description:
## Makefile for lem_in
##

SRC	=	\
	src/strlen.asm		\
	src/strchr.asm		\
	src/strrchr.asm		\
	src/memset.asm		\
	src/memcpy.asm		\
	src/strcmp.asm		\
	src/memmove.asm		\
	src/strncmp.asm		\
	src/strcasecmp.asm	\
	src/strstr.asm		\
	src/strpbrk.asm		\
	src/strcspn.asm		\
	\
	bonus/ffs.asm		\
	bonus/index.asm		\
	bonus/rindex.asm

TEST_SRC	=	\
	tests/strlen.c		\
	tests/strchr.c		\
	tests/strrchr.c		\
	tests/memset.c		\
	tests/memcpy.c		\
	tests/strcmp.c		\
	tests/memmove.c		\
	tests/strncmp.c		\
	tests/strcasecmp.c	\
	tests/strstr.c		\
	tests/strpbrk.c		\
	tests/strcspn.c

BUILD	=	build

AS	=	nasm

ASFLAGS	=	-f elf64

LD	=	ld

LDFLAGS	=	-shared

CC	=	gcc

CCFLAGS	=	-Wall -Wextra --coverage -lcriterion

OBJ	=	$(SRC:%.asm=$(BUILD)/%.o)

TEST_OBJ	=	$(TEST_SRC:%.c=$(BUILD)/%.o)

MAKEFLAGS	=	--no-print-directory

NAME	=	libasm.so

TEST_NAME	=	crit_tests

DIE	=	exit 1

%.asm:
	@echo -e "\033[1;31mFile not found: $@\033[0m" && $(DIE)

%.c:
	@echo -e "\033[1;31mFile not found: $@\033[0m" && $(DIE)

$(BUILD)/%.o: %.asm
	@mkdir -p $(@D)
	@$(AS) $(ASFLAGS) $< -o $@ || $(DIE)

$(BUILD)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $@ || $(DIE)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(LD) -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo -e "\033[1;36m[$(NAME)]: Successfully build\033[0m"
	@echo -e "\033[1;36mCompiled $(shell echo "$?" | wc -w) file(s)\033[0m"

clean:
	@rm -f $(OBJ)
	@rm -f $(TEST_OBJ)
	@echo -e "\033[1;33m[$(NAME)]: Object files successfully cleaned\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(TEST_NAME)
	@echo -e "\033[1;33m[$(NAME)]: Binary file successfully cleaned\033[0m"

re:	fclean all

tests_run:	$(TEST_OBJ)
	@$(CC) -o $(TEST_NAME) $(TEST_OBJ) $(CCFLAGS) ./$(NAME)
	@echo -e "\033[1;36m[$(TEST_NAME)] successfully build\033[0m"
	@echo -e "\033[1;36mCompiled $(shell echo "$?" | wc -w) file(s)\033[0m"
	@./$(TEST_NAME)

cov:
	@gcovr --exclude tests/

covbr:
	@gcovr --exclude tests/ --branches

.PHONY:	all clean fclean re
