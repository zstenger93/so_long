/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:10:50 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/20 11:37:33 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
file check, error check, open window, make images, nullset them
make the map, open the hooks and run the game until something else happens
loop to deal with rendering and refreshing the window
terminate to clear up everything when the window is closed
*/
int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_image		img;
	t_texture	tex;

	ft_wrong_input(argc, argv);
	if (ft_error_types(argv[1]) == 1)
		exit(EXIT_FAILURE);
	mlx = null_set_mlx(ft_open_mapsize_window(argv[1], 0));
	if (!mlx)
		exit(EXIT_FAILURE);
	ft_make_new_images(mlx, &img);
	null_set_img(&img);
	null_set_tex(&tex);
	ft_make_map(mlx, argv[1]);
	mlx_loop_hook(mlx, ft_player_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

char	ft_can_we_exit(void)
{
	t_image	*img;
	int		amount;

	img = null_set_img(NULL);
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
		ft_load_victory(null_set_mlx(NULL), 0, 0);
		ft_images_disabled();
	}
	if (img->pickitup->enabled == false)
		img->victory_screen->enabled = true;
	return (1);
}

void	ft_load_victory(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image		*img;

	tex = null_set_tex(NULL);
	img = null_set_img(NULL);
	tex->victory_screen = mlx_load_png("png/victory.png");
	img->victory_screen = mlx_new_image(mlx, 389, 170);
	mlx_image_to_window(mlx, img->victory_screen, x, y);
	mlx_draw_texture(img->victory_screen, tex->victory_screen, 0, 0);
	mlx_set_instance_depth(img->victory_screen->instances, 8);
	mlx_delete_texture(tex->victory_screen);
	mlx_set_window_size(mlx, 389, 170);
	mlx_set_window_pos(mlx, 1100, 650);
	return ;
}

void	ft_images_disabled(void)
{
	t_image	*img;

	img = null_set_img(NULL);
	img->player->enabled = false;
	img->pickitup->enabled = false;
	img->wall->enabled = false;
	img->exit->enabled = false;
	img->walking_path->enabled = false;
}
