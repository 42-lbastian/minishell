# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stelie <stelie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 20:20:34 by stelie            #+#    #+#              #
#    Updated: 2022/11/24 11:18:58 by stelie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME 		= 	libft.a

#Colors
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

#Commands
CC			= 	gcc
DMK			=	mkdir -p
RM			=	rm -rf
AR			=	ar rc

#Compilation flags
INCLUDES	=	-I$(H_DIR)
CFLAGS		=	-Wall -Werror -Wextra
SAN_FLAGS	=	-g3 -fsanitize=address
RFLAGS		=	-lreadline

#Directories
H_DIR		=	includes
S_DIR		=	src
O_DIR		=	obj

#Source files
SRC_ISS		=	00_00.c\
				00_01.c\
				00_02.c\

SRC_LEN		=	01_00.c\

SRC_NBR		=	02_00.c\
				02_01.c\
				
SRC_BAS		=	03_00.c\
				03_01.c\
				
SRC_PUT		=	04_00.c\
				
SRC_STR		=	05_00.c\
				05_01.c\
				05_02.c\
				05_03.c\
				05_04.c\
				05_05.c\
				05_06.c\
				
SRC_MEM		=	06_00.c\
				06_01.c\
				
SRC_LST		=	07_00.c\
				07_01.c\
				
SRC_PTF		=	08_00.c\
				08_01.c\
				08_02.c\
				08_03.c\
				08_04.c\
				08_05.c\
				08_06.c\
				
SRC_GNL		=	09_00.c\

#Objects
OBJ_ISS		=	$(addprefix $(O_DIR)/, $(SRC_ISS:.c=.o))
OBJ_LEN		=	$(addprefix $(O_DIR)/, $(SRC_LEN:.c=.o))
OBJ_NBR		=	$(addprefix $(O_DIR)/, $(SRC_NBR:.c=.o))
OBJ_BAS		=	$(addprefix $(O_DIR)/, $(SRC_BAS:.c=.o))
OBJ_PUT		=	$(addprefix $(O_DIR)/, $(SRC_PUT:.c=.o))
OBJ_STR		=	$(addprefix $(O_DIR)/, $(SRC_STR:.c=.o))
OBJ_MEM		=	$(addprefix $(O_DIR)/, $(SRC_MEM:.c=.o))
#OBJ_LST		=	$(addprefix $(O_DIR)/, $(SRC_LST:.c=.o))
OBJ_PTF		=	$(addprefix $(O_DIR)/, $(SRC_PTF:.c=.o))
OBJ_GNL		=	$(addprefix $(O_DIR)/, $(SRC_GNL:.c=.o))

$(O_DIR)/%.o:	./$(S_DIR)/*/%.c
				@echo $(Y)Compiling [$@]...$(X)
				@mkdir -p $(O_DIR)
				@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
				@printf $(UP) $(CUT)

$(NAME):	$(OBJ_ISS) $(OBJ_LEN) $(OBJ_NBR) $(OBJ_BAS) $(OBJ_PUT) $(OBJ_STR) $(OBJ_MEM) $(OBJ_LST) $(OBJ_PTF) $(OBJ_GNL)
			@echo $(Y)Compiling [$(NAME)]...$(X)
			@$(AR) $(NAME) $(OBJ_ISS) $(OBJ_LEN) $(OBJ_NBR) $(OBJ_BAS) $(OBJ_PUT) $(OBJ_STR) $(OBJ_MEM) $(OBJ_LST) $(OBJ_PTF) $(OBJ_GNL)
			@printf $(UP)$(CUT)
			@echo $(G)Finished [$(NAME)]$(X)
			

all:	$(NAME)
		
clean:
		@$(RM) $(O_DIR)
		@echo $(R) removed obj files $(X)

fclean:	clean
		@$(RM) $(NAME)
		@echo $(R) removed libft.a $(X)

re:	fclean all

.PHONY: all clean fclean re
