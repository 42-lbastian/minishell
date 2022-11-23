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
MAKE		=	make --no-print-directory
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
				env_handler.c\

SRC_LEXER	=	char_check_special.c\
				lexer.c\
				read_char.c\
				unwanted.c\
				utils.c\
				utils_2.c\
				lst.c\
				lst_2.c\
				free.c\
				remove_spaces.c\
				remove_quotes.c\
				expand_env_var.c\
				count.c\
				set_type_cmd.c\

SRC_PARSER	=	parse.c\
				exec.c\
				lst_parse.c\
				tools.c\

SRC_BUILT	=	#cd.c\
				#pwd.c\
				#echo.c\
				#env.c\
				#export.c\
				#unset.c\
				#utils_env.c\

SRC_DEBUG	=	debug_00.c\

#Objects

OBJ_MAIN	=	$(addprefix $(O_DIR)/, $(SRC_MAIN:.c=.o))
OBJ_LEXER	=	$(addprefix $(O_DIR)/, $(SRC_LEXER:.c=.o))
OBJ_PARSER	=	$(addprefix $(O_DIR)/, $(SRC_PARSER:.c=.o))
OBJ_BUILT	=	$(addprefix $(O_DIR)/, $(SRC_BUILT:.c=.o))
OBJ_DEBUG	=	$(addprefix $(O_DIR)/, $(SRC_DEBUG:.c=.o))
OBJ_ALL		=	$(OBJ_MAIN) $(OBJ_LEXER) $(OBJ_PARSER) $(OBJ_BUILT) $(OBJ_DEBUG)

$(O_DIR)/%.o:	./*/%.c
				@echo $(Y)Compiling [$@]...$(X)
				@$(MKD) $(O_DIR)
				@$(CC) $(CFLAGS) $(RFLAGS) -o $@ -c $<
				@printf $(UP) $(CUT)

$(NAME):	$(OBJ_ALL)
			@$(MAKE) -C $(LFT_DIR)
			@echo $(Y)Compiling [$(NAME)]...$(X)
			@$(CC) -o $(NAME) $(CFLAGS) $(OBJ_ALL) $(LIBFT) $(RFLAG)
			@printf $(UP)$(CUT)
			@echo $(G)Compiled [$(NAME)]$(X)

all:	$(NAME)

fsan: $(OBJ_ALL)
	@$(MAKE) -C $(LFT_DIR)
	@echo $(Y)Compiling [$(NAME)] with fsanitize=address flag...$(X)
	@$(CC) -o $(NAME) $(FFLAGS) $(OBJ_ALL) $(LIBFT) $(RFLAG)
	@printf $(UP)$(CUT)
	@echo $(G)Compiled [$(NAME)] with fsanitize=address flag...$(X)
	
clean:
	@$(MAKE) clean -C libft
	@$(RM) $(O_DIR)
	@echo $(R) removed $(NAME) obj files $(X)

fclean:	clean
		@$(RM) $(NAME)
		@echo $(R) removed $(NAME) executable $(X)
		@$(RM) -rf $(LIBFT)
		@echo $(R) removed libft.a $(X)

re:		fclean all

resan: fclean fsan

.PHONY:	fsan all clean fclean re
