/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:18:07 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/08 11:00:33 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	ft_wrong_input(int argc, char **argv)
{
	if (argc > 2 || ft_strstr(argv[1], ".ber") == false)
	{
		if (argc > 2)
			ft_printf("\e[4;31mError!\e[0m\n"
				"\e[1;4;34mToo many arguments!\e[0m\n");
		else
			ft_printf("\e[4;31mError!\e[0m\n"
				"\e[1;4;34mMaybe something missing? oH, yEs! A MAP!\e[0m\n");
		return (1);
	}	
	return (0);
}

char	ft_error_types(char *argv)
{
	char	error_type;

	error_type = ft_map_validator(argv);
	if (error_type == '1')
		ft_printf("\e[1;4;31mError!\e[0m\n"
			"\e[4;33mMap must be surrounded by walls!\e[0m\n");
	else if (error_type == 'M')
		ft_printf("\e[1;4;31mError!\e[0m\n"
			"\e[4;33mMap must contain P, E and C!\e[0m\n");
	else if (error_type == 'O')
		ft_printf("\e[1;4;31mError!\e[0m\n"
			"\e[4;33mThere is NO or MORE exit or/and player than one!\e[0m\n"
			"\e[4;33mElse you don't anything to collect on the map!\e[0m\n");
	else if (error_type == 'I')
		ft_printf("\e[1;4;31mError!\e[0m\n"
			"\e[4;33mInvalid char/'s in the map!\e[0m\n"
			"\e[1;4;34mValid chars: 0, 1, P, E, C, F and N.\e[0m\n");
	else if (ft_error_types2(argv) != 1)
	{
		ft_printf("\e[1;4;32mThe map is valid and ready to launch!\e[0m\n");
		return (0);
	}
	return (1);
}

char	ft_error_types2(char *argv)
{
	char	error_type;

	error_type = ft_map_validator(argv);
	if (error_type == 'V')
		ft_printf("\e[1;4;31mError!\e[0m\n"
			"\e[4;33mNo valid path to exit!\e[0m\n");
	else if (error_type == 'R')
		ft_printf("\e[1;4;31mError!\e[0m\n"
			"\e[4;33mMap must be rectangular!\e[0m\n");
	else if (error_type == 'A')
		ft_printf("\e[1;4;31mError!\e[0m\n"
			"\e[4;33mMemory allocation failed!\e[0m\n");
	else if (error_type == 'L')
		ft_printf("\e[1;4;31mError!\e[0m\n"
			"\e[4;33mCan't be more or less enemy per type than one!\e[0m\n");
	else
		return (0);
	return (1);
}
