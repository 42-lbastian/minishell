NAME = minishell

SRCS =	char_check.c \
		lexer.c \
		read_char.c \
		unwanted.c \
		utils.c \
		cd.c \
		pwd.c \
		echo.c \

OBJS = ${SRCS:.c=.o}

LIBFT        = ../libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3 -lreadline

RM = rm -rf

all:	$(NAME)

$(NAME): ${OBJS}
	$(CC) -o $(NAME) ${OBJS} $(CFLAGS) ${LIBFT}
	
clean:
	${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
