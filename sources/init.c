/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:15:12 by caeduard          #+#    #+#             */
/*   Updated: 2022/01/29 19:17:52 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_init(t_game *game)
{
	game->img_backg = mlx_xpm_file_to_image
		(game->mlx, "assets/images/0.xpm", &game->img_w, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "assets/images/1.xpm", &game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "assets/images/PD.xpm", &game->img_w, &game->img_h);
	game->img_colect = mlx_xpm_file_to_image
		(game->mlx, "assets/images/C.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, "assets/images/E1.xpm", &game->img_w, &game->img_h);
}

static void	size_window_init(t_game *game)
{
	int	i;

	game->map_w = ft_strlen(game->map[0]) * 64;
	i = 0;
	while (game->map[i])
		i++;
	game->map_h = i * 64;
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	size_window_init(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "zelda");
	game->moves = 0;
	game->endgame = 0;
	img_init(game);
	map_draw(game);
}
