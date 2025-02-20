/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <tbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:39:26 by tamsi             #+#    #+#             */
/*   Updated: 2024/03/30 12:47:06 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768

# define NUM_TEXTURES 4

# define NO_CHAR "NO "
# define SO_CHAR "SO "
# define WE_CHAR "WE "
# define EA_CHAR "EA "
# define F_CHAR "F "
# define C_CHAR "C "

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}		t_line;

typedef struct s_vector2f
{
	float	x;
	float	y;
}			t_vector2f;

typedef struct s_vector2i
{
	int	x;
	int	y;
}		t_vector2i;

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_raycast
{
	t_point		ray_dir;
	t_point		side_dist;
	t_point		delta_dist;
	t_point		map;
	t_vector2i	step;
	t_vector2i	map_pos;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		perp_wall_dist;
	double		camera_x;
}				t_raycast;

typedef struct s_player
{
	t_point		pos;
	t_point		dir;
	t_vector2f	plane;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct s_map
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*f_rgb;
	char		*c_rgb;
	char		**full;
}				t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_data;

typedef struct s_game
{
	int			map_fd;
	int			window_is_open;
	int			keys[65536];
	void		*mlx;
	void		*mlx_win;
	t_player	player;
	t_raycast	raycast;
	t_map		map;
	t_data		img;
	t_data		textures[NUM_TEXTURES];
}				t_game;

void		free_tab(char **tab);
void		free_map(t_map map);
void		init_game(int map_fd, t_game *game);
void		init_ray(t_raycast *raycast);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_line(t_data *img, t_point start, t_point end, int color);
void		raycasting(t_game *game);
void		game_loop(t_game *game);
void		cleanup(t_game *game);
void		move_forward(t_game *game);
void		move_backward(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		rotate_left(t_game *game);
void		rotate_right(t_game *game);
void		append_line_to_map_temp(char **map_temp, char *line);
void		read_map_lines(int map_fd, char **map_temp);
void		draw_texture_column(t_game *game, t_data *texture, int x);
void		color_sky(t_game *game, int x);
void		color_floor(t_game *game, int x);
int			is_map_closed(char **map);
int			check_setup_char(char *line);
int			check_player_char_map(char **map);
int			check_map(t_map map);
int			check_color_lines(char *str);
int			open_map_file(char *map_path);
int			create_trgb(int t, int r, int g, int b);
double		calculate_wall_x(t_game *game);
t_player	init_player(t_map map);
t_map		init_map(int map_fd);
t_data		*get_texture(t_game *game);

#endif
