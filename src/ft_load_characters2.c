/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_characters2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:30:55 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/09 14:53:07 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	ft_l_e3(mlx_t *mlx, int x, int y, char keytype)
{
	t_texture	*tex;
	t_image		*img;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	if (keytype == 'W')
		tex->enemy3 = mlx_load_png("png/norminette_brown_d.png");
	if (keytype == 'S')
		tex->enemy3 = mlx_load_png("png/norminette_brown_u.png");
	if (keytype == 'A')
		tex->enemy3 = mlx_load_png("png/norminette_brown_r.png");
	if (keytype == 'D')
		tex->enemy3 = mlx_load_png("png/norminette_brown_l.png");
	else if (keytype == 'Z')
	{
		tex->enemy3 = mlx_load_png("png/norminette_brown_r.png");
		mlx_draw_texture(img->enemy3, tex->enemy3, 0, 0);
		mlx_image_to_window(mlx, img->enemy3, x, y);
		mlx_set_instance_depth(img->enemy3->instances, 4);
	}
	mlx_draw_texture(img->enemy3, tex->enemy3, 0, 0);
	mlx_delete_texture(tex->enemy3);
	ft_enemy3_location(img->wall);
	ft_player_location(img->enemy3, 'B');
	return (1);
}

char	ft_enemy3_location(mlx_image_t *element)
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
		if (ins[amount].x < img->enemy3->instances->x)
			x_m = 30;
		else
			x_m = 30;
		if (ins[amount].y < img->enemy3->instances->y)
			y_m = 30;
		else
			y_m = 30;
		if (fabs((float)(ins[amount].x - img->enemy3->instances->x)) < x_m)
			if (fabs((float)(ins[amount].y - img->enemy3->instances->y)) < y_m)
				ft_wall_enemy3(x_m, y_m, ins + amount);
		amount++;
	}		
	return (1);
}

void	ft_wall_enemy3(int x_m, int y_m, mlx_instance_t *element_ins)
{
	mlx_instance_t	*enemy_ins;
	t_image			*img;

	img = gset_img(NULL);
	enemy_ins = img->enemy3->instances;
	if (!(fabs((float)((element_ins->x + 6) - enemy_ins->x)) < x_m))
		enemy_ins->x -= 5;
	if (!(fabs((float)(element_ins->x - (enemy_ins->x + 6))) < x_m))
		enemy_ins->x += 5;
	if (!(fabs((float)((element_ins->y + 6) - enemy_ins->y)) < y_m))
		enemy_ins->y -= 5;
	if (!(fabs((float)(element_ins->y - (enemy_ins->y + 6))) < y_m))
		enemy_ins->y += 5;
}
