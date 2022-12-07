/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:02:46 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/07 19:43:57 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		|| map[y][x] == '1' || map[y][x] == 'N' || map[y][x] == 'F')
		return ('V');
	if (map[y][x] == 'E')
		return (0);
	map[y][x] = '1';
	if (ft_dfs(map, x - 1, y, rows) == 0
		|| ft_dfs(map, x + 1, y, rows) == 0
		|| ft_dfs(map, x, y - 1, rows) == 0
		|| ft_dfs(map, x, y + 1, rows) == 0)
		return (0);
	else
		return ('V');
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
