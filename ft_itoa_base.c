#include "libft.h"

char	*ft_itoa_base(unsigned long long n, unsigned int base)
{
	char				*out;
	int					i;
	unsigned long long	nbr;

	nbr = n;
	i = ft_nbrlen_base(nbr, base);
	out = (char *)malloc(sizeof(char) * (i + 1));
	if (out == NULL)
		return (0);
	out[i + 1] = '\0';
	while (n >= base)
	{
		if (n % base < 10)
			out[i--] = (char)(n % base + 48);
		else
			out[i--] = (char)(n % base + 87);
		n = n / base;
	}
	if ((n == 0) || (n % base < 10))
		out[i] = (char)(n % base + 48);
	else
		out[i] = (char)(n % base + 87);
	return (out);
}
