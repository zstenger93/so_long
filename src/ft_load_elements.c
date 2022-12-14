/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:21:52 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/22 18:12:55 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
load the png's on the texture then draw the texture on the
image(what we created in the create_iamges funciton)
set the dept of the image, put it to the window and
delete the texture.
*/
void	ft_load_walking_path(mlx_t *mlx, int x, int y)
{
	t_image		*img;
	t_texture	*tex;
	int			itw;

	tex = null_set_tex(NULL);
	img = null_set_img(NULL);
	itw = mlx_image_to_window(mlx, img->walking_path, x, y);
	tex->walking_path = mlx_load_png("png/walking_path2.png");
	mlx_draw_texture(img->walking_path, tex->walking_path, 0, 0);
	mlx_set_instance_depth(img->walking_path->instances + itw, 2);
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

void	ft_load_pickitup(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image		*img;
	int			itw;

	tex = null_set_tex(NULL);
	img = null_set_img(NULL);
	itw = mlx_image_to_window(mlx, img->pickitup, x, y);
	tex->pickitup = mlx_load_png("png/coffee.png");
	mlx_draw_texture(img->pickitup, tex->pickitup, 0, 0);
	mlx_set_instance_depth(img->pickitup->instances + itw, 3);
	mlx_delete_texture(tex->pickitup);
}

void	ft_load_exit(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image		*img;
	int			itw;

	tex = null_set_tex(NULL);
	img = null_set_img(NULL);
	itw = mlx_image_to_window(mlx, img->exit, x, y);
	tex->exit = mlx_load_png("png/exit.png");
	mlx_draw_texture(img->exit, tex->exit, 0, 0);
	mlx_set_instance_depth(img->exit->instances + itw, 3);
	mlx_delete_texture(tex->exit);
}
