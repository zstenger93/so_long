/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:06:49 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/29 18:13:08 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line_bonus.h"
#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_texture
{
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit_screen;
	mlx_texture_t	*wall;
	mlx_texture_t	*enemy;
	mlx_texture_t	*walking_path;
	
	
}	t_texture;


typedef struct s_image
{
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*exit_screen;
	mlx_image_t	*wall;
	mlx_image_t	*enemy;
	mlx_image_t	*walking_path;
	
	
}	t_image;


void	hook(void *player);


#endif




// wall: something rocky
// player: marine?
// exit: spaceship
// collectible: people to save
// enemy: aliens
// walking path: metal texture?

//movement: make it diagonal as well



// wall: red bricks?
// player: man/woman
// exit: company building
// collectible: projects/xp
// enemy: blackhole
// walking path: something floorish?