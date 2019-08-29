/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:44:02 by zhelm             #+#    #+#             */
/*   Updated: 2019/07/12 14:08:04 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *s)
{
	// const char *str;
	// str = s;
	// while(*str)
	// 	++str;
	// return((str - s));
	size_t len;
	if(s == NULL)
		return 0;
	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}
