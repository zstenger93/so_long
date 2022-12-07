/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_location.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:18:35 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/07 19:52:59 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	ft_enemy_location(mlx_image_t *element)
{
	t_image			*img;
	mlx_instance_t	*ins;
	int				x_m;
	int				y_m;
	int				amount;

	img = gset_img(NULL);
	ins = element->instances;
	amount = 0;
	while (amount < element->count)
	{
		if (ins[amount].x < img->enemy->instances->x)
			x_m = 30;
		else
			x_m = 30;
		if (ins[amount].y < img->enemy->instances->y)
			y_m = 30;
		else
			y_m = 30;
		if (fabs((float)(ins[amount].x - img->enemy->instances->x)) < x_m)
			if (fabs((float)(ins[amount].y - img->enemy->instances->y)) < y_m)
				ft_wall_enemy(x_m, y_m, ins + amount);
		amount++;
	}		
	return (1);
}

void	ft_wall_enemy(int x_m, int y_m, mlx_instance_t *element_ins)
{
	mlx_instance_t	*enemy_ins;
	t_image			*img;

	img = gset_img(NULL);
	enemy_ins = img->enemy->instances;
	if (!(fabs((float)((element_ins->x + 6) - enemy_ins->x)) < x_m))
		enemy_ins->x -= 5;
	if (!(fabs((float)(element_ins->x - (enemy_ins->x + 6))) < x_m))
		enemy_ins->x += 5;
	if (!(fabs((float)((element_ins->y + 6) - enemy_ins->y)) < y_m))
		enemy_ins->y -= 5;
	if (!(fabs((float)(element_ins->y - (enemy_ins->y + 6))) < y_m))
		enemy_ins->y += 5;
}

char	ft_enemy2_location(mlx_image_t *element)
{
	t_image			*img;
	mlx_instance_t	*ins;
	int				x_m;
	int				y_m;
	int				amount;

	img = gset_img(NULL);
	ins = element->instances;
	amount = 0;
	while (amount < element->count)
	{
		if (ins[amount].x < img->enemy2->instances->x)
			x_m = 30;
		else
			x_m = 30;
		if (ins[amount].y < img->enemy2->instances->y)
			y_m = 30;
		else
			y_m = 30;
		if (fabs((float)(ins[amount].x - img->enemy2->instances->x)) < x_m)
			if (fabs((float)(ins[amount].y - img->enemy2->instances->y)) < y_m)
				ft_wall_enemy2(x_m, y_m, ins + amount);
		amount++;
	}		
	return (1);
}

void	ft_wall_enemy2(int x_m, int y_m, mlx_instance_t *element_ins)
{
	mlx_instance_t	*enemy_ins;
	t_image			*img;

	img = gset_img(NULL);
	enemy_ins = img->enemy2->instances;
	if (!(fabs((float)((element_ins->x + 6) - enemy_ins->x)) < x_m))
		enemy_ins->x -= 5;
	if (!(fabs((float)(element_ins->x - (enemy_ins->x + 6))) < x_m))
		enemy_ins->x += 5;
	if (!(fabs((float)((element_ins->y + 6) - enemy_ins->y)) < y_m))
		enemy_ins->y -= 5;
	if (!(fabs((float)(element_ins->y - (enemy_ins->y + 6))) < y_m))
		enemy_ins->y += 5;
}
