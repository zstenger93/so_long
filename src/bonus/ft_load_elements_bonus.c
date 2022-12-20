/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_elements_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:21:52 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/20 10:31:27 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	ft_load_walking_path(mlx_t *mlx, int x, int y, char keytype)
{
	t_image		*img;
	t_texture	*tex;
	int			itw;

	tex = null_set_tex(NULL);
	img = null_set_img(NULL);
	if (keytype == 'W' || keytype == 'A')
		tex->walking_path = mlx_load_png("png/walking_path.png");
	if (keytype == 'S' || keytype == 'D')
		tex->walking_path = mlx_load_png("png/walking_path2.png");
	else if (keytype == 'Q')
	{
		tex->walking_path = mlx_load_png("png/walking_path2.png");
		mlx_draw_texture(img->walking_path, tex->walking_path, 0, 0);
		itw = mlx_image_to_window(mlx, img->walking_path, x, y);
		mlx_set_instance_depth(img->walking_path->instances + itw, 2);
	}
	mlx_draw_texture(img->walking_path, tex->walking_path, 0, 0);
	mlx_delete_texture(tex->walking_path);
}

void	ft_load_wall(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image		*img;
	int			itw;

	tex = null_set_tex(NULL);
	img = null_set_img(NULL);
	itw = mlx_image_to_window(mlx, img->wall, x, y);
	tex->wall = mlx_load_png("png/wall.png");
	mlx_draw_texture(img->wall, tex->wall, 0, 0);
	mlx_set_instance_depth(img->wall->instances + itw, 2);
	mlx_delete_texture(tex->wall);
}

void	ft_load_pickitup(mlx_t *mlx, int x, int y, char keytype)
{
	t_texture	*tex;
	t_image		*img;
	int			itw;

	tex = null_set_tex(NULL);
	img = null_set_img(NULL);
	if (keytype == 'W' || keytype == 'A')
		tex->pickitup = mlx_load_png("png/coffee.png");
	if (keytype == 'S' || keytype == 'D')
		tex->pickitup = mlx_load_png("png/coffee2.png");
	else if (keytype == 'H')
	{
		tex->pickitup = mlx_load_png("png/coffee.png");
		mlx_draw_texture(img->pickitup, tex->pickitup, 0, 0);
		itw = mlx_image_to_window(mlx, img->pickitup, x, y);
		mlx_set_instance_depth(img->pickitup->instances + itw, 3);
	}
	mlx_draw_texture(img->pickitup, tex->pickitup, 0, 0);
	mlx_delete_texture(tex->pickitup);
}

void	ft_load_exit(mlx_t *mlx, int x, int y, char keytype)
{
	t_texture	*tex;
	t_image		*img;
	int			itw;

	tex = null_set_tex(NULL);
	img = null_set_img(NULL);
	if (keytype == 'W' || keytype == 'A')
		tex->exit = mlx_load_png("png/exitfire.png");
	if (keytype == 'S' || keytype == 'D')
		tex->exit = mlx_load_png("png/exit.png");
	else if (keytype == 'J')
	{
		tex->exit = mlx_load_png("png/exit.png");
		mlx_draw_texture(img->exit, tex->exit, 0, 0);
		itw = mlx_image_to_window(mlx, img->exit, x, y);
		mlx_set_instance_depth(img->exit->instances + itw, 3);
	}
	mlx_draw_texture(img->exit, tex->exit, 0, 0);
	mlx_delete_texture(tex->exit);
}
