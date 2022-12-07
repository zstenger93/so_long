/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_characters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:10:04 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/07 20:15:27 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	ft_load_enemy(mlx_t *mlx, int x, int y, char keytype)
{
	t_texture	*tex;
	t_image		*img;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	if (keytype == 'W' || keytype == 'S')
		tex->enemy = mlx_load_png("png/norminetteL.png");
	if (keytype == 'A')
		tex->enemy = mlx_load_png("png/norminetteR.png");
	if (keytype == 'D')
		tex->enemy = mlx_load_png("png/norminetteL.png");
	else if (keytype == 'T')
	{
		tex->enemy = mlx_load_png("png/norminetteR.png");
		mlx_draw_texture(img->enemy, tex->enemy, 0, 0);
		mlx_image_to_window(mlx, img->enemy, x, y);
		mlx_set_instance_depth(img->enemy->instances, 4);
	}
	mlx_draw_texture(img->enemy, tex->enemy, 0, 0);
	mlx_delete_texture(tex->enemy);
	ft_enemy_location(img->wall);
	ft_player_location(img->enemy, 'F');
	return (1);
}

char	ft_load_enemy2(mlx_t *mlx, int x, int y, char keytype)
{
	t_texture	*tex;
	t_image		*img;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	if (keytype == 'W' || keytype == 'S')
		tex->enemy2 = mlx_load_png("png/norminetteL.png");
	if (keytype == 'A')
		tex->enemy2 = mlx_load_png("png/norminetteL.png");
	if (keytype == 'D')
		tex->enemy2 = mlx_load_png("png/norminetteR.png");
	else if (keytype == 'K')
	{
		tex->enemy2 = mlx_load_png("png/norminetteL.png");
		mlx_draw_texture(img->enemy2, tex->enemy2, 0, 0);
		mlx_image_to_window(mlx, img->enemy2, x, y);
		mlx_set_instance_depth(img->enemy2->instances, 4);
	}
	mlx_draw_texture(img->enemy2, tex->enemy2, 0, 0);
	mlx_delete_texture(tex->enemy2);
	ft_enemy2_location(img->wall);
	ft_player_location(img->enemy2, 'N');
	return (1);
}

char	ft_load_player(mlx_t *mlx, int x, int y, char keytype)
{
	t_texture	*tex;
	t_image		*img;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	if (keytype == 'W')
		tex->player = mlx_load_png("png/playerU.png");
	else if (keytype == 'S')
		tex->player = mlx_load_png("png/playerD.png");
	else if (keytype == 'A')
		tex->player = mlx_load_png("png/playerL.png");
	else if (keytype == 'D')
		tex->player = mlx_load_png("png/playerR.png");
	else if (keytype == 'X')
	{
		tex->player = mlx_load_png("png/playerR.png");
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

void	ft_player_hook(void *mlx)
{
	t_image	*img;

	img = gset_img(NULL);
	if (img->player->enabled == true)
		ft_player_movement(mlx, img);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

// check the if!!!
void	ft_enemy_hook(void *mlx)
{
	t_image	*img;

	img = gset_img(NULL);
	if (img->enemy->enabled == true && img->enemy2->enabled == true)
		ft_move_enemy(mlx, img);
}
