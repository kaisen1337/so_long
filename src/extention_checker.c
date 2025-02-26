/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:12:29 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/14 14:10:02 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strrchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}

static int	ft_strcmp(char *s, char *z)
{
	int	i;

	i = 0;
	while (s[i] && z[i])
	{
		if (s[i] != z[i])
			return (s[i] - z[i]);
		i++;
	}
	return (0);
}

static int	ch_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			if (str[i - 1] == '/')
				return (1);
		i++;
	}
	return (0);
}

void	check_extention(char *str)
{
	char	*ext;
	char	*str_ext;

	ext = ".ber";
	str_ext = ft_strrchr(str, '.');
	if (!str_ext || ft_strlen(str_ext) != ft_strlen(ext))
		exit((ft_printf("error\n"), 1));
	if (ft_strcmp(ext, str_ext) != 0)
		exit((ft_printf("error\n"), 1));
	if (ch_name(str))
		exit((ft_printf("error\n"), 1));
	if ((ft_strlen(str) - 4) == 0)
		exit((ft_printf("error\n"), 1));
}
