/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:55:42 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/29 18:38:07 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*img;

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	hook(void *player)
{
	
	mlx_t	*mlx;

	mlx = player;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);

	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y -= 15;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y += 15;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x -= 15;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x += 15;
}



int	main(int argc, char **argv)
{
	mlx_t	*mlx;


	mlx = mlx_init(WIDTH, HEIGHT, "Race Against The Black Hole", true);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, 55, 55);
	memset(img->pixels, 255, img->width * img->height * sizeof(int));
	mlx_image_to_window(mlx, img, 0, 0);



	
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}





















