/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:28:20 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/21 18:19:46 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "mlx.h"
# include "X11/X.h"
# include <math.h>
# include <time.h>

/* SCREEN DIMENSION */
# define WINDOW_HEIGHT 640
# define WINDOW_WIDTH 640

/*  KEY INPUTS  */
# define K_ESC 53
# define K_UP 126
# define K_DOWN 125
# define K_RIGHT 124
# define K_LEFT 123
# define K_SPA 49


typedef struct  s_env       t_env;
typedef struct  s_player    t_player;
typedef struct  s_screen    t_screen;
typedef struct  s_map       t_map;
typedef struct  s_coords    t_coords;
typedef struct  s_line      t_line;
typedef struct  s_draw      t_draw;
typedef struct  s_img       t_img;
typedef struct  s_keyboard  t_keyboard;

struct          s_coords
{
    int     x;
    int     y;
};

struct          s_draw
{
    int     lineHeight;
    int     drawStart;
    int     drawEnd;
    int     color;
    int     modifier;
    t_coords a;
    t_coords b;
};


struct          s_line
{
    int     dx;
    int     sx;
    int     dy;
    int     sy;
    int     err;
    int     e2;
};

struct          s_map
{
    int     mapX;
    int     mapY;
    double  sideDistX;
    double  sideDistY;
    double  deltaDistX;
    double  deltaDistY;
    double  perpWallDist;
    int     stepX;
    int     stepY;
    int     side;
    int     hit;
};

struct          s_screen
{
    double  cameraX;
    double  rayPosX;
    double  rayPosY;
    double  rayDirX;
    double  rayDirY;
    double  planeX;
    double  planeY;
};

struct          s_player
{
    double  posX;
    double  posY;
    double  dirX;
    double  dirY;
    double  movSpeed;
    double  rotSpeed;
};

struct          s_keyboard
{
    int         k_up;
    int         k_down;
    int         k_left;
    int         k_right;
};

struct          s_img
{
    void        *img;
    int         width;
    int         height;
    char        *buffer;
};

struct          s_env
{
    void        *mlx;
    void        *win;
    void        *img;
    char        *img_datas;
    int         bpp;
    int         sl;
    int         end;
    int         x;
    int         **world_map;
    int         map_w;
    int         map_h;
    clock_t     time;
    clock_t     oldTime;
    int         fps;
    t_player    player;
    t_screen    screen;
    t_map       map;
    t_draw      draw;
    t_img       text[2];
    t_keyboard  keyb;
};

void       ft_exit();
void       error();
void       ft_put_pixel(t_env *env, int x, int y, int color);
void       ft_line(t_env *env, t_coords a, t_coords b, int color);
int        **open_arg(char **argv);
void       init_env(t_env *env, char **argv);
void       ft_init_player(t_env *env);
void       ft_init_screen(t_env *env);
void       ft_init_map(t_env *env);
int        keypress_hook(int keycode, t_env *env);
int        keyrelease_hook(int keycode, t_env *env);
void       compute_fps(t_env *env);
void       ft_determine_draw(t_env *env);
void       ft_ray_dir(t_env *env);
void       ft_ray_collision(t_env *env);
int 		color_choice(t_env *env);
void       ft_movements(t_env *env);


#endif