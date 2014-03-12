/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 18:22:39 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/03 14:12:40 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void			affp(void)
{
	int			a;
	extern char	**environ;

	a = 0;
	while (ft_strcmpm("_=", environ[a]) != 1)
	{
		if (environ[a] != NULL)
		{
			ft_putstr(environ[a]);
			ft_putchar('\n');
		}
		a++;
	}
	ft_putstr(environ[a]);
	ft_putchar('\n');
}

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
	extern char	**environ;

	a = 0;
	i = 0;
	while (ft_strcmpm(srch, environ[a]) != 1)
		a = a + 1;
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
		path = ft_strsplit(str, ':');
	}
	return (path[a++]);
}
