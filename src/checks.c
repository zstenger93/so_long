/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:18:07 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/02 11:34:17 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
check for position
check for wall
check for collectible
check for exit
*/

char	error_type(char *argv)
{
	char	type;

	type = map_validator(argv);
	if (type == 'i')
		ft_printf("Error\nInvalid character in the map.\nValid characters are 0, 1, C, E\n");
	else if (type == 'V')
		ft_printf("Error\nThe map cannot be finished, no valid path to the exit.");
	else if (type == 'N')
		ft_printf("Error\nSomething wrong with malloc or malloc failed.");
	else if (type == '1')
		ft_printf("Error\nThe map must be surrounded by walls('1').");
	else if (type == 'R')
		ft_printf("Error\nMap must be rectangular.");
	else if (type == 'M')
		ft_printf("Error\nMap must contain 'P', 'E' and 'C'.");
	else if (type == 'T')
		ft_printf("Error\nOnly one exit and one player is accepted.");
	else
		return (0);
	return (1);
}