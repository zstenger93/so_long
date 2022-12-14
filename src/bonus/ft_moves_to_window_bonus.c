/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_to_window_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:04:00 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/13 11:39:01 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	ft_moves_to_window(mlx_t *mlx)
{
	char				*moves;
	char				*text;
	t_image				*img;
	static mlx_image_t	*tmp;

	mlx_delete_image(mlx, tmp);
	img = null_set_img(NULL);
	moves = ft_itoa(img->move->count);
	text = ft_nm_strjoin("Moves: ", moves);
	tmp = mlx_put_string(mlx, text, 0, 0);
	if (img->player->enabled == false)
		mlx_delete_image(mlx, tmp);
	free(text);
	text = NULL;
	free(moves);
	moves = NULL;
}
