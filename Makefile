##
## EPITECH PROJECT, 2023
## MinilibC
## File description:
## Makefile for lem_in
##

SRC	=	\
	src/strlen.asm	\
	src/strchr.asm	\
	src/strrchr.asm

BUILD	=	build

AS	=	nasm

ASFLAGS	=	-f elf64

CC	=	gcc

CCFLAGS	=	-shared

OBJ	=	$(SRC:%.asm=$(BUILD)/%.o)

MAKEFLAGS	=	--no-print-directory

NAME	=	libasm.so

DIE	=	exit 1

%.asm:
	@echo -e "\033[1;31mFile not found: $@\033[0m" && $(DIE)

$(BUILD)/%.o: %.asm
	@mkdir -p $(@D)
	@$(AS) $(ASFLAGS) $< -o $@ || $(DIE)

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CCFLAGS)
	@echo -e "\033[1;36m[$(NAME)]: Successfully build\033[0m"
	@echo -e "\033[1;36mCompiled $(shell echo "$?" | wc -w) file(s)\033[0m"

clean:
	@rm -f $(OBJ)
	@echo -e "\033[1;33m[$(NAME)]: Object files successfully cleaned\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@echo -e "\033[1;33m[$(NAME)]: Binary file successfully cleaned\033[0m"

re:	fclean all

.PHONY:	all clean fclean re
