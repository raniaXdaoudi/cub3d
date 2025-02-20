# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbesson <tbesson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 23:50:02 by tamsi             #+#    #+#              #
#    Updated: 2024/03/30 13:13:30 by tbesson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	= sources
SRCS_NAME	=	main.c					\
				check_map.c				\
				check_player_char_map.c	\
				check_unclosed_map.c	\
				check_color_setup.c		\
				colors.c				\
				open_map_file.c			\
				draw.c					\
				raycast.c				\
				movements.c				\
				rotations.c				\
				game_loop.c				\
				init_ray.c				\
				init_game.c				\
				init_player.c			\
				init_map_utils.c		\
				init_map.c				\
				exit_game.c				\
				free_map.c
OBJS_DIR	= .objs
OBJS_NAME	= ${SRCS_NAME:.c=.o}
SRCS		= $(addprefix $(SRCS_DIR)/,$(SRCS_NAME))
OBJS		= $(addprefix $(OBJS_DIR)/,$(OBJS_NAME))
MLX			= mlx/Makefile.gen
LFT			= libft.a
INC			= -I ./includes -I ./libs/libft -I ./libs/mlx
LIB			= -L ./libs/libft -lft -L ./libs/mlx -lmlx -lXext -lX11 -lm -lbsd

NAME	= cub3D

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror $(INC)

all:		$(MLX) $(LFT) $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(MLX):
			@make -s -C libs/mlx

$(LFT):
			@make -s -C libs/libft

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
			@mkdir $(OBJS_DIR) 2> /dev/null || true
			$(CC) $(CFLAGS) -o $@ -c $<

clean:
			@make -s $@ -C libs/libft
			@rm -rf $(OBJS) $(OBJS_DIR)

fclean:		clean
			@make -s $@ -C libs/libft
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
