NAME = visualizer_exe
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCL = visualizer.h
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(C_FILES))
OBJ = $(SRC:.c=.o)
LIB = ../libft/libft.a
C_FILES = main.c utils.c parse.c

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(OBJ) ../libft/libft.a -o ../$(NAME)

%.o: %.c $(INCL)
	$(CC) -c $(FLAGS) $< -o $@

$(LIB):
	make -C ../libft

clean:
	make -C ../libft/ clean
	rm -rf $(OBJ)

fclean:
	make -C ../libft/ fclean
	rm -rf $(NAME)

re: fclean all
