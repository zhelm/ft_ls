/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 07:53:13 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/12 10:53:24 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*st_strstart(const char *s, char c, size_t n)
{
	char *src;

	src = (char *)s;
	while (*src)
	{
		while (*src == c)
			src++;
		if (*src != c && n != 0)
			n--;
		else if (n == 0)
			return (src);
		while (*src != c)
			src++;
	}
	return (0);
}

static size_t	st_countstrlen(char const *s, char c, size_t n)
{
	size_t i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (n != 0)
			n--;
		else if (n == 0)
		{
			while (*s != c && *s)
			{
				s++;
				i++;
			}
			return (i);
		}
		while (*s != c)
			s++;
	}
	return (0);
}

static size_t	st_countstr(char const *s, char c)
{
	size_t i;
	size_t count;

	count = 0;
	i = 0;
	while (*s)
	{
		if (*s == c && i == 1)
			i = 0;
		else if (*s != c)
		{
			if (i == 0)
			{
				i = 1;
				count++;
			}
		}
		s++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (!s || !c)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (st_countstr(s, c) + 1));
	if (array == NULL)
		return (NULL);
	while (a < st_countstr(s, c))
	{
		b = 0;
		array[a] = (char *)malloc(sizeof(char) * st_countstrlen(s, c, a) + 2);
		while (*(st_strstart(s, c, a) + b) != c && *(st_strstart(s, c, a) + b))
		{
			array[a][b] = *(st_strstart(s, c, a) + b);
			b++;
		}
		array[a][b] = '\0';
		a++;
	}
	array[a] = NULL;
	return (array);
}
