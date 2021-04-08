# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/23 09:04:27 by ayzapata          #+#    #+#              #
#    Updated: 2021/02/02 12:07:08 by ayzapata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
INCLUDE := -I./include/cub3d.h -I./lib/libft/libft.h -I./lib/libft/get_next_line.h
DIR = srcs/
SRCS := \
		cub3d.c \
		game.c \
		ft_errors.c \
		ft_init_structures1.c \
		ft_init_structures2.c \
		ft_valid_format_file.c \
		ft_valid_empty_line.c \
		ft_read_scene.c \
		ft_treat_file.c \
		ft_get_file_lines.c \
		ft_get_file_lines_utils.c \
		ft_get_settings.c \
		ft_get_map_dimesion.c \
		ft_resolution.c \
		ft_colors_utils1.c \
		ft_colors_utils2.c \
		ft_colors.c \
		ft_texture.c \
		ft_texture_utils.c \
		ft_frees.c \
		ft_frees_utils1.c \
		ft_frees_utils2.c \
		ft_init_pos_moves.c \
		ft_create_rgb_color.c \
		ft_find_closed_map.c \
		ft_find_closed_map_utils1.c \
		ft_find_closed_map_utils2.c \
		ft_find_closed_map_utils3.c \
		ft_find_closed_map_utils4.c \
		ft_check_diagonals.c \
		ft_save_image_bmp.c \
		handle_keys.c \
		load_textures.c \
		draw_ver_line.c \
		drawsprites.c \
		drawsprites_utils1.c \
		drawsprites_utils2.c \
		move.c \
		raycasting.c \
		sort_sprites.c \
		ft_create_map_int.c \
		ft_find_player_direction.c \
		checks.c

CC = clang
SRCS_DIR = $(addprefix $(DIR), $(SRCS))
OBJS = $(SRCS_DIR:.c=.o)
MLX = minilibx-linux-master
CFLAGS = -Wall -Wextra -Werror
LMLX = -L./lib/$(MLX) -lmlx -lXext -lX11 -lm -lbsd 

all:		$(NAME)

$(NAME):	 $(OBJS)
			@make -C ./lib/libft/
			@make -C ./lib/$(MLX)/
			@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME) -L./lib/libft -lft $(LMLX)

objs/%.o: %.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@


clean :
			@rm -rf $(OBJS)
			@make clean -C ./lib/libft/
			@make clean -C ./lib/$(MLX)/
			@rm -rf save.bmp

fclean : clean
			@rm -rf $(NAME)
			@make fclean -C ./lib/libft/
			

re : fclean all

.PHONY: re, clean, fclean, all
