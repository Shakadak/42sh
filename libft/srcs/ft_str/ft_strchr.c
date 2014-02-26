/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:42:56 by npineau           #+#    #+#             */
/*   Updated: 2013/12/15 12:05:37 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*ft_strchr(const char *src, int c)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (src[l] != '\0')
		l++;
	if (c == 0)
		return ((char *)&src[l]);
	while (i < l)
	{
		if (src[i] == c)
			return ((char *)&src[i]);
		i++;
	}
	return (NULL);
}
