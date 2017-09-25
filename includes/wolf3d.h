/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:28:20 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/25 21:54:46 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <time.h>
# include <errno.h>

/*
**SCREEN DIMENSION
*/
# define WINDOW_HEIGHT 640
# define WINDOW_WIDTH 640

/*
**KEY INPUTS
*/
# define K_ESC 53
# define K_UP 126
# define K_DOWN 125
# define K_RIGHT 124
# define K_LEFT 123
# define K_SPA 49

# define RET 0x0000ff

typedef struct s_env		t_env;
typedef struct s_player		t_player;
typedef struct s_screen		t_screen;
typedef struct s_map		t_map;
typedef struct s_coords		t_coords;
typedef struct s_circle		t_circle;
typedef struct s_line		t_line;
typedef struct s_draw		t_draw;
typedef struct s_img		t_img;
typedef struct s_keyboard	t_keyboard;

struct						s_coords
{
	int	x;
	int	y;
};

struct						s_circle
{
	int cirx;
	int ciry;
	int cirdx;
	int cirdy;
	int cirerr;
};

struct						s_draw
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;
	int			modifier;
	t_coords	a;
	t_coords	b;
};

struct						s_line
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
};

struct						s_map
{
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
};

struct						s_screen
{
	double	camera_x;
	double	raypos_x;
	double	raypos_y;
	double	raydir_x;
	double	raydir_y;
	double	plane_x;
	double	plane_y;
};

struct						s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	movspeed;
	double	rotspeed;
};

struct						s_keyboard
{
	int	k_up;
	int	k_down;
	int	k_left;
	int	k_right;
};

struct						s_img
{
	void	*img;
	int		width;
	int		height;
	char	*buffer;
};

struct						s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_datas;
	int			bpp;
	int			sl;
	int			end;
	int			x;
	int			**world_map;
	int			map_w;
	int			map_h;
	clock_t		time;
	clock_t		old_time;
	int			fps;
	t_circle	reticle;
	t_player	player;
	t_screen	screen;
	t_map		map;
	t_draw		draw;
	t_img		text[1];
	t_img		chaingun[7];
	t_keyboard	keyb;
};

void						ft_exit(t_env *env);
void						error(void);
void						ft_put_pixel(t_env *env, int x, int y, int color);
void						ft_line(t_env *env, t_coords a,
								t_coords b, int color);
int							**open_arg(t_env *env, char **argv);
void						init_env(t_env *env, char **argv);
void						check_x(t_env *env, int ***map, int x, int y);
void						ft_init_player(t_env *env);
void						ft_init_screen(t_env *env);
void						ft_init_map(t_env *env);
int							keypress_hook(int keycode, t_env *env);
int							keyrelease_hook(int keycode, t_env *env);
void						compute_fps(t_env *env);
void						ft_determine_draw(t_env *env);
void						ft_ray_dir(t_env *env);
void						ft_ray_collision(t_env *env);
int							color_choice(t_env *env);
void						ft_movements(t_env *env);
void						load_chaingun(t_env *env);
void						animate_chaingun(t_env *env);
int							loop_hook(t_env *env);
void						draw_floor(t_env *env);
void						animate_chaingun(t_env *env);
void						load_textures(t_env *env);
void						draw_circle(int x0, int y0, int radius, t_env *env);

#endif
