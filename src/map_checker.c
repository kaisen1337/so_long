/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:12:18 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/15 12:02:51 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ch_map_shape(t_g *g, char *map)
{
	int		fd;
	char	*line;
	size_t	width;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit((ft_printf("error\n"), 1));
	line = get_next_line(fd);
	if (!line)
		exit((ft_printf("error\n"), close(fd), 1));
	width = ft_strlen(line);
	while (line)
	{
		g->map_height++;
		if (width != ft_strlen(line))
			exit((ft_printf("error\n"), close(fd), free(line), 1));
		free(line);
		line = get_next_line(fd);
	}
	g->map_width = width;
	close(fd);
}

void	store_map(t_g *g, char *str)
{
	char	*line;

	int (i), fd;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return ;
	g->map = malloc((g->map_height + 1) * sizeof(char *));
	if (!g->map)
		exit((ft_printf("error\n"), close(fd), 1));
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		g->map[i] = ft_strdup(line);
		free(line);
		if (!g->map[i])
			exit((ft_printf("error\n"), close(fd), ft_free(g->map), 1));
		line = get_next_line(fd);
		i++;
	}
	g->map[i] = NULL;
	close(fd);
}

void	ch_map_border(t_g *g)
{
	int (i), last;
	i = 0;
	while (g->map[i])
		i++;
	last = i - 1;
	i = 0;
	while (g->map[0][i] && g->map[last][i])
	{
		if (g->map[0][i] != '1' || g->map[last][i] != '1')
			exit((ft_printf("error\n"), ft_free(g->map), 1));
		i++;
	}
	i = 0;
	while (g->map[i])
	{
		if (g->map[i][0] != '1' || g->map[i][ft_strlen(g->map[i]) - 1] != '1')
			exit((ft_printf("error\n"), ft_free(g->map), 1));
		i++;
	}
}

void	make_window(t_g *game)
{
	int (x), y;
	x = 0;
	y = 0;
	game->cnx = mlx_init();
	if (!game->cnx)
	{
		printf("Eroor the cnx failed!");
		exit(1);
	}
	mlx_get_screen_size(game->cnx, &x, &y);
	game->win = mlx_new_window(game->cnx, x, y, "Spider1337");
	if (!game->win)
	{
		printf("Eroor the window flailed!");
		exit(1);
	}
	mlx_set_font(game->cnx, game->win, "12x24");
}

void	put_img(t_g *game)
{
	char *(player), *wall, *space, *star, *door1, *boom, *door, *start;
	player = "./textures/Player/spider.xpm";
	wall = "./textures/net1.xpm";
	space = "./textures/space.xpm";
	star = "./textures/st.xpm";
	door1 = "./textures/closed.xpm";
	boom = "./textures/boom.xpm";
	door = "./textures/gate.xpm";
	start = "./textures/001.xpm";
	game->img_player = mlx_xpm_file_to_image(game->cnx, player,
			&game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->cnx, wall, &game->img_width,
			&game->img_height);
	game->img_space = mlx_xpm_file_to_image(game->cnx, space, &game->img_width,
			&game->img_height);
	game->img_stars = mlx_xpm_file_to_image(game->cnx, star, &game->img_width,
			&game->img_height);
	game->img_door = mlx_xpm_file_to_image(game->cnx, door1, &game->img_width,
			&game->img_height);
	game->img_boom = mlx_xpm_file_to_image(game->cnx, boom, &game->img_width,
			&game->img_height);
	game->img_door2 = mlx_xpm_file_to_image(game->cnx, door, &game->img_width,
			&game->img_height);
	game->img_start = mlx_xpm_file_to_image(game->cnx, start, &game->img_width,
			&game->img_height);
}
