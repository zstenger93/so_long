/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:06:49 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/15 10:57:49 by zstenger         ###   ########.fr       */
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

//TEXTURES WE WILL PUT ON THE DIFFERENT PNG'S
typedef struct s_texture
{
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*victory_screen;
	mlx_texture_t	*wall;
	mlx_texture_t	*pickitup;
	mlx_texture_t	*walking_path;
}	t_texture;

//IMAGES WE WILL SHOW IN THE WINDOW AND MOVE FOR MOVEMENT COUNT
typedef struct s_image
{
	mlx_image_t	*move;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*victory_screen;
	mlx_image_t	*wall;
	mlx_image_t	*pickitup;
	mlx_image_t	*walking_path;
}	t_image;

//THIS TWO FOR PRINTING OUT THE MAP COLORIZED INTO THE TERMINAL
/*
void		ft_read_and_print_map(char *map);
char		put_chars(char c);
*/

//INPUT CHECK
bool		ft_wrong_input(int argc, char **argv);
//CHECK ALL ERROR TYPES ON THE PROVIDED MAP
char		ft_error_types(char *argv);
char		ft_error_types2(char *argv);
//WALLS, ELEMENTS, ENEMIES
char		ft_map_validator(char *argv);
char		ft_have_walls(int fd, size_t *length, size_t *row, size_t count);
char		ft_last_line(char *line, char *lineb, size_t *length, size_t count);
char		ft_map_have_all_elements(int fd, char ext, char pick, char plyr);
char		ft_map_element_check(char c, char *plyr, char *pick, char *ext);
//CHECK VALID PATH TO THE EXIT AND ALL THE COLLECTIBLES with DFS
char		ft_map_validpath(char *argv, size_t rows, size_t columns, int fd);
void		ft_get_player(char **map, size_t *x, size_t *y, size_t columns);
char		ft_dfs_check(char **map, size_t x, size_t y, size_t rows);
int			ft_dfs(char **map, size_t x, size_t y, size_t rows);
void		ft_free_map(char **map, size_t rows);
//OPEN WINDOW
mlx_t		*ft_open_mapsize_window(char *map, int i);
//CREATE THE NEW IMAGES
void		ft_make_new_images(mlx_t *mlx, t_image *img);
//MAKE THE ACTUAL MAP YOU WILL SEE
void		ft_make_map(mlx_t *mlx, char *map);
void		ft_put_loaded_image(mlx_t *mlx, char c, int x, int y);
void		ft_load_walking_path(mlx_t *mlx, int x, int y);
void		ft_load_wall(mlx_t *mlx, int x, int y);
void		ft_load_pickitup(mlx_t *mlx, int x, int y);
void		ft_load_exit(mlx_t *mlx, int x, int y);
char		ft_load_player(mlx_t *mlx, int x, int y, char keytype);
//HOOK
void		ft_player_hook(void *mlx);
//PLAYERMOVEMENTS
void		ft_player_movement(mlx_t *mlx, t_image *img);
//PLAYER LOCATION CHECKS
char		ft_player_location(mlx_image_t *element, char mapelement);
char		ft_is_wall(int x, int y, mlx_instance_t *element_ins, char maplmnt);
char		ft_isit_pickable(mlx_instance_t *element_ins, char mapelement);
char		ft_can_we_exit(void);
//IMAGES TO LOAD CASE OF WINNING
void		ft_load_victory(mlx_t *mlx, int x, int y);
//DISABLE ALL OTHER IMAGES
void		ft_images_disabled(void);
//PRINT MOVEMENT TO THE TERMINAL
char		ft_move_and_count(mlx_t *mlx, t_image *img);
//NULL SETTING MLX, IMAGES AND TEXTURES OR RETURN IT
mlx_t		*null_set_mlx(mlx_t *mlx_to_null);
t_texture	*null_set_tex(t_texture *tex_to_null);
t_image		*null_set_img(t_image *img_to_null);

#endif