#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*tmp;

	tmp = s;
	i = ft_strlen(s);
	s = (s + i);
	while (*s != *tmp && (char)c != *s)
		s--;
	if (c == *s)
		return ((char *)s);
	return (0);
}
