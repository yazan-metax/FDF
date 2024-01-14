# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yazan <yazan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 16:48:38 by ailopez-          #+#    #+#              #
#    Updated: 2024/01/15 00:28:49 by yazan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


NAME		:= fdf

SRC_DIR		:= src/
OBJ_DIR		:= build/
CC			:= gcc
CFLAGS		:= -g -O3 -Wall -Werror -Wextra
FSANITIZE	:= 
NOFLAGS		:= -g
RM			:= rm -f

INC		 		:= inc/
LIB				:= lib/
PRINTF_DIR		:= $(LIB)libft/
PRINTF			:= $(PRINTF_DIR)libft.a
MINILIBX_DIR	:= $(LIB)miniliblx/minilibx_macos/
MINILIBX		:= $(MINILIBX_DIR)libmlx.a
MINILIBXCC		:= -lm -lmlx -L $(MINILIBX_DIR)
HEADER 			:= -I$(INC) -I$(PRINTF_DIR) -I$(MINILIBX_DIR)
OPENGL			:= -framework OpenGL -framework AppKit


#Sources

SRC_FILES	=	color keys mouse mouse_key_utils draw_line\
						drawing_utils drawing extra fdf geometry get_next_line_utils\
						get_next_line map_utils menu parse_map polar\
						transform transform_utils fdf_utils

SRC 		=   $(addprefix $(SRC_DIR),(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
##INCS		= 	$(addprefix $(INC), $(addsuffix .h, $(INC_FILES)))
###

OBJF		=	.cache_exists

all:	makelibs
	@$(MAKE) $(NAME)

makelibs:
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"	
	@$(MAKE) -C $(MINILIBX_DIR)
	@echo "$(GREEN)Minilibx compiled!$(DEF_COLOR)"	

-include 	${DEPS}

$(NAME):	$(OBJ)		
			@$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(PRINTF) $(MINILIBXCC) $(MINILIBX) $(OPENGL) -o $(NAME)		
			@echo "👉 $(BLUE)$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(PRINTF) $(MINILIBXCC) $(OPENGL) -o $(NAME)$(DEF_COLOR)"
			@echo "$(MAGENTA)✨ FDF compiled!$(DEF_COLOR)"

bonus:		
			@$(MAKE) all
			
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) | $(OBJF)
	@echo "⚙️ $(CYAN)Compiling: $< $(DEF_COLOR)"
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

##these are unnecessary
$(PRINTF):
	@make -C $(PRINTF_DIR)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"	

$(MINILIBX):
	@make -C $(MINILIBX_DIR)
	@echo "$(GREEN)Minilibx compiled!$(DEF_COLOR)"			
##
clean:
	@make clean -sC $(PRINTF_DIR)
	@echo "$(CYAN)ft_printf object and dependency files cleaned.$(DEF_COLOR)"
	@make clean -C $(MINILIBX_DIR)
	@echo "$(CYAN)Minilibx object files cleaned.$(DEF_COLOR)"	
	$(RM) -rf $(OBJ_DIR)
	@echo "$(CYAN)Fdf object files cleaned!$(DEF_COLOR)"

fclean:		clean
	$(RM) -f $(NAME)
	@echo "$(CYAN)Fdf executable files cleaned!$(DEF_COLOR)"
	$(RM) -f $(MINILIBX_DIR)libmlx.a
	@echo "$(CYAN)libmlx.a lib cleaned!$(DEF_COLOR)"			
	$(RM) -f $(LIBFT_DIR)libft.a
	@echo "$(CYAN)libft.a lib cleaned!$(DEF_COLOR)"


re:			fclean 
	@$(MAKE)	
	@echo "$(GREEN)Cleaned and rebuilt everything for Fdf!$(DEF_COLOR)"

norm:
	@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
