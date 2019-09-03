/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_isascii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:05:48 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/03 09:05:54 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen_isascii(const char *s)
{
	size_t len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] && ft_isascii(s[len]))
		len++;
	return (len);
}
