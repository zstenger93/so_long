/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:10:50 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/02 19:56:42 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_image_t	*g_img;

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_image	img;
	t_texture	tex;
	
	if (argc != 2 || !ft_strstr(argv[1], ".ber"))
	{
		printf("add a map you idiot\n");
		exit(EXIT_FAILURE);
	}
	ft_read_and_print_map(argv[1]);

	mlx = gset_mlx(open_mapsize_window(argv[1], 0));
	if (!mlx)
		exit(EXIT_FAILURE);
	ft_make_the_images(mlx, &img);
	gset_img(&img);
	gset_tex(&tex);
	ft_make_map(mlx, argv[1]);
	mlx_loop_hook(mlx, hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);



	
	return (EXIT_SUCCESS);
}

// bool	ft_wrong_input(int argc, char **argv)
// {
// 	if (argc != 2 || !ft_strstr(&argv[1], ".ber"))
// 	{
// 		printf("add a map you idiot\n");
// 		return (1);
// 	}	
// 	return (0);
// }

// char	ft_map_validator(char *argv)
// {
// 	size_t	len;
// 	size_t	row;
// 	char	c;
// }


//32pixel size for each byte
mlx_t	*open_mapsize_window(char *map, int count)
{
	mlx_t	*mlx;
	int		x;
	int		y;
	int		fd;
	char	*buffer;

	y = 0;
	fd = open(map, O_RDWR);
	buffer = get_next_line(fd);
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
	mlx = mlx_init(x * 32, y * 32, "Escape The Black Hole", 1);
	return (mlx);
}

void	ft_make_the_images(mlx_t *mlx, t_image *img)
{
	img->walking_path = mlx_new_image(mlx, 32, 32);
	img->player = mlx_new_image(mlx, 32, 32);
	img->wall = mlx_new_image(mlx, 32, 32);
	img->pickitup = mlx_new_image(mlx, 32, 32);
	img->exit = mlx_new_image(mlx, 32, 32);
	img->exit_screen = mlx_new_image(mlx, 32, 32);
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
	if (c == 'E' || c == '0' || c == 'P' || c == 'C')
		ft_load_walking_path(mlx, x, y, '0');
	if (c == '1')
		ft_load_wall(mlx, x, y);
	if (c == 'P')
		ft_load_player(mlx, x, y);
	if (c == 'C')
		ft_load_pickitup(mlx, x, y);
	if (c == 'E')
		ft_load_exit(mlx, x, y);
}

void	ft_load_walking_path(mlx_t *mlx, int x, int y, char c)
{
	t_image		*img;
	t_texture	*tex;
	int			towindow;

	tex = gset_tex(NULL);
	img = gset_img(NULL);

	tex->walking_path = mlx_load_png("png/walking_path.png");
	if (c == '0')
	{
		mlx_draw_texture(img->walking_path, tex->walking_path, 0, 0);
		mlx_delete_texture(tex->walking_path);
		towindow = mlx_image_to_window(mlx, img->walking_path, x, y);
		mlx_set_instance_depth(img->walking_path->instances + towindow, 2);
	}
	if (c == 'C')
		mlx_draw_texture(img->pickitup, tex->walking_path, 0, 0);
}

void	ft_load_wall(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image	*img;
	int			i;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	i = mlx_image_to_window(mlx, img->wall, x, y);
	tex->wall = mlx_load_png("png/wall.png");
	mlx_draw_texture(img->wall, tex->wall, 0, 0);
	mlx_set_instance_depth(img->wall->instances + i, 2);
	mlx_delete_texture(tex->wall);
}

void	ft_load_pickitup(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image	*img;
	int			i;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	i = mlx_image_to_window(mlx, img->pickitup, x, y);
	tex->pickitup = mlx_load_png("png/pickitup.png");
	mlx_draw_texture(img->pickitup, tex->pickitup, 0, 0);
	mlx_set_instance_depth(img->pickitup->instances + i, 3);
	mlx_delete_texture(tex->pickitup);
}

void	ft_load_exit(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image	*img;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	// if (end == 'V')
	// {
	// 	tex->end_screen = mlx_load_png("Art/victory.png");
	// 	img->end_screen = mlx_new_image(mlx, x, y);
	// 	mlx_image_to_window(mlx, img->end_screen, mlx->width / 2 - 190, 0);
	// 	mlx_draw_texture(img->end_screen, tex->end_screen, 0, 0);
	// 	mlx_set_instance_depth(img->end_screen->instances, 8);
	// 	mlx_delete_texture(tex->end_screen);
	// 	return ;
	// }
	mlx_image_to_window(mlx, img->exit, x, y);
	tex->exit = mlx_load_png("png/exit.png");
	mlx_draw_texture(img->exit, tex->exit, 0, 0);
	mlx_set_instance_depth(img->exit->instances, 4);
	mlx_delete_texture(tex->exit);
}

void	ft_load_player(mlx_t *mlx, int x, int y)
{
	t_texture	*tex;
	t_image	*img;
	int			i;

	tex = gset_tex(NULL);
	img = gset_img(NULL);
	i = mlx_image_to_window(mlx, img->player, x, y);
	tex->player = mlx_load_png("png/playerR.png");
	mlx_draw_texture(img->player, tex->player, 0, 0);
	mlx_set_instance_depth(img->player->instances + i, 3);
	mlx_delete_texture(tex->player);


}


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
	if (c =='\n')
		write(1, &c, 1);
	return (0);
}











void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}



























