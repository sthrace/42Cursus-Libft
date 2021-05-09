#include "libft.h"

int	ft_nbrlen_base(long long nbr, int base)
{
	int		i;

	i = 1;
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}
