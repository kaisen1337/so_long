/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:12:18 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/14 14:08:32 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	key1(int key, t_g *game)
{
	if (key == 65307)
		esc(game);
	if (key == LEFT && game->start == 1)
	{
		game->status = 0;
		move_left_b(game);
	}
	if (key == RIGHT && game->start == 1)
	{
		game->status = 1;
		move_right_b(game);
	}
	if (key == UP && game->start == 1)
		move_up_b(game);
	if (key == DOWN && game->start == 1)
		move_down_b(game);
	if (game->map_tcheck == 1 && game->start == 1)
		mlx_put_image_to_window(game->cnx, game->win, game->img_door2,
			game->x_door * PX, game->y_door * PX);
	if (game->stars_counter == 0 && game->map_tcheck == 0 && game->start == 1)
	{
		mlx_put_image_to_window(game->cnx, game->win, game->img_boom,
			game->x_door * PX, game->y_door * PX);
		game->map_tcheck = 1;
	}
}

static void	key2(int key, t_g *game)
{
	char	*buffer;

	if ((game->x_door == game->x_player) && (game->y_door == game->y_player))
		if (game->stars_counter == 0 && game->x_door != 0)
			esc(game);
	if ((key == LEFT || key == UP || key == RIGHT || key == DOWN)
		&& (game->start == 1))
	{
		mlx_put_image_to_window(game->cnx, game->win, game->img_wall, 0 * PX, 0
			* PX);
		buffer = ft_itoa(game->p_m_counter);
		mlx_string_put(game->cnx, game->win, 5, 20, 0xFFFF00, buffer);
		free(buffer);
	}
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
		mlx_set_font(game->cnx, game->win, "12x24");
		draw_map_b(game);
		mlx_hook(game->win, 2, 1L << 0, keys, game);
		mlx_hook(game->win, 17, 0, x_close, game);
		mlx_loop_hook(game->cnx, game_loop, game);
		game_loop(game);
	}
	return (0);
}

void	prepare_game_b(t_g *game)
{
	put_img(game);
	put_img2(game);
	mlx_set_font(game->cnx, game->win, "12x24");
	mlx_string_put(game->cnx, game->win, 400, 400, 0xFF0000, "Press Enter");
	mlx_string_put(game->cnx, game->win, 400, 440, 0xFF0000,
		"To Start The Game");
	mlx_put_image_to_window(game->cnx, game->win, game->img_start, 700, -50);
	mlx_hook(game->win, 3, 1L << 1, keys, game);
	mlx_hook(game->win, 2, 1L << 0, key_start, game);
	mlx_hook(game->win, 17, 0, x_close, game);
}
