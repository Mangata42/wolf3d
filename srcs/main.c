/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:27:45 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/19 11:28:17 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int worldMap[MAP_WIDTH][MAP_HEIGHT]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void    ft_movements(t_env *env)
{
    if (env->keyb.k_up == 1)
    {
        if (!(worldMap[(int)(env->player.posX + env->player.dirX * env->player.movSpeed)][(int)(env->player.posY)]))
            env->player.posX += env->player.dirX * env->player.movSpeed;
        if (!(worldMap[(int)(env->player.posX)][(int)(env->player.posY + env->player.dirY * env->player.movSpeed)]))
            env->player.posY += env->player.dirY * env->player.movSpeed;
    }
     if (env->keyb.k_down == 1)
    {
        if (!(worldMap[(int)(env->player.posX - env->player.dirX * env->player.movSpeed)][(int)(env->player.posY)]))
            env->player.posX -= env->player.dirX * env->player.movSpeed;
        if (!(worldMap[(int)(env->player.posX)][(int)(env->player.posY - env->player.dirY * env->player.movSpeed)]))
            env->player.posY -= env->player.dirY * env->player.movSpeed;
    }
    if (env->keyb.k_right == 1)
    {
        double oldDirX = env->player.dirX;
        env->player.dirX = env->player.dirX * cos(-(env->player.rotSpeed)) - env->player.dirY * sin(-(env->player.rotSpeed));
        env->player.dirY = oldDirX * sin(-(env->player.rotSpeed)) + env->player.dirY * cos(-(env->player.rotSpeed));
        double oldPlaneX = env->screen.planeX;
        env->screen.planeX = env->screen.planeX * cos(-(env->player.rotSpeed)) - env->screen.planeY * sin(-(env->player.rotSpeed));
        env->screen.planeY = oldPlaneX * sin(-(env->player.rotSpeed)) + env->screen.planeY * cos(-(env->player.rotSpeed));
    }
     if (env->keyb.k_left == 1)
    {
        double oldDirX = env->player.dirX;
        env->player.dirX = env->player.dirX * cos((env->player.rotSpeed)) - env->player.dirY * sin((env->player.rotSpeed));
        env->player.dirY = oldDirX * sin((env->player.rotSpeed)) + env->player.dirY * cos(-(env->player.rotSpeed));
        double oldPlaneX = env->screen.planeX;
        env->screen.planeX = env->screen.planeX * cos((env->player.rotSpeed)) - env->screen.planeY * sin((env->player.rotSpeed));
        env->screen.planeY = oldPlaneX * sin((env->player.rotSpeed)) + env->screen.planeY * cos((env->player.rotSpeed));
    }
}

void    ft_init_player(t_env *env)
{
    env->player.posX = 22;
    env->player.posY= 12;
    env->player.dirX = -1;
    env->player.dirY = 0;
    env->screen.planeX = 0;
    env->screen.planeY = 0.66;
}

void    ft_init_screen(t_env *env)
{
    env->screen.cameraX = 2 * env->x / (double)WINDOW_WIDTH - 1;
    env->screen.rayPosX = env->player.posX;
    env->screen.rayPosY = env->player.posY;
    env->screen.rayDirX = env->player.dirX + env->screen.planeX * env->screen.cameraX;
    env->screen.rayDirY = env->player.dirY + env->screen.planeY * env->screen.cameraX;
}

void    ft_init_map(t_env *env)
{
    env->map.mapX = (int)env->screen.rayPosX;
    env->map.mapY = (int)env->screen.rayPosY; 
    env->map.deltaDistX = sqrt(1 + (env->screen.rayDirY * env->screen.rayDirY) / (env->screen.rayDirX * env->screen.rayDirX));
    env->map.deltaDistY = sqrt(1 + (env->screen.rayDirX * env->screen.rayDirX) / (env->screen.rayDirY * env->screen.rayDirY));
    env->map.hit = 0;
}

void    ft_ray_dir(t_env *env)
{
    if (env->screen.rayDirX < 0)
    {
        env->map.stepX = -1;
        env->map.sideDistX = (env->screen.rayPosX - env->map.mapX) * env->map.deltaDistX;
    }
    else
    {
        env->map.stepX = 1;
        env->map.sideDistX = (env->map.mapX + 1.0 - env->screen.rayPosX) * env->map.deltaDistX;
    }
    if (env->screen.rayDirY < 0)
    {
        env->map.stepY = -1;
        env->map.sideDistY = (env->screen.rayPosY - env->map.mapY) * env->map.deltaDistY;
    }
    else
    {
        env->map.stepY = 1;
        env->map.sideDistY = (env->map.mapY + 1.0 - env->screen.rayPosY) * env->map.deltaDistY;
    }
}

void    ft_ray_collision(t_env *env)
{
    while (env->map.hit == 0)
    {
        if (env->map.sideDistX < env->map.sideDistY)
        {
             env->map.sideDistX += env->map.deltaDistX;
             env->map.mapX += env->map.stepX;
             env->map.side = 0;
        }
        else
        {
           env->map.sideDistY += env->map.deltaDistY;
           env->map.mapY += env->map.stepY;
           env->map.side = 1;
        }
        if (worldMap[env->map.mapX][env->map.mapY] > 0)
            env->map.hit = 1;
    }   
}

void    ft_determine_draw(t_env *env)
{
    if (env->map.side == 0)
        env->map.perpWallDist = (env->map.mapX - env->screen.rayPosX + (1 - env->map.stepX) / 2) / env->screen.rayDirX;
    else
        env->map.perpWallDist = (env->map.mapY - env->screen.rayPosY + (1 - env->map.stepY) / 2) / env->screen.rayDirY; 
    env->draw.lineHeight = WINDOW_HEIGHT / env->map.perpWallDist;
    env->draw.drawStart = -(env->draw.lineHeight) / 2 + WINDOW_HEIGHT / 2;
    if(env->draw.drawStart < 0)
        env->draw.drawStart = 0;
    env->draw.drawEnd = env->draw.lineHeight / 2 + WINDOW_HEIGHT / 2;
    if(env->draw.drawEnd >= WINDOW_HEIGHT)
        env->draw.drawEnd = WINDOW_HEIGHT - 1;
    env->draw.a.x = env->x;
    env->draw.a.y = env->draw.drawStart;
    env->draw.b.x = env->x;
    env->draw.b.y = env->draw.drawEnd;
}

int     loop_hook(t_env *env)
{
    ft_movements(env);
    env->time = clock();
    env->x = 0;
    mlx_destroy_image(env->mlx, env->img);
    env->img = mlx_xpm_file_to_image(env->mlx, "./textures/space.xpm", &(env->text[0].width), &(env->text[0].height));
    env->img_datas = mlx_get_data_addr(env->img, &(env->bpp), &(env->sl), &(env->end));
    while (env->x < WINDOW_WIDTH)
    {
        ft_init_screen(env);
        ft_init_map(env);
        ft_ray_dir(env);
        ft_ray_collision(env);
        ft_determine_draw(env);
        if (worldMap[env->map.mapX][env->map.mapY] == 0)
            env->draw.color = 0xF7FE2E;
        if (worldMap[env->map.mapX][env->map.mapY] == 1)
            env->draw.color = 0xff0000;
        if (worldMap[env->map.mapX][env->map.mapY] == 2)
            env->draw.color = 0x00ff00;
        if (worldMap[env->map.mapX][env->map.mapY] == 3)
            env->draw.color = 0x0000ff;
        if (worldMap[env->map.mapX][env->map.mapY] == 4)
            env->draw.color = 0xffffff;
        ft_line(env, env->draw.a, env->draw.b, env->draw.color);
        for (int y = env->draw.drawEnd; y < WINDOW_HEIGHT; y++)
            ft_put_pixel(env, env->x, y, 0x42f498);
        env->x++;
    }
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    env->oldTime = env->time;
    env->time = clock();
    env->fps = 60 / ((double)(env->time - env->oldTime) / CLOCKS_PER_SEC);
    env->player.movSpeed = 20 * ((double)(env->time - env->oldTime) / CLOCKS_PER_SEC);
    env->player.rotSpeed = 10 * ((double)(env->time - env->oldTime) / CLOCKS_PER_SEC);
    printf("fps : %d\n", env->fps);
    return (0);
}

void    ft_exit(void)
{
    system("killall afplay");
    exit(EXIT_SUCCESS);
}

int     test(int keycode, t_env *env)
{
    if (keycode == 18)
    {
        system("afplay ./music/nuke.mp3");
        ft_exit();
    }
    if (keycode == K_ESC)
        ft_exit();
    if (keycode == K_SPA)
        system("afplay ./music/9mm.wav&");
    if (keycode == K_UP)
        env->keyb.k_up = 1;
    if (keycode == K_DOWN)
        env->keyb.k_down = 1;
    if (keycode == K_RIGHT)
        env->keyb.k_right = 1;
    if (keycode == K_LEFT)
        env->keyb.k_left = 1;
    return (0);
}

int     test2(int keycode, t_env *env)
{
    if (keycode == K_UP)
        env->keyb.k_up = 0;
    if (keycode == K_DOWN)
        env->keyb.k_down = 0;
    if (keycode == K_RIGHT)
        env->keyb.k_right = 0;
    if (keycode == K_LEFT)
        env->keyb.k_left = 0;
    return (0);
}

int     main(void)
{
    t_env   env;

    env.mlx = mlx_init();
    env.win = mlx_new_window(env.mlx, WINDOW_HEIGHT, WINDOW_WIDTH, "le correcteur est gay");
    env.img = mlx_xpm_file_to_image(env.mlx, "./textures/space.xpm", &(env.text[0].width), &(env.text[0].height));
    env.img_datas = mlx_get_data_addr(env.img, &(env.bpp), &(env.sl), &(env.end));
    env.time = 0;
    env.oldTime = 0;
    system("afplay ./music/ingame.mp3&");
    ft_init_player(&env);
    mlx_hook(env.win, KeyPress, KeyPressMask, test, &env);
    mlx_hook(env.win, KeyRelease, KeyReleaseMask, test2, &env);
    mlx_loop_hook(env.mlx, loop_hook, &env);
    mlx_loop(env.mlx);
    return (EXIT_SUCCESS);
}