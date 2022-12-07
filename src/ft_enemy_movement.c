/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:21:51 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/07 19:55:39 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_enemy(mlx_t *mlx, t_image *img)
{
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (ft_load_enemy(mlx, 0, 0, 'W') == 1
			&& ft_load_enemy2(mlx, 0, 0, 'W') == 1)
			ft_move_enemy_w(img);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (ft_load_enemy(mlx, 0, 0, 'S') == 1
			&& ft_load_enemy2(mlx, 0, 0, 'S') == 1)
			ft_move_enemy_s(img);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		if (ft_load_enemy(mlx, 0, 0, 'A') == 1
			&& ft_load_enemy2(mlx, 0, 0, 'A') == 1)
			ft_move_enemy_a(img);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		if (ft_load_enemy(mlx, 0, 0, 'D') == 1
			&& ft_load_enemy2(mlx, 0, 0, 'D') == 1)
			ft_move_enemy_d(img);
	}
}

void	ft_move_enemy_w(t_image *img)
{
	img->enemy->instances->y += 3;
	img->enemy2->instances->y -= 3;
}

void	ft_move_enemy_s(t_image *img)
{
	img->enemy->instances->y -= 3;
	img->enemy2->instances->y += 3;
}

void	ft_move_enemy_a(t_image *img)
{
	img->enemy->instances->x += 3;
	img->enemy2->instances->x -= 3;
}

void	ft_move_enemy_d(t_image *img)
{
	img->enemy->instances->x -= 3;
	img->enemy2->instances->x += 3;
}
