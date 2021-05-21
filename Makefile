NAME =

FLAG = -Wall -Werror -Wextra

LIB = ./libft/libft.a

INC = ./inc

LIBOBJ = ../libft/%.o

SRC =

OBJ = $(SRC:%.c=%.o)


.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ) $(LIBOBJ)
	ar -rcs $(NAME) $(OBJ) $(LIBOBJ)

%.o: %.c
	gcc $(FLAG) -c $< -o $@

$(LIBOBJ): ./libft/libft.h
	make -C ./libft/

clean:
	make clean -C ./libft/
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(LIB)

re: fclean all