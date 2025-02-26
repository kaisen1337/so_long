/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:06:35 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/15 12:58:20 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "/usr/include/minilibx-linux/mlx.h"
// # include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct t_g
{
	int		start;
	void	*cnx;
	void	*win;
	void	*img_player;
	void	*img_wall;
	void	*img_space;
	void	*img_stars;
	void	*img_start;
	void	*img_door;
	void	*img_door2;
	void	*img_boom;
	void	*img_enemy;
	char	**map;
	int		x_player;
	int		y_player;
	int		x_door;
	int		y_door;
	int		p_m_counter;
	int		stars_counter;
	int		img_width;
	int		img_height;
	int		map_width;
	int		map_height;
	int		map_tcheck;
	int		frame;
	int		status;
	void	*frame1;
	void	*frame2;
	void	*frame3;
	void	*frame4;
}			t_g;
/***********************************
 * Define macros
 *************************************/
# define PX 64
# define UP 65362
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
/***********************************
 * ft_printf
 *************************************/
int			ft_printf(const char *str, ...);

/***********************************
 * get next line functions
 *************************************/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
int			serch_new_line(char *str);
char		*get_next_line(int fd);

/***********************************
 * movement
 *************************************/
void		move_left(t_g *game);
void		move_right(t_g *game);
void		move_up(t_g *game);
void		move_down(t_g *game);
/***********************************
 * clear t_g
 *************************************/
void		initialize(t_g *stract);
void		check_extention(char *str);
void		ch_map_shape(t_g *g, char *map);
void		ch_map_border(t_g *g);
void		check_map(t_g *game, char *str);
int			ch_player_path(t_g *g);
void		store_map(t_g *g, char *str);
void		make_window(t_g *game);
void		put_img(t_g *game);
void		prepare_game(t_g *game);
void		draw_map(t_g *game);
void		ft_free(char **str);
/***********************************
 * close_window
 *************************************/
void		esc(t_g *game);
int			x_close(t_g *game);
char		*ft_itoa(int n);
#endif