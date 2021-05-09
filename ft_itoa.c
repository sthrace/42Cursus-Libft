#include "libft.h"

static int	ft_nbrlen(unsigned int n)
{
	unsigned int	len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*output;
	int				len;
	int				i;
	int				sign;

	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	len = ft_nbrlen(n) + sign;
	i = 0;
	output = (char *)malloc(sizeof(char) * (len + 1 + sign));
	if (output == NULL)
		return (NULL);
	i = len - 1;
	while (n >= 10)
	{
		output[i--] = (char)(n % 10 + 48);
		n = n / 10;
	}
	output[i] = (char)(n % 10 + 48);
	output[len + sign] = '\0';
	return (output);
}
