/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:06:35 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/12 16:47:16 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../so_long.h"
# include <time.h> // For clock()

/***********************************
	bonus
*************************************/
void	put_img2(t_g *game);
void	check_map_b(t_g *game, char *str);
void	prepare_game_b(t_g *game);
void	move_left_b(t_g *game);
void	move_right_b(t_g *game);
void	move_up_b(t_g *game);
void	move_down_b(t_g *game);
void	plus_initialize(t_g *stract);
void	draw_map_b(t_g *g);
int		game_loop(t_g *game);
#endif