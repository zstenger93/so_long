/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_to_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:04:00 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/11 13:04:25 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_moves_to_window(mlx_t *mlx, t_image *img)
{
	char	*moves;
	char	*text;
	
	moves = ft_itoa(img->move);
	text = ft_nm_strjoin("You moved: ", moves);
	mlx_put_string(mlx, text, 10, 5);
	free(text);
	free(moves);
}
