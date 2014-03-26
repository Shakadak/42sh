/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 18:22:39 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/26 17:54:04 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_sh.h"

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
	if (g_environ[0] == 0)
		return (0);
	while (ft_strcmpm(srch, g_environ[a]) != 1)
	{
		a = a + 1;
		if (g_environ[a] == 0)
			return (0);
	}
	while (g_environ[a][i] != '=')
		i = i + 1;
	return (g_environ[a] + i + 1);
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
