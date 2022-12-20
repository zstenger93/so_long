/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:10:04 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/20 10:42:25 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	ft_load_player(mlx_t *mlx, int x, int y, char keytype)
{
	t_texture	*tex;
	t_image		*img;

	tex = null_set_tex(NULL);
	img = null_set_img(NULL);
	if (keytype == 'W' || keytype == 'S' || keytype == 'A' || keytype == 'D')
		tex->player = mlx_load_png("png/player_r.png");
	else
	{
		tex->player = mlx_load_png("png/player_r.png");
		mlx_draw_texture(img->player, tex->player, 0, 0);
		mlx_image_to_window(mlx, img->player, x, y);
		mlx_set_instance_depth(img->player->instances, 8);
	}
	mlx_draw_texture(img->player, tex->player, 0, 0);
	mlx_delete_texture(tex->player);
	ft_player_location(img->pickitup, 'C');
	ft_player_location(img->exit, 'E');
	return (ft_player_location(img->wall, '1'));
}

void	ft_player_hook(void *mlx)
{
	t_image		*img;

	img = null_set_img(NULL);
	if (img->player->enabled == true)
	{
		ft_player_movement(mlx, img);
		ft_move_and_count(mlx, img);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

t_image	*null_set_img(t_image *img_to_null)
{
	static t_image	*img;

	if (img_to_null != NULL)
		img = img_to_null;
	return (img);
}

t_texture	*null_set_tex(t_texture *tex_to_null)
{
	static t_texture	*tex;

	if (tex_to_null != NULL)
		tex = tex_to_null;
	return (tex);
}

mlx_t	*null_set_mlx(mlx_t *mlx_to_null)
{
	static mlx_t	*mlx;

	if (mlx_to_null != NULL)
		mlx = mlx_to_null;
	return (mlx);
}

/*
ft_read_and_print_map(argv[1]);
void	ft_read_and_print_map(char *map)
{
	int		count;
	int		x;
	int		y;
	int		fd;
	char	*line;

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
			count ++;
		}
		free(line);
		line = get_next_line(fd);
	}
	write(1, "\n", 1);
	close(fd);
}

char	put_chars(char c)
{
	char	colored_0[] = "\e[1;37mO\e[0m";
	char	colored_1[] = "\e[1;31m1\e[0m";
	char	colored_c[] = "\e[1;33mC\e[0m";
	char	colored_p[] = "\e[1;32mP\e[0m";
	char	colored_e[] = "\e[1;35mE\e[0m";
	char	colored_f[] = "\e[1;34mF\e[0m";
	char	colored_n[] = "\e[1;34mN\e[0m";
	char	colored_b[] = "\e[1;34mB\e[0m";

	if (c == '0')
		write(1, &colored_0, 13);
	if (c == '1')
		write(1, &colored_1, 13);
	if (c == 'C')
		write(1, &colored_c, 13);
	if (c == 'E')
		write(1, &colored_e, 13);
	if (c == 'P')
		write(1, &colored_p, 13);
	if (c == 'F')
		write(1, &colored_f, 13);
	if (c == '\n')
		write(1, &c, 1);
	if (c == 'N')
		write(1, &colored_n, 13);
	if (c == 'B')
		write(1, &colored_b, 13);
	return (0);
}
*/
