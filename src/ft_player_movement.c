/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:13:31 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/21 17:21:24 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_player_movement(mlx_t *mlx, t_image *img)
{
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (ft_load_player(mlx, 0, 0, 'W') == 1)
			img->player->instances[0].y -= 4;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (ft_load_player(mlx, 0, 0, 'S') == 1)
			img->player->instances[0].y += 4;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		if (ft_load_player(mlx, 0, 0, 'A') == 1)
			img->player->instances[0].x -= 4;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		if (ft_load_player(mlx, 0, 0, 'D') == 1)
			img->player->instances[0].x += 4;
	}
}

/*
if the player isn't close to the wall the margin is 32 pixel,
if it is close then the margin is 30 pixel.
if example wall[i]_x - player_x is smaller than the margin (x_m)
if it will be true for y as well and then checks the wall else
checks the enxt coordinate.
if-else -> left-right, up-down
*/
char	ft_player_location(mlx_image_t *element, char mapelement)
{
	t_image			*img;
	mlx_instance_t	*ins;
	int				x_m;
	int				y_m;
	int				amount;

	img = null_set_img(NULL);
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
		if (fabs((float)(ins[amount].x - img->player->instances->x)) < x_m
			&& fabs((float)(ins[amount].y - img->player->instances->y)) < y_m)
			return (ft_is_wall(x_m, y_m, ins + amount, mapelement));
		amount++;
	}
	return (1);
}

/*
FABS CONVERT ABSOLUTE VALUE->ALWAYS POSITIVE LIKE UNICUM
if the statement is true we are "in the wall" because I set the margin to
30/32px in the previous function, then we will bounce back 3px from the wall
1 right 2 left 3 bottom 4 upper wall
wall[i].x/y 
all element is 32x32px and a floating number so it can be eg from
wall[0].0 to wall[0].32 then wall[1].0 to wall[1].32 both, on x and y
coordinates as well. 
*/
char	ft_is_wall(int x_m, int y_m, mlx_instance_t *element_ins, char maplmnt)
{
	mlx_instance_t	*player_ins;
	t_image			*img;

	if (maplmnt != '1')
		return (ft_isit_pickable(element_ins, maplmnt));
	img = null_set_img(NULL);
	player_ins = img->player->instances;
	if ((fabs((float)((element_ins->x + 6) - player_ins->x)) > x_m))
		player_ins->x -= 4;
	if ((fabs((float)(element_ins->x - (player_ins->x + 6))) > x_m))
		player_ins->x += 4;
	if ((fabs((float)((element_ins->y + 6) - player_ins->y)) > y_m))
		player_ins->y -= 4;
	if ((fabs((float)(element_ins->y - (player_ins->y + 6))) > y_m))
		player_ins->y += 4;
	return (0);
}

char	ft_isit_pickable(mlx_instance_t *element_ins, char mapelement)
{
	if (mapelement != 'C')
		return (ft_can_we_exit());
	element_ins->enabled = false;
	return (1);
}
