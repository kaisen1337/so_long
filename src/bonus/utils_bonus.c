/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:46:39 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/14 12:39:55 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img2(t_g *game)
{
	char *(p_frame1), *p_frame2, *p_frame3, *p_frame4, *enemy;
	p_frame1 = "./textures/Player/frame1.xpm";
	p_frame2 = "./textures/Player/frame2.xpm";
	p_frame3 = "./textures/Player/frame3.xpm";
	p_frame4 = "./textures/Player/frame4.xpm";
	enemy = "./textures/0b.xpm";
	game->frame1 = mlx_xpm_file_to_image(game->cnx, p_frame1, &game->img_width,
			&game->img_height);
	game->frame2 = mlx_xpm_file_to_image(game->cnx, p_frame2, &game->img_width,
			&game->img_height);
	game->frame3 = mlx_xpm_file_to_image(game->cnx, p_frame3, &game->img_width,
			&game->img_height);
	game->frame4 = mlx_xpm_file_to_image(game->cnx, p_frame4, &game->img_width,
			&game->img_height);
	game->img_enemy = mlx_xpm_file_to_image(game->cnx, enemy, &game->img_width,
			&game->img_height);
}

void	plus_initialize(t_g *stract)
{
	stract->frame = 0;
	stract->status = 0;
	stract->img_enemy = NULL;
}
