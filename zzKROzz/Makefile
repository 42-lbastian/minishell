NAME	=	minishell

H_DIR	=	includes/

SRCS	=	minishell.c\
			signals.c\

OBJS = ${SRCS:.c=.o}

LIBFT        = libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -lreadline -g -I $(H_DIR)

FFLAGS = -Wall -Wextra -Werror -lreadline -g -fsanitize=address -I $(H_DIR)

RM = rm -rf

all:	$(NAME)

$(NAME): ${OBJS}
	$(MAKE) -C libft
	$(CC) -o $(NAME) ${OBJS} $(CFLAGS) ${LIBFT}

fsan: ${OBJS}
	$(MAKE) -C libft
	$(CC) -o $(NAME) ${OBJS} $(FFLAGS) ${LIBFT}
	
clean:
	$(MAKE) clean -C libft
	${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		${RM} libft/libft.a

re:		fclean all

.PHONY:	all clean fclean re
