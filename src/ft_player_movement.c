/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:13:31 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/12 15:25:44 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_player_movement(mlx_t *mlx, t_image *img)
{
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (ft_load_player(mlx, 0, 0, 'W') == 1)
			ft_move_player_w(mlx, img);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (ft_load_player(mlx, 0, 0, 'S') == 1)
			ft_move_player_s(mlx, img);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		if (ft_load_player(mlx, 0, 0, 'A') == 1)
			ft_move_player_a(mlx, img);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		if (ft_load_player(mlx, 0, 0, 'D') == 1)
			ft_move_player_d(mlx, img);
	}
}

char	ft_player_location(mlx_image_t *element, char mapelement)
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
		if (ins[amount].x < img->player->instances->x)
			x_m = 30;
		else
			x_m = 30;
		if (ins[amount].y < img->player->instances->y)
			y_m = 30;
		else
			y_m = 30;
		if (fabs((float)(ins[amount].x - img->player->instances->x)) < x_m)
			if (fabs((float)(ins[amount].y - img->player->instances->y)) < y_m)
				return (ft_is_wall(x_m, y_m, ins + amount, mapelement));
		amount++;
	}
	return (1);
}

char	ft_is_wall(int x_m, int y_m, mlx_instance_t *element_ins, char maplmnt)
{
	mlx_instance_t	*player_ins;
	t_image			*img;

	if (maplmnt != '1')
		return (ft_isit_pickable(element_ins, maplmnt));
	img = gset_img(NULL);
	player_ins = img->player->instances;
	if (!(fabs((float)((element_ins->x + 14) - player_ins->x)) < x_m))
		player_ins->x -= 2;
	if (!(fabs((float)(element_ins->x - (player_ins->x + 14))) < x_m))
		player_ins->x += 2;
	if (!(fabs((float)((element_ins->y + 12) - player_ins->y)) < y_m))
		player_ins->y -= 2;
	if (!(fabs((float)(element_ins->y - (player_ins->y + 12))) < y_m))
		player_ins->y += 2;
	return (0);
}

char	ft_isit_pickable(mlx_instance_t *element_ins, char mapelement)
{
	if (mapelement != 'C')
		return (ft_can_we_exit());
	element_ins->enabled = false;
	return (1);
}
