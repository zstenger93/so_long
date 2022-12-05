/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:18:07 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/05 19:53:46 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
check for position
check for wall
check for collectible
check for exit
*/

#include "../includes/so_long.h"

void	ft_enemy_hook(void *mlx)
{
	t_image *img;

	img = gset_img(NULL);
	if (img->enemy->enabled == true)
		ft_enemy_movement(mlx, img);
		
}

void	ft_enemy_movement(mlx_t *mlx, t_image *img)
{
	int	i;
	
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (ft_load_player(mlx, 0, 0, 'W') == 2)
			{
				i = 0;
				while (i < img->enemy->count)
				{
					img->enemy->instances[i].x -= 3;
					img->enemy->instances[i].y += 2;
					i++;
				}
			}
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (ft_load_player(mlx, 0, 0, 'S') == 2)
			{
				i = 0;
				while (i < img->enemy->count)
				{
					img->enemy->instances[i].x += 3;
					img->enemy->instances[i].y -= 2;
					i++;
				}
			}
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		if (ft_load_player(mlx, 0, 0, 'A') == 2)
			{
				i = 0;
				while (i < img->enemy->count)
				{
					img->enemy->instances[i].y -= 3;
					img->enemy->instances[i].x += 2;
					i++;
				}
			}
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		if (ft_load_player(mlx, 0, 0, 'D') == 2)
			{
				i = 0;
				while (i < img->enemy->count)
				{
					img->enemy->instances[i].y += 3;
					img->enemy->instances[i].x -= 2;
					i++;
				}
			}
	}
}





// 	ft_load_enemy(mlx_t *mlx, int x, int y, char keytype)
// {
// 	t_texture	*tex;
// 	t_image	*img;

// 	tex = gset_tex(NULL);
// 	img = gset_img(NULL);
// 	if (keytype == 'W' || keytype == 'S' || keytype == 'A' || keytype == 'D')
// 		tex->enemy = mlx_load_png("png/norminette.png");
// 	else if (keytype == 'T')
// 	{
// 		tex->enemy = mlx_load_png("png/norminette.png");
// 		mlx_draw_texture(img->enemy, tex->enemy, 0, 0);
// 		mlx_image_to_window(mlx, img->enemy, x, y);
// 		mlx_set_instance_depth(img->enemy->instances,  3);
// 	}
// 	mlx_draw_texture(img->enemy, tex->enemy, 0, 0);
// 	mlx_delete_texture(tex->enemy);
// 	// ft_enemy_location(img->wall, 'F');
// 	return (0);
// }