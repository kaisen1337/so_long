/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:07:46 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/14 14:16:35 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(t_g *g, int y, int x)
{
	if (y < 0 || x < 0 || y >= g->map_height || x >= g->map_width)
		return ;
	if (g->map[y][x] == '1' || g->map[y][x] == 'A' || g->map[y][x] == 'X')
		return ;
	g->map[y][x] = 'A';
	fill(g, y - 1, x);
	fill(g, y + 1, x);
	fill(g, y, x - 1);
	fill(g, y, x + 1);
}

int	ch_player_path(t_g *g)
{
	int (y), x;
	fill(g, g->y_player, g->x_player);
	y = 0;
	while (y < g->map_height)
	{
		x = 0;
		while (x < g->map_width)
		{
			if (g->map[y][x] == 'C' || g->map[y][x] == 'E')
				exit((ft_printf("error\n"), ft_free(g->map), 1));
			x++;
		}
		y++;
	}
	g->stars_counter = 0;
	ft_free(g->map);
	return (1);
}
