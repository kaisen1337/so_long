/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:39:25 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/14 14:10:38 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ch_map_element(t_g *g)
{
	int (i), j, p, c, e;
	1 && (i = 0, p = 0, c = 0, e = 0);
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P')
				(g->x_player = j) && (g->y_player = i) && p++;
			else if (g->map[i][j] == 'E')
				(g->x_door = j) && (g->y_door = i) && e++;
			else if (g->map[i][j] == 'C')
				(g->stars_counter += 1) && c++;
			else if (g->map[i][j] != '0' && g->map[i][j] != '1')
				exit((ft_printf("error\n"), ft_free(g->map), 1));
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 || c < 1)
		exit((ft_printf("error\n"), ft_free(g->map), 1));
}

void	check_map(t_g *game, char *str)
{
	check_extention(str);
	initialize(game);
	ch_map_shape(game, str);
	store_map(game, str);
	ch_map_border(game);
	ch_map_element(game);
	if (ch_player_path(game))
	{
		store_map(game, str);
		ch_map_element(game);
	}
}

int	main(int ac, char **av)
{
	t_g	game;

	if (ac == 2)
	{
		check_map(&game, av[1]);
		make_window(&game);
		prepare_game(&game);
		mlx_loop(game.cnx);
	}
	return (0);
}
