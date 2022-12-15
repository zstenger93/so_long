/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:02:46 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/15 10:24:23 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// looks for player position row by row
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

// checks if there is still E or C on the map
char	ft_dfs_check(char **map, size_t x, size_t y, size_t rows)
{
	size_t	i;

	if (ft_dfs(map, x, y, rows) == 'V')
		return ('V');
	i = 0;
	while (i < rows)
	{
		if ((!ft_pf_strchr(map[i], 'C')) == false)
			return ('Q');
		else if (ft_pf_strchr(map[i], 'E'))
			return ('V');
		i++;
	}
	return (0);
}

//depth first search, replacing everything on the map with X which isn't a wall
int	ft_dfs(char **map, size_t x, size_t y, size_t rows)
{
	if (x < 1 || y < 1 || x >= ft_strlen(*map) || y > rows
		|| map[y][x] == 'X' || map[y][x] == '1')
		return ('V');
	map[y][x] = 'X';
	ft_dfs(map, x - 1, y, rows);
	ft_dfs(map, x + 1, y, rows);
	ft_dfs(map, x, y - 1, rows);
	ft_dfs(map, x, y + 1, rows);
	return (0);
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

char	ft_move_and_count(mlx_t *mlx, t_image *img)
{
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		img->move->count++;
		ft_printf("Moves:%i Pixels moved: %d\n",
			img->move->count, img->move->count * 4);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		img->move->count++;
		ft_printf("Moves:%i Pixels moved: %d\n",
			img->move->count, img->move->count * 4);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		img->move->count++;
		ft_printf("Moves:%i Pixels moved: %d\n",
			img->move->count, img->move->count * 4);
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		img->move->count++;
		ft_printf("Moves:%i Pixels moved: %d\n",
			img->move->count, img->move->count * 4);
	}
	return (0);
}
