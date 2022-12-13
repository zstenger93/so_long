/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:20:21 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/13 11:39:40 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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

char	ft_map_have_all_enemies(int fd, char n, char f, char b)
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
			if (ft_map_enemies_check(linecopy, &n, &f, &b) == 'I')
				return ('I');
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!f || !n || !b || f > 1 || n > 1 || b > 1)
		return ('L');
	return (0);
}

char	ft_map_enemies_check(char c, char *n, char *f, char *b)
{
	if (c == 'N')
		(*n)++;
	else if (c == 'F')
		(*f)++;
	else if (c == 'B')
		(*b)++;
	else if (c != '1' && c != '0' && c != '\n' && c != 'P' && c != 'E'
		&& c != 'C')
		return ('I');
	return (0);
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