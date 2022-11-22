#Name
NAME		=	minishell

#Colors
Y			=	"\033[33m"
R			=	"\033[31m"
G			=	"\033[32m"
B			=	"\033[34m"
X			=	"\033[0m"
UP			=	"\033[A"
CUT			=	"\033[K"

#Commands
CC			=	cc
RM			=	rm -rf
MAKE		=	make
MKD			=	mkdir -p
RFLAG		=	-lreadline
CFLAGS		=	-Wall -Wextra -Werror -g
FFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address

#Libft
LFT_DIR		=	libft
LIBFT		=	libft/libft.a

#Directories
H_DIR		=	include
O_DIR		=	obj

#Source Files

SRC_MAIN	=	minishell.c\
				signal.c\
				create_env.c\
				create_env_lst.c\

SRC_LEXER	=	char_check_special.c\
				lexer.c\
				read_char.c\
				unwanted.c\
				utils.c\
				utils_2.c\
				lst.c\
				lst_2.c\
				lst_print.c\
				free.c\
				remove_spaces.c\
				remove_quotes.c\
				expand_env_var.c\
				expand_env_var_2.c\
				count.c\
				set_type_cmd.c\

SRC_PARSER	=	parse.c\
				create_lst_parser.c \
				create_lst_parser_utils.c \
				exec.c\
				lst_parse.c\
				lst_parse_print.c\
				tools.c\

SRC_BUILT	=	#cd.c\
				#pwd.c\
				#echo.c\
				#env.c\
				#utils_env.c\
				#export.c\
				#unset.c\

#Objects

OBJ_MAIN	=	$(addprefix $(O_DIR)/, $(SRC_MAIN:.c=.o))
OBJ_LEXER	=	$(addprefix $(O_DIR)/, $(SRC_LEXER:.c=.o))
OBJ_PARSER	=	$(addprefix $(O_DIR)/, $(SRC_PARSER:.c=.o))
OBJ_BUILT	=	$(addprefix $(O_DIR)/, $(SRC_BUILT:.c=.o))


$(O_DIR)/%.o:	./*/%.c
				@echo $(Y)Compiling [$@]...$(X)
				@$(MKD) $(O_DIR)
				@$(CC) $(CFLAGS) $(RFLAGS) -o $@ -c $<
				@printf $(UP) $(CUT)

$(NAME):	$(OBJ_MAIN) $(OBJ_LEXER) $(OBJ_PARSER) $(OBJ_BUILT)
			@$(MAKE) -C $(LFT_DIR)
			@echo $(Y)Compiling [$(NAME)]...$(X)
			@$(CC) -o $(NAME) $(CFLAGS) $(OBJ_MAIN) $(OBJ_LEXER) $(OBJ_PARSER) $(OBJ_BUILT) $(LIBFT) $(RFLAG)
			@printf $(UP)$(CUT)
			@echo $(G)Compiled : [$(NAME)]$(X)

all:	$(NAME)

fsan: $(OBJ_MAIN) $(OBJ_LEXER) $(OBJ_PARSER) $(OBJ_BUILT)
	$(MAKE) -C $(LFT_DIR)
	$(CC) -o $(NAME) $(FFLAGS) $(OBJ_MAIN) $(OBJ_LEXER) $(OBJ_PARSER) $(OBJ_BUILT) $(LIBFT) $(RFLAG)
	
clean:
	@$(MAKE) clean -C libft
	@$(RM) $(OBJS)
	@echo $(R) removed $(NAME) obj files $(X)

fclean:	clean
		@$(RM) $(NAME)
		@echo $(R) removed $(NAME) executable $(X)
		@$(RM) -rf $(LIBFT)
		@echo $(R) removed libft.a $(X)

re:		fclean all

resan: fclean fsan

.PHONY:	fsan all clean fclean re
