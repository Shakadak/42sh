/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:39:01 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/26 01:01:12 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			nbr_word(char const *s, char c)
{
	int	i;
	int	b;

	i = 0;
	b = 1;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			b = b + 1;
			while (s[i] == c)
				i = i + 1;
		}
		else
			i = i + 1;
	}
	return (b);
}

int			sizeword(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] == c)
		i = i + 1;
	while (s[i] != c && s[i] != 0)
	{
		i = i + 1;
		size = size + 1;
		if (s[i] == 0)
			return (size);
	}
	while (s[i] == c)
	{
		i = i + 1;
	}
	return (size);
}

char		*instr(char const *s, char c, int *i, char *str)
{
	int	e;

	e = 0;
	while (s[*i] == c)
	{
		*i = *i + 1;
	}
	while (s[*i] != c && s[*i] != 0)
	{
		str[e] = s[*i];
		e = e + 1;
		*i = *i + 1;
	}
	str[e] = '\0';
	while (s[*i] == c)
	{
		*i = *i + 1;
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		nbr_wrd;
	int		i;
	int		a;

	if (s == 0)
		return (0);
	i = 0;
	a = 0;
	nbr_wrd = nbr_word(s, c);
	str = malloc(sizeof(char *) * nbr_wrd + 2);
	if (s == 0)
	{
		str[0] = NULL;
		return (str);
	}
	while (s[i] != 0)
	{
		str[a] = malloc(sizeof(char) * sizeword(s, c, i) + 1);
		instr(s, c, &i, str[a]);
		a++;
	}
	str[a] = NULL;
	return (str);
}
