NAME = push_swap

FLAG = -Wall -Werror -Wextra

LIB = ./libft/libft.a

LIBOBJ = ../libft/%.o

SRC = ps_input_check_and_process.c \
 		ps_main_sort.c \
 		 ps_main_sort2.c \
 		 ps_main_sort3.c \
 		 ps_main_sort4.c \
 		 ps_main_sort5.c \
 		 ps_mid_and_init.c \
 		 ps_operations.c \
 		 ps_operations2.c \
 		 ps_operations3.c \
 		 push_swap.c \
 		 ps_defragment_output.c \
 		 ps_defragment_output2.c \
 		 error_handler.c

OBJ = $(SRC:%.c=%.o)

B_SRC = checker_bonus.c \
		ps_input_check_and_process.c \
		ps_mid_and_init.c \
		ps_operations.c \
		ps_operations2.c \
		ps_operations3.c \
		error_handler.c

B_OBJ = $(B_SRC:%.c=%.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ) $(LIBOBJ) push_swap.h
	gcc $(FLAG) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
	gcc $(FLAG) -c $< -o $@

$(LIBOBJ): ./libft/libft.h
	make -C ./libft/

bonus: $(B_OBJ) $(LIBOBJ) push_swap.h
	gcc $(FLAG) $(B_OBJ) $(LIB) -o checker

clean:
	make clean -C ./libft/
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(LIB)

re: fclean all