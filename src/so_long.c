/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:10:50 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/08 13:59:13 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_image		img;
	t_texture	tex;

	ft_wrong_input(argc, argv);
	if (ft_error_types(argv[1]) == 1)
		exit(EXIT_FAILURE);
	mlx = gset_mlx(ft_open_mapsize_window(argv[1], 0));
	if (!mlx)
		exit(EXIT_FAILURE);
	ft_make_new_images(mlx, &img);
	gset_img(&img);
	gset_tex(&tex);
	ft_make_map(mlx, argv[1]);
	mlx_loop_hook(mlx, ft_player_hook, mlx);
	mlx_loop_hook(mlx, ft_enemy_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

char	ft_can_we_exit(void)
{
	t_image	*img;
	int		amount;

	img = gset_img(NULL);
	amount = 0;
	while (amount < img->pickitup->count)
	{
		if (img->pickitup->instances[amount].enabled == true)
			return (0);
		amount++;
	}
	img->player->enabled = false;
	if (img->player->enabled == false)
	{
		ft_load_victory(gset_mlx(NULL), 389, 170);
		ft_images_disabled();
	}
	if (img->pickitup->enabled == false)
		img->victory_screen->enabled = true;
	return (1);
}

void	ft_load_failure(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image		*img;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	tex->failure_screen = mlx_load_png("png/failure.png");
	img->failure_screen = mlx_new_image(mlx, x, y);
	mlx_image_to_window(mlx, img->failure_screen, x, y);
	mlx_draw_texture(img->failure_screen, tex->failure_screen, 0, 0);
	mlx_set_instance_depth(img->failure_screen->instances, 8);
	mlx_delete_texture(tex->failure_screen);
	return ;
}

void	ft_load_victory(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image		*img;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	tex->victory_screen = mlx_load_png("png/victory.png");
	img->victory_screen = mlx_new_image(mlx, x, y);
	mlx_image_to_window(mlx, img->victory_screen, x, y);
	mlx_draw_texture(img->victory_screen, tex->victory_screen, 0, 0);
	mlx_set_instance_depth(img->victory_screen->instances, 8);
	mlx_delete_texture(tex->victory_screen);
	return ;
}

void	ft_images_disabled(void)
{
	t_image	*img;

	img = gset_img(NULL);
	img->player->enabled = false;
	img->pickitup->enabled = false;
	img->enemy->enabled = false;
	img->enemy2->enabled = false;
	img->wall->enabled = false;
	img->exit->enabled = false;
	img->walking_path->enabled = false;
}
/*
int mlx_put_string(mlx_t *mlx, const char *str, int32_t x, int32_t y)
{
	
}

*/
