/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:06:49 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/07 18:14:00 by zstenger         ###   ########.fr       */
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


typedef struct s_mapsize
{
	int	width;
	int	height;
	char	**temp_map;
	int	p_x;
	int	p_y;
}	t_mapsize;

typedef struct s_texture
{
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*victory_screen;
	mlx_texture_t	*failure_screen;
	mlx_texture_t	*wall;
	mlx_texture_t	*pickitup;
	mlx_texture_t	*walking_path;
	mlx_texture_t	*enemy;
	mlx_texture_t	*enemy2;
	mlx_texture_t	*enemy3;
	mlx_texture_t	*enemy4;
	mlx_texture_t	*enemy5;
}	t_texture;


typedef struct s_image
{
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*victory_screen;
	mlx_image_t *failure_screen;
	mlx_image_t	*wall;
	mlx_image_t	*pickitup;
	mlx_image_t	*walking_path;
	mlx_image_t	*enemy;
	mlx_image_t	*enemy2;
	mlx_image_t	*enemy3;
	mlx_image_t	*enemy4;
	mlx_image_t	*enemy5;
}	t_image;

// temporary player
void	hook(void *param);



//checking for wrong input
bool	ft_wrong_input(int argc, char **argv);

//reading the map and print it to terminal
void	ft_read_and_print_map(char *map);

//temporary for printing the map to terminal
char	put_chars(char c);

//obviousi guess
mlx_t	*ft_open_mapsize_window(char *map, int i);


//make the map
void	ft_make_map(mlx_t *mlx, char *map);

//create new images for the png's
void	ft_make_new_images(mlx_t *mlx, t_image *img);

//put the loaded images on the map to the right places
void	ft_put_loaded_image(mlx_t *mlx, char c, int x, int y);

//load the png's on the new images
void	ft_load_walking_path(mlx_t *mlx, int x, int y, char c);
void	ft_load_wall(mlx_t *mlx, int x, int y);
void	ft_load_pickitup(mlx_t *mlx, int x, int y);
void	ft_load_exit(mlx_t *mlx, int x, int y);
char	ft_load_player(mlx_t *mlx, int x, int y, char keytype);
char	ft_load_enemy(mlx_t *mlx, int x, int y, char keytype);
void	ft_load_failure(mlx_t *mlx, int x, int y);
void	ft_load_victory(mlx_t *mlx, int x, int y);

//in case of an error, returning the correct error output
char	ft_error_types(char *argv);

//looking thru the whole map and checking for walls around it
//if there is a valid path to exit or not
//if there is player, exit, collectible and enemy as well in case of bonus
//also if there are more player or exit than one
//all collectibles should be reachable as well otherwise the map cannot be finished
char	ft_map_validator(char *argv);

//checking if the map is surrounded by walls
char	ft_map_have_walls(int fd, size_t *length, size_t *row, size_t count);

//check the map elements
char	ft_map_element_check(char c, char *plyr, char *pick, char *ext, char *n, char *f);

//checking the elements of the map if there is only one player and exit
//if P, C, E, are all present on the map
char	ft_map_have_all_elements(int fd, char ext, char pick, char plyr, char n, char f);

//checking fo valid path on the map to the exit
char	ft_map_with_validpath(char *argv, size_t rows, size_t columns, int fd);

//get the position of the player
void	ft_get_player(char **map, size_t *x, size_t *y, size_t columns);

//search the map for a valid path from the player to the exit
int	ft_dfs(char **map, size_t x, size_t y, size_t rows);

//free the temporary map
void	ft_free_map(char **map, size_t rows);




//moving the player on the map
void	ft_player_movement(mlx_t *mlx, t_image *img);

char	ft_player_location(mlx_image_t *element, char mapelement);
char	ft_is_wall(int x, int y, mlx_instance_t *element_ins, char mapelement);
char	ft_isit_pickable(mlx_instance_t *element_ins, char mapelement);
char	ft_can_we_exit(void);
char	ft_isit_norminette(char mapelement);

char	ft_enemy_location(mlx_image_t *element);
void	ft_wall_enemy(int x_m, int y_m, mlx_instance_t *element_ins);

void	ft_player_hook(void *mlx);




void	ft_enemy_hook(void *mlx);
void	ft_enemy_movement(mlx_t *mlx, t_image *img);
void	ft_move_enemy(mlx_t *mlx, t_image *img);
void	ft_move_enemy_W(t_image *img);
void	ft_move_enemy_S(t_image *img);
void	ft_move_enemy_A(t_image *img);
void	ft_move_enemy_D(t_image *img);


char	ft_load_enemy2(mlx_t *mlx, int x, int y, char keytype);
// char	ft_load_enemy3(mlx_t *mlx, int x, int y, char keytype);
// char	ft_load_enemy4(mlx_t *mlx, int x, int y, char keytype);
// char	ft_load_enemy5(mlx_t *mlx, int x, int y, char keytype);


char	ft_enemy2_location(mlx_image_t *element);
void	ft_wall_enemy2(int x_m, int y_m, mlx_instance_t *element_ins);



// char	ft_enemy3_location(mlx_image_t *element);
// void	ft_wall_enemy3(int x_m, int y_m, mlx_instance_t *element_ins);
// char	ft_enemy4_location(mlx_image_t *element);
// void	ft_wall_enemy4(int x_m, int y_m, mlx_instance_t *element_ins);
// char	ft_enemy5_location(mlx_image_t *element);
// void	ft_wall_enemy5(int x_m, int y_m, mlx_instance_t *element_ins);;


//null setting shitstorm
mlx_t	*gset_mlx(mlx_t *mlx_to_null);
t_texture	*gset_tex(t_texture *tex_to_null);
t_image	*gset_img(t_image *img_to_null);



//WTF
void	ft_enemy2_hook(void *mlx);
void	ft_move_enemy2(mlx_t *mlx, t_image *img);


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