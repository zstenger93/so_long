/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:06:49 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/02 19:18:00 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

typedef struct s_texture
{
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit_screen;
	mlx_texture_t	*wall;
	mlx_texture_t	*pickitup;
	mlx_texture_t	*walking_path;
	
	
}	t_texture;


typedef struct s_image
{
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*exit_screen;
	mlx_image_t	*wall;
	mlx_image_t	*pickitup;
	mlx_image_t	*walking_path;
	
	
}	t_image;

// temporary player
void	hook(void *param);



//checking for wrong input
// bool	ft_wrong_input(int argc, char **argv);

//reading the map, need to rewrite
void	ft_read_and_print_map(char *map);

//temporary for printing the map to terminal
char	put_chars(char c);

//obviousi guess
mlx_t	*open_mapsize_window(char *map, int i);

void	ft_make_the_images(mlx_t *mlx, t_image *img);

void	ft_make_map(mlx_t *mlx, char *map);

void	ft_put_loaded_image(mlx_t *mlx, char c, int x, int y);

void	ft_load_walking_path(mlx_t *mlx, int x, int y, char c);

void	ft_load_wall(mlx_t *mlx, int x, int y);

void	ft_load_pickitup(mlx_t *mlx, int x, int y);

void	ft_load_exit(mlx_t *mlx, int x, int y);

void	ft_load_player(mlx_t *mlx, int x, int y);


mlx_t	*gset_mlx(mlx_t *p_mlx);
t_texture	*gset_tex(t_texture *p_tex);
t_image	*gset_img(t_image *p_img);









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