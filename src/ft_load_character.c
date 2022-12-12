/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:10:04 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/12 15:25:47 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	ft_load_player(mlx_t *mlx, int x, int y, char keytype)
{
	t_texture	*tex;
	t_image		*img;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	if (keytype == 'W')
		tex->player = mlx_load_png("png/player_u.png");
	else if (keytype == 'S')
		tex->player = mlx_load_png("png/player_d.png");
	else if (keytype == 'A')
		tex->player = mlx_load_png("png/player_l.png");
	else if (keytype == 'D')
		tex->player = mlx_load_png("png/player_r.png");
	else if (keytype == 'X')
	{
		tex->player = mlx_load_png("png/player_d.png");
		mlx_draw_texture(img->player, tex->player, 0, 0);
		mlx_image_to_window(mlx, img->player, x, y);
		mlx_set_instance_depth(img->player->instances, 8);
	}
	mlx_draw_texture(img->player, tex->player, 0, 0);
	mlx_delete_texture(tex->player);
	ft_player_location(img->pickitup, 'C');
	ft_player_location(img->exit, 'E');
	return (ft_player_location(img->wall, '1'));
}

void	ft_move_player_w(mlx_t *mlx, t_image *img)
{
	img->player->instances[0].y -= 4;
	ft_load_exit(mlx, 0, 0, 'W');
	ft_load_pickitup(mlx, 0, 0, 'W');
}

void	ft_move_player_s(mlx_t *mlx, t_image *img)
{
	img->player->instances[0].y += 4;
	ft_load_exit(mlx, 0, 0, 'S');
	ft_load_pickitup(mlx, 0, 0, 'S');
}

void	ft_move_player_a(mlx_t *mlx, t_image *img)
{
	img->player->instances[0].x -= 4;
	ft_load_exit(mlx, 0, 0, 'A');
	ft_load_pickitup(mlx, 0, 0, 'A');
}

void	ft_move_player_d(mlx_t *mlx, t_image *img)
{
	img->player->instances[0].x += 4;
	ft_load_exit(mlx, 0, 0, 'D');
	ft_load_pickitup(mlx, 0, 0, 'D');
}
