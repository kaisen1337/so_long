/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:23:45 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/12 16:27:22 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	helper(t_g *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		game->stars_counter -= 1;
	game->p_m_counter += 1;
	game->map[game->y_player][game->x_player] = '0';
	mlx_put_image_to_window(game->cnx, game->win, game->img_space,
		game->x_player * PX, game->y_player * PX);
	if (game->map[y][x] == game->map[game->y_door][game->x_door])
	{
		game->map[y][x] = 'E';
		mlx_put_image_to_window(game->cnx, game->win, game->img_door,
			game->x_door * PX, game->y_door * PX);
	}
}

void	move_left(t_g *game)
{
	int	x;
	int	y;

	x = game->x_player - 1;
	y = game->y_player;
	if ((x <= 0) || (game->map[y][x] == '1'))
		return ;
	helper(game, x, y);
	game->x_player = x;
	game->map[game->y_player][game->x_player] = 'P';
	mlx_put_image_to_window(game->cnx, game->win, game->img_player,
		game->x_player * PX, game->y_player * PX);
	ft_printf("%d\n", game->p_m_counter);
}

void	move_right(t_g *game)
{
	int	x;
	int	y;

	x = game->x_player + 1;
	y = game->y_player;
	if ((x >= game->map_width) || (game->map[y][x] == '1'))
		return ;
	helper(game, x, y);
	game->x_player = x;
	game->map[game->y_player][game->x_player] = 'P';
	mlx_put_image_to_window(game->cnx, game->win, game->img_player,
		game->x_player * PX, game->y_player * PX);
	printf("%d\n", game->p_m_counter);
}

void	move_up(t_g *game)
{
	int	x;
	int	y;

	1 && (x = game->x_player), y = game->y_player - 1;
	if ((x >= game->map_width) || (game->map[y][x] == '1'))
		return ;
	helper(game, x, y);
	game->y_player = y;
	game->map[game->y_player][game->x_player] = 'P';
	mlx_put_image_to_window(game->cnx, game->win, game->img_player,
		game->x_player * PX, game->y_player * PX);
	printf("%d\n", game->p_m_counter);
}

void	move_down(t_g *game)
{
	int	x;
	int	y;

	x = game->x_player;
	y = game->y_player + 1;
	if (game->map[y][x] == '1')
		return ;
	helper(game, x, y);
	game->y_player = y;
	game->map[game->y_player][game->x_player] = 'P';
	mlx_put_image_to_window(game->cnx, game->win, game->img_player,
		game->x_player * PX, game->y_player * PX);
	printf("%d\n", game->p_m_counter);
}
