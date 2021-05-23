#include "libft.h"
#include <limits.h>
#include <stdio.h>

long	ft_atol(const char *str)
{
	int					sign;
	long				res;
	int					i;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (res > INT_MAX || res * sign < INT_MIN || ft_strlen(str) > 19)
	{
		ft_putendl_fd("\033[1;31mError\033[0m", 2);
    	exit (1);
	}
	return (res * sign);
}