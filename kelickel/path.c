/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 18:22:39 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/25 10:30:01 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int				ft_strcmpm(char *one, char *two)
{
	int			a;

	if (one == 0 || two == 0)
		return (0);
	a = 0;
	while (one[a] != 0 && two[a] != 0)
	{
		if (one[a] != two[a])
			return (0);
		a = a + 1;
	}
	return (1);
}

char			*ft_getenv(char *srch)
{
	int			a;
	int			i;

	a = 0;
	i = 0;
	if (environ[0] == 0)
		return (0);
	while (ft_strcmpm(srch, environ[a]) != 1)
	{
		a = a + 1;
		if (environ[a] == 0)
			return (0);
	}
	while (environ[a][i] != '=')
		i = i + 1;
	return (environ[a] + i + 1);
}

char			*ft_path(void)
{
	static int	a;
	static char	*str;
	static char	**path;

	if (a == 0)
	{
		str = ft_getenv("PATH");
		if (str == 0)
			return (0);
		path = ft_strsplit(str, ':');
	}
	return (path[a++]);
}
