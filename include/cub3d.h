/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:48:16 by ayzapata          #+#    #+#             */
/*   Updated: 2021/02/02 10:54:39 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../lib/minilibx-linux-master/mlx.h"

# define A_KEY 97
# define D_KEY 100
# define W_KEY 119
# define S_KEY 115
# define RIGHT_KEY 65363
# define LEFT_KEY 65361
# define ESC_KEY 65307
# define N_PARAMETRES 8
# define ROTSPEED 0.03
# define SPEED 0.075

/*
**	Settings flags
**	r	:	resolution
**	no	:	north texture
**	so	:	south texture
**	we	:	west texture
**	ea	:	east texture
**	s	:	sprite texture
**	f	:	floor color
**	c	:	ceiling color
**	sm	:	It is a flag indicating that the map has started
**	el	:	It is a flag indicating that after the map has started
*/

typedef	struct			s_set
{
	int					r;
	int					no;
	int					so;
	int					ea;
	int					we;
	int					s;
	int					f;
	int					c;
	int					sm;
	int					el;
}						t_set;

typedef	struct			s_file
{
	char				*cont;
	int					line_nbr;
	int					line_size;
	int					nodes_nbr;
	struct s_file		*next;
}						t_file;

typedef	struct			s_vector2
{
	int					x;
	int					y;
}						t_vector2;

typedef	struct			s_vector2d
{
	double				x;
	double				y;
}						t_vector2d;

/*
**	x	:	x-coordinate
**	y	:	x-coordinate
**	tx	:	strite value, it means = 2
*/

typedef struct			s_sprite
{
	float				x;
	float				y;
	int					tx;
	struct s_sprite		*next;
}						t_sprite;

typedef struct			s_onecoord
{
	int					x;
	int					y;
	int					index;
	struct s_onecoord	*next;
}						t_onecoord;

typedef struct			s_spritab
{
	float				x;
	float				y;
}						t_spritab;

/*
**	no	:	north texture file
**	so	:	south texture file
**	we	:	west texture file
**	ea	:	east texture file
**	s	:	sprite texture file
*/

typedef struct			s_textfiles
{
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*s;
}						t_textfiles;

typedef struct			s_color
{
	int					red;
	int					green;
	int					blue;
}						t_color;

/*
**	screen		:	screen resolution
**	tf			:	textures files
**	map_int		:	It is an array, where it is stocked the map with the
**					values in ints. Here, the lines map has the same length.
**	map_sln		:	It is an array, where it is stocked the map with the
**					solution that surrounds the player
**	onescoord	:	It is a linked chain where it is stocked the one's
**					coordinates of the solution of map
**	dir			:	It is the direction of the player: N, S, E, W
**	sprnbr		:	number of sprite in the map
**	sprite		:	It is a linked chain where it is stocked the sprite
**					coordinates
**	mapdim		: 	map dimension: x, y
**	pos			:	pos initial
**	pldir		:	dir initial
**					it should be valided the empty lines. In the middle of
**					the map there should be no lines with any character,
**					only empty lines
**	plane		:	the 2d raycaster version of camera plane
**	save		:	flag it should create an image
*/

typedef struct			s_scndescrip
{
	t_set				settings;
	t_file				*file;
	t_vector2			screen;
	t_textfiles			tf;
	t_color				floor;
	t_color				ceiling;
	int					**map_int;
	int					**map_sln;
	t_onecoord			*onescoord;
	int					rf;
	int					cf;
	int					one_north;
	int					one_south;
	int					one_east;
	int					one_west;
	int					go_up;
	int					go_down;
	int					go_right;
	int					go_left;
	char				dir;
	int					sprnbr;
	t_sprite			*sprite;
	t_vector2			mapdim;
	t_vector2d			pos;
	t_vector2d			pldir;
	t_vector2d			plane;
	int					save;
}						t_scndescrip;

typedef struct			s_img
{
	void				*img_ptr;
	int					*pixels;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

typedef struct			s_moves
{
	int					forward;
	int					stepback;
	int					turnright;
	int					turnleft;
	int					right;
	int					left;
}						t_moves;

typedef struct			s_text
{
	void				*tex;
	t_vector2			size;
	int					*pixels;
	int					bpp;
	int					sizeline;
	int					endian;
}						t_text;

/*
**	camerax		:	x-coordinate in camera space
**	sizedist	:	length of ray from current position to next x or y-side
**	deltadist	:	length of ray from one x or y-side to next x or y-side
**	step		:	what direction to step in x or y-direction (either +1 or -1)
**	perpwalldist:	length of the ray
**	side		:	it was a NS or a EW wall hit?
**	lineheight	:	height of line to draw on screen
**	wallx		:	where exactly the wall was hit
**	sprtab		:	sprite coordinates in an array
**	textx		:	x coordinate on the texture
**	texty		:	y coordinate on the texture
*/

typedef struct			s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_img				image;
	double				camerax;
	t_vector2			mapbox;
	t_vector2d			raypos;
	t_vector2d			raydir;
	t_moves				moves;
	t_vector2d			sizedist;
	t_vector2d			deltadist;
	t_vector2			step;
	double				perpwalldist;
	char				walldir;
	int					side;
	int					lineheight;
	int					drawstart;
	int					drawend;
	t_text				north;
	t_text				south;
	t_text				east;
	t_text				west;
	t_text				sprite;
	t_text				texture;
	int					textx;
	int					texty;
	double				wallx;
	double				zbuffer[5000];
	t_spritab			*sprtab;
	int					*spr_order;
	double				*spr_dist;
}						t_data;

typedef struct			s_sprvar
{
	t_vector2d			sprite;
	double				invdet;
	t_vector2d			transform;
	int					sprscreenx;
	t_vector2			size;
	int					drawstarty;
	int					drawendy;
	int					drawstartx;
	int					drawendx;
	int					tex_x;
	int					tex_y;
	int					x;
	int					y;
	int					d;
}						t_sprvar;

typedef	struct			s_param
{
	t_data				*data;
	t_scndescrip		*scene;
	t_sprvar			*sprites;
}						t_param;

int						ft_check_diagonals(t_param *p);
int						ft_find_closed_map(t_param *p);
int						ft_save_image_bmp(t_param *p);
int						ft_create_rgb_color(int r, int g, int b);
int						drawsprites(t_param *p, int i);
void					raycasting(t_param *p);
int						move(t_param *p);
int						ft_treat_file(char **av, t_param *p);
int						ft_valid_empty_line(t_param *p, char *line);
int						ft_read_scene(int fd, t_param *p, int ret);
int						ft_valid_format_file(char *str, char *format);
int						ft_errors(int err, t_param *p);
int						ft_get_map_dimesion(t_param *p, t_file *tmp,
																int param_nbr);
int						ft_get_settings(t_param *p, int r);
int						ft_find_player_direction(t_param *p);
/*
**						draw_ver_line.c
*/
void					ft_define_line(t_data *data, t_scndescrip *scene);
void					select_texture_ns(t_data *data);
void					select_texture_ew(t_data *data);
void					image_pixel(t_param *p, int x, int y, int n);
void					draw_ver_line(int x, int y, t_param *p);
/*
**						ft_texture_utils.c
*/
int						ft_texture(char *line, char	**texture, int i, int *set);
/*
**						ft_texture.c
*/
void					ft_get_texture_no(t_param *p);
void					ft_get_texture_so(t_param *p);
void					ft_get_texture_ea(t_param *p);
void					ft_get_texture_we(t_param *p);
void					ft_get_texture_s(t_param *p);
/*
**						ft_resolution.c
*/
int						ft_resolution(char *line, t_param *p, int i, int t);
void					ft_get_resolution_r(t_param *p);
/*
**						ft_create_map_int.c
*/
int						match_line_length(t_param *p, int i,
												char *new_cont, t_file	*tmp);
t_sprite				*add_sprite_coord(t_param *p, int spr_tx, int i, int j);
int						converte_to_int(char c, t_param *p, int i, int j);
int						ft_create_map_int(t_param *p,
													int i, int j, t_file *tmp);
/*
**						ft_colors.c
*/
int						ft_colors(char *line, t_color *color, int i, int *set);
void					ft_get_color_f(t_param *p);
void					ft_get_color_c(t_param *p);
/*
**						checks.c
*/
int						checked_data(t_scndescrip *scene);
int						checked_settings(t_set *settings);
int						checked_settings_to_one(t_set *settings);
/*
**						ft_get_file_lines.c
*/
int						ft_get_file_lines(t_param *p, char *line);
int						check_settings(t_param *p, char *line, int i);
int						beginning_of_the_map(t_param *p, char *line, int i);
int						get_parameter(t_param *p, char *line, int i, int *set);
int						check_map_line(t_param *p, char *line, int i);
/*
**						ft_get_file_lines_utils.c
*/
t_file					*ft_add_elem_file(t_param *p, char *content,
														int len, int len_line);
int						check_empty_line(t_param *p, char *line);
int						check_add_elem_file(t_param *p, char *line, int i);
int						ft_lst_file_size(t_file *lst);
/*
**						ft_init_structures1.c
*/
void					ft_init_textfiles_struct(t_textfiles *texture);
void					ft_init_color_struct(t_color *color);
void					ft_ini_struc_scene(t_scndescrip *scene);
void					ft_init_settings(t_set *settings);
/*
**						ft_init_structures2.c
*/
void					ft_ini_struc_data(t_data *data);
void					ft_ini_struc_sprite(t_sprvar *sprites);
/*
**						ft_colors_utils1.c
*/
int						advance(char *line);
int						ft_isspace(char *line, int i);
int						check_comma(char *line);
int						ft_isnum(char *line);
int						check(char *line);
/*
**						ft_colors_utils2.c
*/
int						valid_content_color(t_color *color);
int						check_color(t_color *color);
int						green_color(char *line, int i, t_color **color, int ck);
int						blue_color(char *line, int i, t_color **color, int ck);
int						color_init_checks(char *line, int i, t_color *color);
/*
**						ft_init_pos_moves.c
*/
void					set_pos_dir_initial(t_scndescrip *scene,
														int i, int j, char c);
void					set_plane_initial(t_scndescrip *scene, char c);
void					ini_move_keys(t_data *data);
/*
**						ft_find_closed_map_util.c
*/
void					go_up_flag(t_scndescrip *scene);
void					go_down_flag(t_scndescrip *scene);
void					go_right_flag(t_scndescrip *scene);
void					go_left_flag(t_scndescrip *scene);
int						can_go(t_scndescrip *scene, int r, int c);
/*
**						ft_find_closed_map_utils3.c
*/
int						ft_going_rigth(t_param *p, int r, int c);
int						ft_going_down(t_param *p, int r, int c);
int						ft_going_left(t_param *p, int r, int c);
int						ft_going_up(t_param *p, int r, int c);
/*
**						ft_find_closed_map_utils2.c
*/
int						ft_search_down(t_param *p, int r, int c);
int						ft_search_up(t_param *p, int r, int c);
int						ft_search_right(t_param *p, int r, int c);
int						ft_search_left(t_param *p, int r, int c);
/*
**						ft_find_closed_map_utils1.c
*/
t_onecoord				*add_one_coord(t_param *p, int n, int i, int j);
int						count_ones(t_param *p);
int						ft_int_tab_to_zeros(t_param *p);
int						check_around_player(t_scndescrip *scene, int i, int j);
int						closed_map(t_param *p, int r, int c);
/*
**						drawsprites_utils1.c
*/
void					sprite_lines(t_data *data, t_scndescrip *scene,
													t_sprvar *sprites, int h);

/*
**						drawsprites_utils2.c
*/
void					create_order_tab(t_param *p);
void					sprite_h(t_scndescrip *scene, t_sprvar *sprites);
void					sprite_w(t_scndescrip *scene, t_sprvar *sprites);
/*
**						sort_sprites.c
*/
void					sort_sprites(t_data *data, t_scndescrip *scene);
int						sprites_to_tab(t_param *p);
/*
**						handle_keys.c
*/
int						handle_key(int key, t_param *p);
int						key_release(int key, t_param *p);
int						closeredx(t_param *p);
/*
**						load_textures.c
*/
void					loading_textures(t_param *p);
void					get_texture_pixels(t_param *p);
/*
**						ft_frees_utils1.c
*/
void					ft_clear_textures(t_textfiles *to_free);
int						ft_clear_map_int(int **to_free, double y);
void					ft_clear_sprtab(t_spritab **to_free);
void					ft_lstclear_sprite(t_sprite **to_free);
void					ft_clear_part_of_list(t_param *p);
/*
**						ft_frees_utils2.c
*/
void					ft_clear_int_tab(int **to_free);
void					ft_clear_double_tab(double **to_free);
void					ft_lstclear_one_coord(t_onecoord **to_free);
void					ft_free_tex(void *mlx_ptr, t_text *texture);
void					ft_destroy_win(void **mlx_ptr, void **win_ptr);
/*
**						ft_frees.c
*/
void					ft_lstclear_file(t_file **to_free);
void					ft_free_t_param(t_param *p);
void					ft_frees1(t_param *p);
void					ft_frees2(t_param *p);
/*
**						game.c
*/
int						ft_startgame(t_param *p);
int						create_image(t_param *p);
int						create_window(t_param *p);
int						ft_execute_game(t_param *p, char **av, int r);
int						check_arg(t_param *p, int ac, char **av);

#endif
