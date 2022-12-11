/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_to_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:04:00 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/11 17:30:16 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_moves_to_window(mlx_t *mlx)
{
	char	*moves;
	char	*text;
	t_image *img;
	static mlx_image_t	*tmp;

	
	mlx_delete_image(mlx, tmp);
	img = gset_img(NULL);
	moves = ft_itoa(img->move->count);
	text = ft_nm_strjoin("Your moves: ", moves);
	tmp = mlx_put_string(mlx, text, 10, 5);
	free(text);
	text = NULL;
	free(moves);
	moves = NULL;
}
