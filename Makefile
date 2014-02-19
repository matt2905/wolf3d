# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/09 12:39:45 by mmartin           #+#    #+#              #
#    Updated: 2014/01/15 20:34:15 by mmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	wolf3d

export		LIBFT	=	$(PWD)/libft.a

export		CC		=	gcc

export		CFLAGS	=	-Wall -Wextra -Werror -g

export		INC		=	-I $(PWD)/libft/includes

SRC			=	main.c			\
				ft_key.c		\
				ft_draw.c		\
				ft_move.c		\
				ft_segment.c	\
				ft_minimap.c	\
				ft_read_file.c	\
				ft_background.c

OBJ			=	$(SRC:.c=.o)

LIB			=	-L. -lft -L /usr/X11/lib -lXext -lmlx -lX11

INC			+=	-I includes

all:		$(LIBFT) $(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo ""
	@echo "\033[33m"Compilating of wolf3d : "\033[32m"Success"\033[0m"

%.o:		%.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@echo "\033[31m"Objects of wolf3d : deleted"\033[0m"
	@/bin/rm -f $(OBJ)

fclean:		clean
	@echo "\033[31m"Wolf3D : deleted"\033[0m"
	@/bin/rm -f $(NAME)

fcleanlib:
	@Make fclean -C libft

$(LIBFT):
	@Make -C libft

re:			fcleanlib fclean all

.PHONY:		all clean fclean fcleanlib re
