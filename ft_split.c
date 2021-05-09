#include "libft.h"

static size_t	ft_len(char const *s, char c, int type)
{
	size_t		wdcnt;
	size_t		i;

	i = 0;
	if (type == 1)
	{
		wdcnt = 0;
		while (s[i] != '\0')
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i] && s[i] != c)
				wdcnt++;
			while (s[i] && s[i] != c)
				i++;
		}
		return (wdcnt);
	}
	if (type == 2)
	{
		while (s[i] && s[i] != c)
			i++;
		return (i);
	}
	return (0);
}

static void	ft_free(char **s, int c)
{
	while (c)
	{
		free(s[c]);
		c--;
	}
	free(s);
}

static char	*ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		*splitstr;

	i = 0;
	j = 0;
	splitstr = (char *)malloc(sizeof(char) * (ft_len(s, c, 2) + 1));
	if (splitstr == NULL)
		return (NULL);
	while (s[i] && s[i] != c)
		splitstr[j++] = s[i++];
	splitstr[j] = '\0';
	return (splitstr);
}

static void	ft_helper(char ***split, size_t *i, char const *s, char c)
{
	*split[*i] = ft_strsplit(s, c);
	if (*split[*i] == NULL)
		ft_free(*split, *i - 1);
	*i += 1;
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		wdcnt;
	char		**split;

	i = 0;
	if (!s)
		return (NULL);
	wdcnt = ft_len(s, c, 1);
	split = (char **)malloc(sizeof(char *) * (wdcnt + 1));
	if (split == NULL)
		return (NULL);
	while (i < wdcnt)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			ft_helper(&split, &i, s, c);
			while (*s && *s != c)
				s++;
		}
	}
	split[i] = NULL;
	return (split);
}
