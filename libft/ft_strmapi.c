/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 07:47:45 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/12 11:02:48 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*n;

	if (!s || !f)
		return (NULL);
	i = 0;
	n = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (n == NULL)
		return (NULL);
	while (s[i])
	{
		n[i] = f((unsigned int)i, s[i]);
		i++;
	}
	n[i] = '\0';
	return (n);
}
