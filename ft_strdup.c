#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, s1, ft_strlen(s1) + 1);
	return (dst);
}
