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