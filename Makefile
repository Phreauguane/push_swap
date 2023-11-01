
NAME		= push_swap

CC			= cc

CFLAGS		= -Wall -Werror -Wextra

LIBFT_DIR	= libft

MAIN		=	src/push_swap.c

SRCS		= 	src/exit_handler.c		\
				src/init_stack.c		\
				src/node_refresh.c		\
				src/operations_a.c		\
				src/operations_b.c		\
				src/operations_both.c	\
				src/stack_utils.c		\
				src/stack_utils2.c		\
				src/stack_utils3.c

ALGORITHMS	=	src/sort_shmol.c src/algorithm.c src/calc_prices.c

RM			= rm -rf

all			: 
	$(MAKE)	-C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -I include $(MAIN) $(SRCS) $(ALGORITHMS) libft/libft.a -o $(NAME)

clean		:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(NAME)

fclean		: clean
	$(MAKE) fclean -C $(LIBFT_DIR)

re			: fclean all

.PHONY		: all clean fclean re