/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 12:44:17 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/02/25 12:44:17 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsh.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*copy;

	i = 0;
	if (!len)
		return (NULL);
	if ((copy = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	copy[len] = '\0';
	while (i < len)
	{
		copy[i] = s[start + i];
		i++;
	}
	return (copy);
}
