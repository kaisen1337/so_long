/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 06:57:01 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/12 16:47:29 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	frame1(t_g *game)
{
	if (game->frame == 0)
		mlx_put_image_to_window(game->cnx, game->win, game->img_player,
			game->x_player * PX, game->y_player * PX);
	else
		mlx_put_image_to_window(game->cnx, game->win, game->frame1,
			game->x_player * PX, game->y_player * PX);
}

void	frame2(t_g *game)
{
	if (game->frame == 0)
		mlx_put_image_to_window(game->cnx, game->win, game->frame2,
			game->x_player * PX, game->y_player * PX);
	else
		mlx_put_image_to_window(game->cnx, game->win, game->frame3,
			game->x_player * PX, game->y_player * PX);
}

void	frame3(t_g *game)
{
	mlx_put_image_to_window(game->cnx, game->win, game->frame4, game->x_player
		* PX, game->y_player * PX);
	game->status = -1;
}

int	game_loop(t_g *game)
{
	static clock_t	last_update = 0;
	clock_t			current_time;

	current_time = clock();
	if (((current_time - last_update) * 1000 / CLOCKS_PER_SEC) >= 400)
	{
		game->frame = (game->frame + 1) % 2;
		if (game->status == 3)
			frame3(game);
		else if (game->status == 0)
			frame1(game);
		else if (game->status != 0)
			frame2(game);
		last_update = current_time;
	}
	return (0);
}
