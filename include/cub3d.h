/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:46:22 by ealbayra          #+#    #+#             */
/*   Updated: 2024/03/12 18:58:42 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 720

# include <stdbool.h>

typedef struct s_key
{
	bool	ak;
	bool	dk;
	bool	wk;
	bool	sk;
	bool	rk;
	bool	lk;
}				t_key;

typedef struct s_data
{
	void	*img;
	int		*addr;
}				t_data;

typedef struct s_player
{
	char	way;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	rot_speed;
	double	speed;
}				t_player;

typedef struct s_ray
{
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	double	camera_x;
	double	ray_dirx;
	double	ray_diry;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	wall_dist;
}				t_ray;

typedef struct s_draw
{
	int				draw_s;
	int				draw_e;
	int				line_h;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
	unsigned int	color;
	int				tex_w;
	int				tex_h;
}				t_draw;

typedef struct s_texture
{
	t_data			*no;
	t_data			*so;
	t_data			*we;
	t_data			*ea;
	unsigned int	floorc;
	unsigned int	ceilingc;
}				t_texture;

typedef struct s_map
{
	int		*floor_val;
	int		*ceil_val;
	char	*floor;
	char	*ceil;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		map_data;
	t_ray		*ray;
	t_data		*image;
	t_player	*player;
	t_texture	*tex;
	t_draw		*draw;
	t_key		key;
	char		**map;
}				t_game;

int		map_name_check(char *file);
int		pair_map(t_game *game, char **regex);
int		check_pairs(t_game *game);
int		check_map_surrounded(t_game *game);
void	check_map_valid(t_game *game);
void	init_map(t_game *game, char *file);
void	init_all(t_game *game);
void	init_mlx(t_game *game);
void	init_raycasting(t_game *game);
void	init_key(t_game *game);
void	init_draw(t_game *game);
void	init_map_data(t_game *game);
int		check_and_get(t_game *game, char **regex);
int		exit_game(t_game *game);
void	init_player(t_game *game);
char	*ft_straddchar(char *s1, char *s2);
void	ft_exit(char *str);
void	free_all(t_game *game);
void	free_double(char **str);
void	convert_xpm(t_game *game);
void	player_check(t_game *game, char way);
void	cf_valid(t_game *game, char **floor, char **ceil);
int		key_press(int keycode, t_game *game);
int		key_relase(int keycode, t_game *game);
void	movements(t_game *game);
int		ray_casting(t_game *game);
void	calculate_ray(t_game *game, int x);
void	calculate_steps(t_game *game);
void	free_all_ext(t_game *game);
void	free_valid(char **floor, char **ceil, t_game *game);
void	free_number(char **s1, char **s2, t_game *game);
void	check_number(char **s1, char **s2, t_game *game);
void	check_number2(char **s1, char **s2, t_game *game);
void	parse_map_utils(t_game *game, int j, int i, char **regex);

#endif
