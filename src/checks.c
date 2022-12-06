/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:18:07 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/06 18:08:34 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
check for position
check for wall
check for collectible
check for exit
*/

#include "../includes/so_long.h"

void	ft_move_enemy(mlx_t *mlx, t_image *img)
{
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (ft_load_enemy(mlx, 0, 0, 'W') == 0)
			ft_move_enemy_W(img);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (ft_load_enemy(mlx, 0, 0, 'S') == 0)
			ft_move_enemy_S(img);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		if (ft_load_enemy(mlx, 0, 0, 'A') == 0)
			ft_move_enemy_A(img);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		if (ft_load_enemy(mlx, 0, 0, 'D') == 0)
			ft_move_enemy_D(img);
	}
}

void	ft_move_enemy_W(t_image *img)
{
	img->enemy->instances->y += 3;
	img->enemy2->instances->y -= 3;
}

void	ft_move_enemy_S(t_image *img)
{
	img->enemy->instances->y -= 3;
	img->enemy2->instances->y += 3;
}

void	ft_move_enemy_A(t_image *img)
{
	img->enemy->instances->x += 3;
	img->enemy2->instances->x -= 3;
}

void	ft_move_enemy_D(t_image *img)
{
	img->enemy->instances->x -= 3;
	img->enemy2->instances->x += 3;
}





void	ft_enemy_hook(void *mlx)
{
	t_image	*img;
	
	img = gset_img(NULL);
	if (img->player->enabled == true)
		ft_move_enemy(mlx, img);
}


char	ft_load_enemy2(mlx_t *mlx, int x, int y, char keytype)
{
	t_texture	*tex;
	t_image	*img;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	if (keytype == 'W' || keytype == 'S' || keytype == 'A' || keytype == 'D')
	{
		tex->enemy2 = mlx_load_png("png/norminette.png");
	}
	else if (keytype == 'T')
	{
		tex->enemy2 = mlx_load_png("png/norminette.png");
		mlx_draw_texture(img->enemy2, tex->enemy2, 0, 0);
		mlx_image_to_window(mlx, img->enemy2, x, y);
		mlx_set_instance_depth(img->enemy2->instances,  4);
	}
	mlx_draw_texture(img->enemy2, tex->enemy2, 0, 0);
	mlx_delete_texture(tex->enemy2);
	return (0);
}

// char	ft_load_enemy3(mlx_t *mlx, int x, int y, char keytype)
// {
// 	t_texture	*tex;
// 	t_image	*img;

// 	tex = gset_tex(NULL);
// 	img = gset_img(NULL);
// 	if (keytype == 'W' || keytype == 'S' || keytype == 'A' || keytype == 'D')
// 	{
// 		tex->enemy3 = mlx_load_png("png/norminette.png");
// 	}
// 	else if (keytype == 'T')
// 	{
// 		tex->enemy3 = mlx_load_png("png/norminette.png");
// 		mlx_draw_texture(img->enemy3, tex->enemy3, 0, 0);
// 		mlx_image_to_window(mlx, img->enemy3, x, y);
// 		mlx_set_instance_depth(img->enemy3->instances,  4);
// 	}
// 	mlx_draw_texture(img->enemy3, tex->enemy3, 0, 0);
// 	mlx_delete_texture(tex->enemy3);
// 	return (0);
// }

// char	ft_load_enemy4(mlx_t *mlx, int x, int y, char keytype)
// {
// 	t_texture	*tex;
// 	t_image	*img;

// 	tex = gset_tex(NULL);
// 	img = gset_img(NULL);
// 	if (keytype == 'W' || keytype == 'S' || keytype == 'A' || keytype == 'D')
// 	{
// 		tex->enemy4 = mlx_load_png("png/norminette.png");
// 	}
// 	else if (keytype == 'T')
// 	{
// 		tex->enemy4 = mlx_load_png("png/norminette.png");
// 		mlx_draw_texture(img->enemy4, tex->enemy4, 0, 0);
// 		mlx_image_to_window(mlx, img->enemy4, x, y);
// 		mlx_set_instance_depth(img->enemy4->instances,  4);
// 	}
// 	mlx_draw_texture(img->enemy4, tex->enemy4, 0, 0);
// 	mlx_delete_texture(tex->enemy4);
// 	return (0);
// }

// char	ft_load_enemy5(mlx_t *mlx, int x, int y, char keytype)
// {
// 	t_texture	*tex;
// 	t_image	*img;

// 	tex = gset_tex(NULL);
// 	img = gset_img(NULL);
// 	if (keytype == 'W' || keytype == 'S' || keytype == 'A' || keytype == 'D')
// 	{
// 		tex->enemy5 = mlx_load_png("png/norminette.png");
// 	}
// 	else if (keytype == 'T')
// 	{
// 		tex->enemy5 = mlx_load_png("png/norminette.png");
// 		mlx_draw_texture(img->enemy5, tex->enemy5, 0, 0);
// 		mlx_image_to_window(mlx, img->enemy5, x, y);
// 		mlx_set_instance_depth(img->enemy5->instances,  4);
// 	}
// 	mlx_draw_texture(img->enemy5, tex->enemy5, 0, 0);
// 	mlx_delete_texture(tex->enemy5);
// 	return (0);
// }



char	ft_enemy2_location(mlx_image_t *element)
{
	t_image	*img;
	mlx_instance_t	*ins;
	int	x_m;
	int y_m;
	int amount;

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
	t_image *img;

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

// char	ft_enemy3_location(mlx_image_t *element)
// {
// 	t_image	*img;
// 	mlx_instance_t	*ins;
// 	int	x_m;
// 	int y_m;
// 	int amount;

// 	img = gset_img(NULL);
// 	ins = element->instances;
// 	amount = 0;
// 	while (amount < element->count)
// 	{
// 		if (ins[amount].x < img->enemy3->instances->x)
// 			x_m = 30;
// 		else
// 			x_m = 30;
// 		if (ins[amount].y < img->enemy3->instances->y)
// 			y_m = 30;
// 		else
// 			y_m = 30;
// 		if (fabs((float)(ins[amount].x - img->enemy3->instances->x)) < x_m)
// 			if (fabs((float)(ins[amount].y - img->enemy3->instances->y)) < y_m)
// 				ft_wall_enemy2(x_m, y_m, ins + amount);
// 		amount++;
// 	}		
// 	return (1);
// }

// void	ft_wall_enemy3(int x_m, int y_m, mlx_instance_t *element_ins)
// {
// 	mlx_instance_t	*enemy_ins;
// 	t_image *img;

// 	img = gset_img(NULL);
// 	enemy_ins = img->enemy3->instances;
// 	if (!(fabs((float)((element_ins->x + 6) - enemy_ins->x)) < x_m))
// 		enemy_ins->x -= 5;
// 	if (!(fabs((float)(element_ins->x - (enemy_ins->x + 6))) < x_m))
// 		enemy_ins->x += 5;
// 	if (!(fabs((float)((element_ins->y + 6) - enemy_ins->y)) < y_m))
// 		enemy_ins->y -= 5;
// 	if (!(fabs((float)(element_ins->y - (enemy_ins->y + 6))) < y_m))
// 		enemy_ins->y += 5;
// }

// char	ft_enemy4_location(mlx_image_t *element)
// {
// 	t_image	*img;
// 	mlx_instance_t	*ins;
// 	int	x_m;
// 	int y_m;
// 	int amount;

// 	img = gset_img(NULL);
// 	ins = element->instances;
// 	amount = 0;
// 	while (amount < element->count)
// 	{
// 		if (ins[amount].x < img->enemy4->instances->x)
// 			x_m = 30;
// 		else
// 			x_m = 30;
// 		if (ins[amount].y < img->enemy4->instances->y)
// 			y_m = 30;
// 		else
// 			y_m = 30;
// 		if (fabs((float)(ins[amount].x - img->enemy4->instances->x)) < x_m)
// 			if (fabs((float)(ins[amount].y - img->enemy4->instances->y)) < y_m)
// 				ft_wall_enemy2(x_m, y_m, ins + amount);
// 		amount++;
// 	}		
// 	return (1);
// }

// void	ft_wall_enemy4(int x_m, int y_m, mlx_instance_t *element_ins)
// {
// 	mlx_instance_t	*enemy_ins;
// 	t_image *img;

// 	img = gset_img(NULL);
// 	enemy_ins = img->enemy4->instances;
// 	if (!(fabs((float)((element_ins->x + 6) - enemy_ins->x)) < x_m))
// 		enemy_ins->x -= 5;
// 	if (!(fabs((float)(element_ins->x - (enemy_ins->x + 6))) < x_m))
// 		enemy_ins->x += 5;
// 	if (!(fabs((float)((element_ins->y + 6) - enemy_ins->y)) < y_m))
// 		enemy_ins->y -= 5;
// 	if (!(fabs((float)(element_ins->y - (enemy_ins->y + 6))) < y_m))
// 		enemy_ins->y += 5;
// }

// char	ft_enemy5_location(mlx_image_t *element)
// {
// 	t_image	*img;
// 	mlx_instance_t	*ins;
// 	int	x_m;
// 	int y_m;
// 	int amount;

// 	img = gset_img(NULL);
// 	ins = element->instances;
// 	amount = 0;
// 	while (amount < element->count)
// 	{
// 		if (ins[amount].x < img->enemy5->instances->x)
// 			x_m = 30;
// 		else
// 			x_m = 30;
// 		if (ins[amount].y < img->enemy5->instances->y)
// 			y_m = 30;
// 		else
// 			y_m = 30;
// 		if (fabs((float)(ins[amount].x - img->enemy5->instances->x)) < x_m)
// 			if (fabs((float)(ins[amount].y - img->enemy5->instances->y)) < y_m)
// 				ft_wall_enemy2(x_m, y_m, ins + amount);
// 		amount++;
// 	}		
// 	return (1);
// }

// void	ft_wall_enemy5(int x_m, int y_m, mlx_instance_t *element_ins)
// {
// 	mlx_instance_t	*enemy_ins;
// 	t_image *img;

// 	img = gset_img(NULL);
// 	enemy_ins = img->enemy5->instances;
// 	if (!(fabs((float)((element_ins->x + 6) - enemy_ins->x)) < x_m))
// 		enemy_ins->x -= 5;
// 	if (!(fabs((float)(element_ins->x - (enemy_ins->x + 6))) < x_m))
// 		enemy_ins->x += 5;
// 	if (!(fabs((float)((element_ins->y + 6) - enemy_ins->y)) < y_m))
// 		enemy_ins->y -= 5;
// 	if (!(fabs((float)(element_ins->y - (enemy_ins->y + 6))) < y_m))
// 		enemy_ins->y += 5;
// }