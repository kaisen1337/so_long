/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:38:59 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/14 14:07:26 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_helper(t_g *g, int y, int x)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->cnx, g->win, g->img_wall, x * PX, y * PX);
	else if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->cnx, g->win, g->img_space, x * PX, y * PX);
	else if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->cnx, g->win, g->img_player, x * PX, y * PX);
	else if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->cnx, g->win, g->img_stars, x * PX, y * PX);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->cnx, g->win, g->img_door, x * PX, y * PX);
}

void	draw_map_b(t_g *g)
{
	int (x), y = 0;
	while (y < g->map_height)
	{
		x = 0;
		while (x < g->map_width)
		{
			if (g->map[y][x] == 'X')
				mlx_put_image_to_window(g->cnx, g->win, g->img_enemy, x * PX, y
					* PX);
			else
				ft_helper(g, y, x);
			x++;
		}
		y++;
	}
}
