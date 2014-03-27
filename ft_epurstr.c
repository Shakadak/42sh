/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epurstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 13:57:31 by kelickel          #+#    #+#             */
/*   Updated: 2014/02/07 12:18:06 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		middle(char *str)
{
	int	a;
	int	b;

	a = 0;
	while (str[a] == ' ' || str[a] == '\t' || str[a] == '\r')
		a++;
	if (str[a] == 0)
		return (0);
	b = 0;
	while (str[a] != 0)
	{
		if (str[a] == ' ' || str[a] == '\t' || str[a] == '\r')
		{
			while (str[a] == ' ' || str[a] == '\t' || str[a] == '\r')
						a++;
		}
		else
			a++;
		b++;
	}
	return (b);
}

char	*ft_epur(char *str)
{
	char	*epur;
	int		size;
	int		a;
	int		b;

	a = 0;
	b = 0;
	size = middle(str);
	if (size == 0)
		return (0);
	epur = malloc(sizeof(char) * (size + 1));
	while (str[a] == ' ' || str[a] == '\t' || str[a] == '\r')
		a++;
	while (str[a] != 0)
	{
		if (str[a] == ' ')
		{
			epur[b++] = str[a++];
			while (str[a] == ' ' || str[a] == '\t' || str[a] == '\r')
						a++;
		}
		epur[b++] = str[a++];
	}
	epur[b] = '\0';
	return (epur);
}
