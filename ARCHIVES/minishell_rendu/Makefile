NAME = minishell

SRCS =	lexer/minishell.c \
		lexer/create_env.c \
		lexer/char_check.c \
		lexer/char_check_special.c \
		lexer/lexer.c \
		lexer/init.c \
		lexer/read_char.c \
		lexer/unwanted.c \
		lexer/utils.c \
		lexer/lst.c \
		lexer/free.c \
		lexer/remove_spaces.c \
		lexer/remove_quotes.c \
		lexer/expand_env_var.c \
		lexer/count.c \
		lexer/set_type_cmd.c \
		parse/parse.c \
		parse/exec.c \
		parse/lst.c \
		parse/tools.c \

OBJS = ${SRCS:.c=.o}

LIBFT        = libft/libft.a

CC = cc

RFLAG = -lreadline

CFLAGS = -Wall -Wextra -Werror -g

FFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

RM = rm -rf

all:	$(NAME)

$(NAME): ${OBJS}
	$(MAKE) -C libft
	$(CC) -o $(NAME) ${OBJS} $(CFLAGS) ${LIBFT} $(RFLAG)

fsan: ${OBJS}
	$(MAKE) -C libft
	$(CC) $(RFLAG) -o $(NAME) ${OBJS} $(FFLAGS) ${LIBFT}
	
clean:
	$(MAKE) clean -C libft
	${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		${RM} libft/libft.a

re:		fclean all

resan: fclean fsan

.PHONY:	all clean fclean re
