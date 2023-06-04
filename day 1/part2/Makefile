# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 19:29:31 by jonascim          #+#    #+#              #
#    Updated: 2023/06/04 16:17:45 by jonascim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= lvl2
LIBFT		:= libft
INCLUDE		:= includes
CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -g -fsanitize=address
MLXFLAGS	:= -framework OpenGL -framework AppKit
RM			:= rm -f

SRC_DIR		:= srcs/

SRC_FILES		:=	main.c

SRC 		:= 	$(addprefix $(SRC_DIR), $(SRC_FILES))


all:		$(NAME)

$(NAME):	$(SRC)
			@make -C $(LIBFT)
			@$(CC) $(CFLAGS) $(SRC) -o$(NAME) -I$(INCLUDE) -I$(LIBFT) -L$(LIBFT) -lft -lmlx $(MLXFLAGS)

clean:
			@make clean -C $(LIBFT)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re norm
