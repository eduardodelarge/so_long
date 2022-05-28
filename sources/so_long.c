/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:56:03 by caeduard          #+#    #+#             */
/*   Updated: 2022/02/01 06:17:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strstr(char *str, char *str_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str_find[j] && str_find[j] == str[i + j])
		{
			j++;
		}
		if (str_find[j] == '\0')
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}

static int	argv_checker(char *argv)
{
	if (ft_strstr(argv, ".ber") == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (map_checker(&game) && argv_checker(argv[1]))
		{
			game_init(&game);
			gameplay(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			if (game.map)
				free_map(game.map);
			printf("Error\nInvalid Map");
			exit(1);
		}
	}
	else
	{
		printf("Error\nInvalid Sytax");
		exit(1);
	}
	return (0);
}
