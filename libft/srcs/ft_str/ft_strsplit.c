/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:46:09 by cheron            #+#    #+#             */
/*   Updated: 2014/01/21 14:56:55 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_ntosplit(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
			if (s[i] != c)
		{
			n++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		i++;
	}
	return (n);
}

static void		ft_tabdel(char **tab, int j)
{
	while (j > 0)
	{
		free(tab[j - 1]);
		tab[j - 1] = NULL;
		j--;
	}
	free(tab);
	tab = NULL;
}

static char		**ft_iterative_split(char const *s, char **tab, char c)
{
	size_t	i;
	size_t	len;
	size_t	start;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		len = i - start;
		if ((tab[j] = ft_strsub(s, start, len)) == NULL)
		{
			ft_tabdel(tab, j);
			return (NULL);
		}
		if (len > 0)
			j++;
	}
	tab[j] = '\0';
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
		tab = (char**) malloc(sizeof(char *) * (ft_ntosplit(s, c) + 1));
		if (!tab)
			return (NULL);
		if ((tab = ft_iterative_split(s, tab, c)) == NULL)
			return (NULL);
		return (tab);
}
