/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:10:48 by nkasimi           #+#    #+#             */
/*   Updated: 2025/01/17 08:40:37 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[len] = '\0';
	return ((char *)ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*a;
	unsigned int	n;

	if (s == NULL)
		return (NULL);
	i = 0;
	n = ft_strlen(s);
	if (start >= n)
		return (ft_strdup(""));
	if (len > n - start)
		len = n - start;
	a = malloc(len + 1);
	if (!a)
		return (NULL);
	while (i < len)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	a = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * (sizeof(char)));
	if (!a)
		return (NULL);
	i = 0;
	while (i < (int)ft_strlen(s1))
	{
		a[i] = s1[i];
		i++;
	}
	k = 0;
	while (k < (int)ft_strlen(s2))
	{
		a[i] = s2[k];
		i++;
		k++;
	}
	a[i] = '\0';
	return (a);
}

int	serch_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
