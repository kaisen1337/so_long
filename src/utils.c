/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:18:08 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/12 16:27:22 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **str)
{
	int	i;

	if (!str || !str[0])
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	x_close(t_g *game)
{
	esc(game);
	return (0);
}

void	initialize(t_g *stract)
{
	stract->img_start = NULL;
	stract->cnx = NULL;
	stract->win = NULL;
	stract->img_player = NULL;
	stract->img_wall = NULL;
	stract->img_space = NULL;
	stract->img_stars = NULL;
	stract->img_door = NULL;
	stract->img_door2 = NULL;
	stract->img_boom = NULL;
	stract->map = NULL;
	stract->x_player = 0;
	stract->y_player = 0;
	stract->x_door = 0;
	stract->y_door = 0;
	stract->p_m_counter = 0;
	stract->stars_counter = 0;
	stract->img_width = 0;
	stract->img_height = 0;
	stract->map_width = 0;
	stract->map_height = 0;
	stract->map_tcheck = 0;
	stract->start = 0;
}
