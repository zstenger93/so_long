/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:20:21 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/07 20:07:38 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_image	*gset_img(t_image *img_to_null)
{
	static t_image	*img;

	if (img_to_null != NULL)
		img = img_to_null;
	return (img);
}

t_texture	*gset_tex(t_texture *tex_to_null)
{
	static t_texture	*tex;

	if (tex_to_null != NULL)
		tex = tex_to_null;
	return (tex);
}

mlx_t	*gset_mlx(mlx_t *mlx_to_null)
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
	close(fd);
}

char	put_chars(char c)
{
	char colored0[] = "\e[1;37mO\e[0m";
	char colored1[] = "\e[1;31m1\e[0m";
	char coloredC[] = "\e[1;33mC\e[0m";
	char coloredP[] = "\e[1;32mP\e[0m";
	char coloredE[] = "\e[1;35mE\e[0m";
	char coloredF[] = "\e[1;34mF\e[0m";
	char coloredN[] = "\e[1;34mN\e[0m";

	if (c == '0')
		write(1, &colored0, 13);
	if (c == '1')
		write(1, &colored1, 13);
	if (c == 'C')
		write(1, &coloredC, 13);
	if (c == 'E')
		write(1, &coloredE, 13);
	if (c == 'P')
		write(1, &coloredP, 13);
	if (c == 'F')
		write(1, &coloredF, 13);
	if (c =='\n')
		write(1, &c, 1);
	if (c == 'N')
		write(1, &coloredN, 13);
	return (0);
}
*/
