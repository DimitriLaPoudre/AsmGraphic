##
## EPITECH PROJECT, 2023
## MinilibC
## File description:
## Makefile
##

NAME = basic_game

SRC = src/main.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -z execstack -Wall -Wextra -Wno-unused-parameter -I./include -I../../include -L../../lib -lAsmGraphic -lAsmLibrary

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../../lib/AsmGraphic
	make -C ../../lib/AsmLibrary
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

.PHONY: run

run:
	@$(MAKE) -s re
	@./$(NAME)
	@$(MAKE) -s fclean

run_debug: fclean $(OBJ)
	@make -s -C ../../lib/AsmGraphic
	@make -s -C ../../lib/AsmLibrary
	@gcc $(OBJ) -o $(NAME) $(CFLAGS) -g3
	@valgrind ./$(NAME)
	@$(MAKE) -s fclean

clean:
	make -C ../../lib/AsmGraphic clean
	make -C ../../lib/AsmLibrary clean
	rm -rf $(OBJ)

fclean: clean
	make -C ../../lib/AsmGraphic fclean
	make -C ../../lib/AsmLibrary fclean
	rm -rf $(NAME)

re: fclean all
