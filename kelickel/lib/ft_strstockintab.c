/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstockintab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 21:38:50 by croy              #+#    #+#             */
/*   Updated: 2014/03/26 17:53:09 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_sh.h"


static void		dupl(char *str, char *dup, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			dup[j] = str[i];
			j++;
		}
		i++;
	}
	dup[i] = '\0';
}

char		*epur_str(char *str, char c)
{
	int		i;
	int		j;
	int		count;
	char	*dup;

	count = i = j = 0;
	while (str[i])
	{
		if (str[i] != c)
			count++;
		i++;
	}
	dup = malloc(sizeof(char) * count + 1);
	i = 0;
	dupl(str, dup, c);
	return (dup);
}

char		**ft_strsplit_r(char *str)
{
	char	**tab;
	char	*cpy;
	char	*fcpy;

	cpy = epur_str(str, '"');
	fcpy = epur_str(cpy, '\t');
	free(cpy);
	tab = ft_strsplit(fcpy, ' ');
	free(fcpy);
	return (tab);
}
