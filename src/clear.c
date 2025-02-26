/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:47:55 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/12 16:27:22 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_clear_img(t_g *game)
{
	if (game->img_player)
		mlx_destroy_image(game->cnx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->cnx, game->img_wall);
	if (game->img_stars)
		mlx_destroy_image(game->cnx, game->img_stars);
	if (game->img_space)
		mlx_destroy_image(game->cnx, game->img_space);
	if (game->img_door)
		mlx_destroy_image(game->cnx, game->img_door);
	if (game->img_door2)
		mlx_destroy_image(game->cnx, game->img_door2);
	if (game->img_boom)
		mlx_destroy_image(game->cnx, game->img_boom);
	if (game->img_start)
		mlx_destroy_image(game->cnx, game->img_start);
}

void	esc(t_g *game)
{
	ft_free(game->map);
	if (game->win != NULL)
		mlx_destroy_window(game->cnx, game->win);
	ft_clear_img(game);
	if (game->cnx)
		mlx_destroy_display(game->cnx);
	if (game->cnx)
		free(game->cnx);
	exit(0);
}
