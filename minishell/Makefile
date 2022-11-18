#Name
NAME = minishell

#Colors
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

#Commands
CC = cc
RM = rm -rf
RFLAG = -lreadline
CFLAGS = -Wall -Wextra -Werror -g
FFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

#Libft
LIBFT        = libft/libft.a

#Source Files
SRCS =	main/minishell.c \
		main/signal.c \
		main/create_env.c \
		main/create_env_lst.c \
		main/init_struct.c \
		lexer/char_check_special.c \
		lexer/lexer.c \
		lexer/read_char.c \
		lexer/unwanted.c \
		lexer/utils.c \
		lexer/utils_2.c \
		lexer/lst.c \
		lexer/lst_2.c \
		lexer/lst_print.c \
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
		#builtins/cd.c \
		#builtins/pwd.c \
		#builtins/echo.c \
		#builtins/env.c \
		#builtins/utils_env.c \
		#builtins/export.c \
		#builtins/unset.c \


OBJS = ${SRCS:.c=.o}

all:	$(NAME)

$(NAME): ${OBJS}
	$(MAKE) -C libft
	$(CC) -o $(NAME) ${OBJS} $(CFLAGS) ${LIBFT} $(RFLAG)

fsan: ${OBJS}
	$(MAKE) -C libft
	$(CC) $(RFLAG) -o $(NAME) ${OBJS} $(FFLAGS) ${LIBFT}
	
clean:
	$(MAKE) clean -C libft
	@${RM} ${OBJS}
	@echo $(R) removed $(NAME) obj files $(X)

fclean:	clean
		@${RM} ${NAME}
		@echo $(R) removed $(NAME) executable $(X)
		@$(RM) -rf $(LIBFT)
		@echo $(R) removed libft.a $(X)

re:		fclean all

resan: fclean fsan

.PHONY:	all clean fclean re
