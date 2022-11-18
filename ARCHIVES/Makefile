NAME = minishell

SRCS =	lexer/char_check.c \
		lexer/char_check_special.c \
		lexer/lexer.c \
		lexer/init.c \
		lexer/read_char.c \
		lexer/unwanted.c \
		lexer/utils.c \
		lexer/list.c \
		lexer/free.c \
		builtins/cd.c \
		builtins/pwd.c \
		builtins/echo.c \
		builtins/env.c \
		builtins/utils_env.c \
		builtins/export.c \


OBJS = ${SRCS:.c=.o}

LIBFT        = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lreadline -g

FFLAGS = -Wall -Wextra -Werror -lreadline -g -fsanitize=address

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
