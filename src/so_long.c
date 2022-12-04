/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:10:50 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/04 23:26:09 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_image_t	*g_img;

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_image	img;
	t_texture	tex;
	
	ft_wrong_input(argc, argv);
	if (ft_error_types(argv[1]) == 1)
		exit(EXIT_FAILURE);
	ft_read_and_print_map(argv[1]);
	mlx = gset_mlx(open_mapsize_window(argv[1], 0));
	if (!mlx)
		exit(EXIT_FAILURE);
	ft_make_new_images(mlx, &img);
	gset_img(&img);
	gset_tex(&tex);
	ft_make_map(mlx, argv[1]);
	mlx_loop_hook(mlx, ft_player_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

bool	ft_wrong_input(int argc, char **argv)
{
	if (argc > 2 || ft_strstr(argv[1], ".ber") == false)
	{
		if (argc > 2)
			ft_printf("\e[4;31mError!\e[0m\n\e[1;4;34mToo many arguments!\e[0m\n");
		else
			ft_printf("\e[4;31mError!\e[0m\n\e[1;4;34mMaybe something missing? oH, yEs! A MAP!\e[0m\n");
		return (1);
	}	
	return (0);
}



//32pixel size for each byte
mlx_t	*open_mapsize_window(char *map, int count)
{
	mlx_t	*mlx;
	int		x;
	int		y;
	int		fd;
	char	*buffer;

	fd = open(map, O_RDWR);
	buffer = get_next_line(fd);
	y = 0;
	while (buffer != 0)
	{
		x = 0;
		while (buffer[count] != '\n' && buffer[count] != '\0')
			count++;
		x = count;
		count = 0;
		y++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	mlx = mlx_init(x * 32, y * 32, "Survive The Norm", 1);
	return (mlx);
}

void	ft_make_new_images(mlx_t *mlx, t_image *img)
{
	img->walking_path = mlx_new_image(mlx, 32, 32);
	img->player = mlx_new_image(mlx, 32, 32);
	img->wall = mlx_new_image(mlx, 32, 32);
	img->pickitup = mlx_new_image(mlx, 32, 32);
	img->exit = mlx_new_image(mlx, 32, 32);
	img->enemy = mlx_new_image(mlx, 32, 32);
}

void	ft_make_map(mlx_t *mlx, char *map)
{
	int	x;
	int	y;
	int	fd;
	int	count;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		count = 0;
		x = 0;
		while (line[count] != '\n' && line[count] != '\0')
		{
			ft_put_loaded_image(mlx, line[count], x, y);
			x += 32;
			count++;
		}
		free(line);
		line = get_next_line(fd);
		y += 32;
	}
	close(fd);
}

void	ft_put_loaded_image(mlx_t *mlx, char c, int x, int y)
{
	if (c == 'F' || c == 'E' || c == '0' || c == 'P' || c == 'C')
		ft_load_walking_path(mlx, x, y, '0');
	if (c == '1')
		ft_load_wall(mlx, x, y);
	if (c == 'P')
		ft_load_player(mlx, x, y, 'F');
	if (c == 'C')
		ft_load_pickitup(mlx, x, y);
	if (c == 'E')
		ft_load_exit(mlx, x, y);
	if (c == 'F')
		ft_load_enemy(mlx, x, y);
}

void	ft_load_walking_path(mlx_t *mlx, int x, int y, char c)
{
	t_image		*img;
	t_texture	*tex;
	int			itw;

	tex = gset_tex(NULL);
	img = gset_img(NULL);

	tex->walking_path = mlx_load_png("png/walking_path.png");
	if (c == '0')
	{
		mlx_draw_texture(img->walking_path, tex->walking_path, 0, 0);
		mlx_delete_texture(tex->walking_path);
		itw = mlx_image_to_window(mlx, img->walking_path, x, y);
		mlx_set_instance_depth(img->walking_path->instances + itw, 2);
	}
	if (c == 'C')
		mlx_draw_texture(img->pickitup, tex->walking_path, 0, 0);
}

void	ft_load_wall(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image	*img;
	int			itw;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	itw = mlx_image_to_window(mlx, img->wall, x, y);
	tex->wall = mlx_load_png("png/wall.png");
	mlx_draw_texture(img->wall, tex->wall, 0, 0);
	mlx_set_instance_depth(img->wall->instances + itw, 2);
	mlx_delete_texture(tex->wall);
}

void	ft_load_pickitup(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image	*img;
	int			itw;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	itw = mlx_image_to_window(mlx, img->pickitup, x, y);
	tex->pickitup = mlx_load_png("png/pickitup.png");
	mlx_draw_texture(img->pickitup, tex->pickitup, 0, 0);
	mlx_set_instance_depth(img->pickitup->instances + itw, 3);
	mlx_delete_texture(tex->pickitup);
}

void	ft_load_exit(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image	*img;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	mlx_image_to_window(mlx, img->exit, x, y);
	tex->exit = mlx_load_png("png/exit.png");
	mlx_draw_texture(img->exit, tex->exit, 0, 0);
	mlx_set_instance_depth(img->exit->instances, 4);
	mlx_delete_texture(tex->exit);
}

void	ft_load_failure(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image	*img;
	
	
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
	t_image	*img;

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

char	ft_load_player(mlx_t *mlx, int x, int y, char keytype)
{
	t_texture	*tex;
	t_image	*img;

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
	else if (keytype == 'F')
	{
		tex->player = mlx_load_png("png/playerR.png");
		mlx_draw_texture(img->player, tex->player, 0, 0);
		mlx_image_to_window(mlx, img->player, x, y);
		mlx_set_instance_depth(img->player->instances, 5);
	}
	mlx_draw_texture(img->player, tex->player, 0, 0);
	mlx_delete_texture(tex->player);
	ft_player_location(img->pickitup, 'C');
	ft_player_location(img->exit, 'E');
	ft_player_location(img->enemy, 'F');
	return (ft_player_location(img->wall, '1'));
}

void	ft_load_enemy(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image	*img;
	int	itw;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	itw = mlx_image_to_window(mlx, img->enemy, x, y);
	tex->enemy = mlx_load_png("png/norminette.png");
	mlx_draw_texture(img->enemy, tex->enemy, 0, 0);
	mlx_set_instance_depth(img->enemy->instances + itw, 3);
	mlx_delete_texture(tex->enemy);
}




char	ft_error_types(char *argv)
{
	char	error_type;
	
	error_type = ft_map_validator(argv);
	if (error_type == '1')
		ft_printf("\e[1;4;31mError!\e[0m\n\e[4;33mMap must be surrounded by walls!\e[0m\n");
	else if (error_type == 'M')
		ft_printf("\e[1;4;31mError!\e[0m\n\e[4;33mMap must contain P, E and C!\e[0m\n");
	else if (error_type == 'O')
		ft_printf("\e[1;4;31mError!\e[0m\n\e[4;33mThere is NO or MORE exit or/and player than one!\e[0m\n");
	else if (error_type == 'I')
		ft_printf("\e[1;4;31mError!\e[0m\n\e[4;33mInvalid char/'s in the map!\e[0m\n\e[1;4;34mValid chars: 0, 1, P, E, C, F.\e[0m\n");
	else if (error_type == 'V')
		ft_printf("\e[1;4;31mError!\e[0m\n\e[4;33mNo valid path to exit!\e[0m\n");
	else if (error_type == 'R')
		ft_printf("\e[1;4;31mError!\e[0m\n\e[4;33mMap must be rectangular!\e[0m\n");
	else if (error_type == 'A')
		ft_printf("\e[1;4;31mError!\e[0m\n\e[4;33mMemory allocation failed!\e[0m\n");
	else
		{ft_printf("\e[1;4;32mThe map is valid and ready to launch!\e[0m\n");
		return (0);}
	return (1);
}



char	ft_map_validator(char *argv)
{
	size_t	length;
	size_t	row;
	char	error;

	row = 0;
	error = ft_map_have_walls(open(argv, O_RDONLY), &length, &row, 0);
	if (error != 0)
		return (error);
	error = ft_map_have_all_elements(open(argv, O_RDWR), 0, 0, 0);
	if (error != 0)
		return (error);
	error = ft_map_with_validpath(argv, row, length, 0);
	if (error != 0)
		return (error);
	return (0);
}

char	ft_map_element_check(char c, char *plyr, char *pick, char *ext)
{
	if (c == 'C')
		*pick = 1;
	else if (c == 'E')
		(*ext)++;
	else if (c == 'P')
		(*plyr)++;
	else if (c != 'F' && c != '1' && c != '\n' && c != '0')
		return ('I');
	return (0);
}

char	ft_map_have_walls(int fd, size_t *length, size_t *row, size_t count)
{
	char	*line;
	char	*lineb;
	
	line = get_next_line(fd);
	*length = ft_gnlinelen(line);
	lineb = malloc((*length + 1));
	if (lineb == NULL)
		return ('A');
	while (line)
	{
		//if the length of the readed line isn't equal, map isn't rectangular
		if (*length != ft_gnlinelen(line))
			return ('R');
		//if the first element or the last of the line isn't wall
		if (line[0] != '1' || line[*length - 1] != '1')
			return ('1');
		//copy line to lineb(efore) and free the line. maybe use strjoin
		ft_strlcpy(lineb, line, *length + 1);
		free(line);
		line = get_next_line(fd);
		count = 0;
		//check the first line for the wall
		if ((*row)++ == 0)
		{
			while (count < *length)
			{
				if (lineb[count++] != '1')
					return ('1');
			}
		}
	}
	//checking the the last row for the wall FFFFFUUUUUUUUCCCCCKKKK
	if (line == NULL)
	{
		count = 0;
		while (count < *length)
		{
			if (lineb[count++] != '1')
				return ('1');
		}
	}
		
	free(lineb);
	return (0);
}

char	ft_map_have_all_elements(int fd, char ext, char pick, char plyr)
{
	size_t	length;
	size_t	count;
	char	*line;
	char	linecopy;

	line = get_next_line(fd);
	length = ft_gnlinelen(line);
	while (line)
	{
		count = 0;
		while (count < length)
		{
			linecopy = line[count++];
			if (ft_map_element_check(linecopy, &plyr, &pick, &ext) == 'I')
				return ('I');
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!plyr || !ext || plyr > 1 || ext > 1)
		return ('O');
	else if ((plyr + ext + pick) != 3)
		return ('M');
	return (0);
}





char	ft_map_with_validpath(char *argv, size_t rows, size_t columns, int fd)
{
	size_t	x;
	size_t	y;
	size_t	path;
	char	**map;
	char	*line;

	fd = open(argv, O_RDONLY);
	map = malloc(rows * sizeof(char *));
	if (map == NULL)
		return ('A');
	line = get_next_line(fd);
	path = 0;
	while (line != NULL)
	{
		map[path] = malloc((columns + 1));
		if (map[path] == NULL)
			return ('A');
		ft_strlcpy(map[path++], line, columns +1);
		free(line);
		line = get_next_line(fd);
	}
	ft_get_player(map, &x, &y, columns);
	path = ft_dfs(map, x, y, rows);
	ft_free_map(map, rows);
	return (path);
}

void	ft_free_map(char **map, size_t rows)
{
	size_t	count;

	count = 0;
	while (count < rows)
	{
		free(map[count]);
		count++;
	}
	free(map);
}

void	ft_get_player(char **map, size_t *x, size_t *y, size_t columns)
{
	char	player_position;
	
	*x = 0;
	*y = 1;
	player_position = '0';
	while (player_position != 'P')
	{
		if (*x < columns -2)
			(*x)++;
		else
		{
			*x = 1;
			(*y)++;
		}
		player_position = map[*y][*x];
	}
}

int	ft_dfs(char **map, size_t x, size_t y, size_t rows)
{
	if (x < 1 || y < 1 || x >= ft_strlen(*map) || y > rows
		|| map[y][x] == 'X' || map[y][x] == 'F')
		return ('V');
	if (map[y][x] == 'E')
		return (0);
	map[y][x] = 'X';
	if (ft_dfs(map, x - 1, y, rows) == 0
		|| ft_dfs(map, x + 1, y, rows) == 0
		|| ft_dfs(map, x, y - 1, rows) == 0
		|| ft_dfs(map, x, y + 1, rows) == 0)
		return (0);
	
	else
		return ('V');
}


void	ft_player_movement(mlx_t *mlx, t_image *img)
{
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (ft_load_player(mlx, 0, 0, 'W') == true)
			img->player->instances[0].y -= 4;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (ft_load_player(mlx, 0, 0, 'S') == true)
			img->player->instances[0].y += 4;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		if (ft_load_player(mlx, 0, 0, 'A') == true)
			img->player->instances[0].x -= 4;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		if (ft_load_player(mlx, 0, 0, 'D') == true)
			img->player->instances[0].x += 4;
	}
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


char	ft_is_wall(int x_m, int y_m, mlx_instance_t *element_ins, char mapelement)
{
	mlx_instance_t	*player_ins;
	t_image *img;

	//if the map element isn't wall check if it is collectableee
	if (mapelement != '1')
		return (ft_isit_pickable(element_ins, mapelement));
	img = gset_img(NULL);
	player_ins = img->player->instances;
	//checks player position and moves back to the original position before hitting the wall
	if (!(fabs((float)((element_ins->x + 6) - player_ins->x)) < x_m))
		player_ins->x -= 1;
	if (!(fabs((float)(element_ins->x - (player_ins->x + 6))) < x_m))
		player_ins->x += 1;
	if (!(fabs((float)((element_ins->y + 6) - player_ins->y)) < y_m))
		player_ins->y -= 1;
	if (!(fabs((float)(element_ins->y - (player_ins->y + 6))) < y_m))
		player_ins->y += 1;
	return (0);
}

char	ft_isit_norminette(char mapelement)
{
	t_image	*img;

	if (mapelement != 'F')
		return (ft_can_we_exit());
	img = gset_img(NULL);
	if (img->player->enabled == true)
		ft_load_failure(gset_mlx(NULL), 370, 140);
	img->player->enabled = false;
	img->pickitup->enabled = false;
	return (1);
}

char	ft_isit_pickable(mlx_instance_t *element_ins, char mapelement)
{
	//if it isn't collectable checks for exit
	if (mapelement != 'C')
		return (ft_isit_norminette(mapelement));
	//if it is indeed collectable then disable the current element
	element_ins->enabled = false;
	return (1);
}

char	ft_can_we_exit(void)
{
	t_image	*img;
	int	amount;
	
	img = gset_img(NULL);
	amount = 0;
	//stays in the while loop until we have collectibles on the map
	while (amount < img->pickitup->count)
	{
		if (img->pickitup->instances[amount].enabled == true)
			return (0);
		amount++;
	}
	// load exit img
	img->player->enabled = false;
	if (img->player->enabled == false)
		ft_load_victory(gset_mlx(NULL), 389, 170);
	//if there is no collectible
	if (img->pickitup->enabled == false)
		img->victory_screen->enabled = true;
	return (1);
}

//x_m and y_m controls the bounce back from the walls
char	ft_player_location(mlx_image_t *element, char mapelement)
{
	t_image	*img;
	mlx_instance_t	*ins;
	int	x_m;
	int y_m;
	int amount;
	
	amount = 0;
	img = gset_img(NULL);
	ins = element->instances;
	while (amount < element->count)
	{
		//left right 2-2 pixel less for the better movement
		if (ins[amount].x < img->player->instances->x)
			x_m = 30;
		else
			x_m = 30;
		//up and down left 4-4 pixel less for the better movement
		if (ins[amount].y < img->player->instances->y)
			y_m = 28;
		else
			y_m = 28;
		if (fabs((float)(ins[amount].x - img->player->instances->x)) < x_m)
			if (fabs((float)(ins[amount].y - img->player->instances->y)) < y_m)
				return (ft_is_wall(x_m, y_m, ins + amount, mapelement));
		amount++;
	}
	return (1);
}
































// replace this shitpile later on
t_image	*gset_img(t_image *p_img)
{
	static t_image	*img;

	if (p_img != NULL)
		img = p_img;
	return (img);
}

t_texture	*gset_tex(t_texture *p_tex)
{
	static t_texture	*tex;

	if (p_tex != NULL)
		tex = p_tex;
	return (tex);
}

mlx_t	*gset_mlx(mlx_t *p_mlx)
{
	static mlx_t	*mlx;

	if (p_mlx != NULL)
		mlx = p_mlx;
	return (mlx);
}
















void	ft_read_and_print_map(char *map)
{
	int count;
	int	x;
	int y;
	int fd;
	char *line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		count = 0;
		x = 0;
		while (line[count] != '\0')
		{
			put_chars(line[count]);
			// x += 32;
			count ++;
		}
		free(line);
		line = get_next_line(fd);
		// y += 32;
	}
	close(fd);
}

char	put_chars(char c)
{
	if (c == '0')
		write(1, &c, 1);
	if (c == '1')
		write(1, &c, 1);
	if (c == 'C')
		write(1, &c, 1);
	if (c == 'E')
		write(1, &c, 1);
	if (c == 'P')
		write(1, &c, 1);
	if (c == 'F')
		write(1, &c, 1);
	if (c =='\n')
		write(1, &c, 1);
	return (0);
}

// void	hook(void *param)
// {
// 	mlx_t	*mlx;

// 	mlx = param;
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		g_img->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		g_img->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		g_img->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		g_img->instances[0].x += 5;
// }



























