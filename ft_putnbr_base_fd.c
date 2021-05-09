#include "libft.h"

void	ft_putnbr_base_fd(long long nbr, int base, char *ascii, int fd)
{
	if (nbr >= base)
		ft_putnbr_base_fd(nbr / base, base, ascii, fd);
	write(fd, &ascii[nbr % base], 1);
}
