#include "libft.h"

static int	ft_read(char buff, int fd, int *value)
{
	*value = read(fd, &buff, 1);
	return (*value);
}

int	ft_gnl(int fd, char **line)
{
	char		buff;
	int			value;

	buff = 0;
	*line = (char *)malloc(1);
	if (*line == NULL || !fd || !(*line))
		return (-1);
	*line[0] = '\0';
	while (ft_read(buff, fd, &value) > 0)
	{
		if (buff == '\n')
			break ;
		*line = ft_charjoin(*line, buff);
	}
	return (value);
}
