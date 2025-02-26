/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:32:10 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/12 17:48:27 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	key1(int key, t_g *game)
{
	if (key == 65307)
		esc(game);
	if (key == LEFT && game->start == 1)
		move_left(game);
	if (key == RIGHT && game->start == 1)
		move_right(game);
	if (key == UP && game->start == 1)
		move_up(game);
	if (key == DOWN && game->start == 1)
		move_down(game);
	if (game->map_tcheck == 1 && game->start == 1)
		mlx_put_image_to_window(game->cnx, game->win, game->img_door2,
			game->x_door * PX, game->y_door * PX);
	if (game->stars_counter == 0 && game->map_tcheck == 0)
	{
		mlx_put_image_to_window(game->cnx, game->win, game->img_boom,
			game->x_door * PX, game->y_door * PX);
		game->map_tcheck = 1;
	}
}

static void	key2(int key, t_g *game)
{
	(void)key;
	if ((game->x_door == game->x_player) && (game->y_door == game->y_player))
		if (game->stars_counter == 0 && game->x_door != 0)
			esc(game);
}

static int	keys(int key, t_g *game)
{
	key1(key, game);
	key2(key, game);
	return (0);
}

static int	key_start(int key, t_g *game)
{
	if (key == 65293 && game->start == 0)
	{
		game->start = 1;
		mlx_clear_window(game->cnx, game->win);
		mlx_destroy_window(game->cnx, game->win);
		game->win = mlx_new_window(game->cnx, game->map_width * PX,
				game->map_height * PX, "Spider1337");
		draw_map(game);
		mlx_hook(game->win, 2, 1L << 0, keys, game);
		mlx_hook(game->win, 17, 0, x_close, game);
	}
	return (0);
}

void	prepare_game(t_g *game)
{
	put_img(game);
	mlx_string_put(game->cnx, game->win, 400, 400, 0xFF0000, "Press Enter");
	mlx_string_put(game->cnx, game->win, 400, 440, 0xFF0000,
		"To Start The Game");
	mlx_put_image_to_window(game->cnx, game->win, game->img_start, 700, -50);
	mlx_hook(game->win, 3, 1L << 1, keys, game);
	mlx_hook(game->win, 2, 1L << 0, key_start, game);
	mlx_hook(game->win, 17, 0, x_close, game);
}
