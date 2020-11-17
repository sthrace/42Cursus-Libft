/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:00:14 by sthrace           #+#    #+#             */
/*   Updated: 2020/11/15 12:18:59 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
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
