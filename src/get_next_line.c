/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 05:01:21 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/03 20:11:36 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_join(int fd, char *text, char *buffer)
{
	int		len;
	char	*tempo;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (!serch_new_line(text))
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buffer[len] = '\0';
		tempo = text;
		text = ft_strjoin(tempo, buffer);
		free(tempo);
		if (!text)
			return (NULL);
	}
	return (text);
}

char	*ft_read_text(int fd, char *text)
{
	char	*buffer;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!text)
		text = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	text = ft_read_join(fd, text, buffer);
	free(buffer);
	if (!text || (text[0] == '\0'))
	{
		free(text);
		return (NULL);
	}
	return (text);
}

char	*ft_our_line(char *the_complet_line)
{
	int		i;
	char	*line;

	i = 0;
	if (!the_complet_line)
		return (NULL);
	while (the_complet_line[i] != '\n' && the_complet_line[i] != '\0')
	{
		i++;
	}
	line = ft_substr(the_complet_line, 0, i);
	return (line);
}

char	*ft_the_rest_of_line(char *the_complet_line)
{
	int		k;
	size_t	len;
	char	*rest;

	k = 0;
	if (!the_complet_line)
		return (NULL);
	len = ft_strlen(the_complet_line);
	while (the_complet_line[k] != '\n' && the_complet_line[k] != '\0')
		k++;
	if (the_complet_line[k] == '\0' || k == (int)len - 1)
	{
		free(the_complet_line);
		return (NULL);
	}
	rest = ft_substr(the_complet_line, k + 1, len - k - 1);
	free(the_complet_line);
	if (!rest || rest[0] == '\0')
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*the_static_var;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	the_static_var = ft_read_text(fd, the_static_var);
	if (!the_static_var)
		return (NULL);
	line = ft_our_line(the_static_var);
	if (!line)
		return (NULL);
	the_static_var = ft_the_rest_of_line(the_static_var);
	return (line);
}
