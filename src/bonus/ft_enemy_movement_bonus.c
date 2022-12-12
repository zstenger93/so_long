/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_movement_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:21:51 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/12 10:51:09 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	ft_move_enemy(mlx_t *mlx, t_image *img)
{
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (ft_load_enemy(mlx, 0, 0, 'W') == 1
			&& ft_l_e2(mlx, 0, 0, 'W') == 1 && ft_l_e3(mlx, 0, 0, 'W') == 1)
			ft_move_enemy_w(mlx, img);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (ft_load_enemy(mlx, 0, 0, 'S') == 1
			&& ft_l_e2(mlx, 0, 0, 'S') == 1 && ft_l_e3(mlx, 0, 0, 'S') == 1)
			ft_move_enemy_s(mlx, img);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		if (ft_load_enemy(mlx, 0, 0, 'A') == 1
			&& ft_l_e2(mlx, 0, 0, 'A') == 1 && ft_l_e3(mlx, 0, 0, 'A') == 1)
			ft_move_enemy_a(mlx, img);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		if (ft_load_enemy(mlx, 0, 0, 'D') == 1
			&& ft_l_e2(mlx, 0, 0, 'D') == 1 && ft_l_e3(mlx, 0, 0, 'D') == 1)
			ft_move_enemy_d(mlx, img);
	}
}

void	ft_move_enemy_w(mlx_t *mlx, t_image *img)
{
	img->enemy->instances->y += 4;
	img->enemy2->instances->y -= 3;
	img->enemy3->instances->y += 5;
	ft_load_exit(mlx, 0, 0, 'W');
	ft_load_pickitup(mlx, 0, 0, 'W');
}

void	ft_move_enemy_s(mlx_t *mlx, t_image *img)
{
	img->enemy->instances->y -= 4;
	img->enemy2->instances->y += 3;
	img->enemy3->instances->y -= 5;
	ft_load_exit(mlx, 0, 0, 'S');
	ft_load_pickitup(mlx, 0, 0, 'S');
}

void	ft_move_enemy_a(mlx_t *mlx, t_image *img)
{
	img->enemy->instances->x += 4;
	img->enemy2->instances->x -= 3;
	img->enemy3->instances->x += 5;
	ft_load_exit(mlx, 0, 0, 'A');
	ft_load_pickitup(mlx, 0, 0, 'A');
}

void	ft_move_enemy_d(mlx_t *mlx, t_image *img)
{
	img->enemy->instances->x -= 4;
	img->enemy2->instances->x += 3;
	img->enemy3->instances->x -= 5;
	ft_load_exit(mlx, 0, 0, 'D');
	ft_load_pickitup(mlx, 0, 0, 'D');
}
