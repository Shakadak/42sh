/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:15:29 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/25 10:08:40 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_env(char	**arg)
{
	int	i;

	if (ft_strcmp(arg[0], "env") == 0)
		return (0);
	if (ft_strcmp(arg[1], "-i") == 1)
		return (1);
	i = 0;
	while (environ[i] != 0)
	{
		ft_putstr(environ[i++]);
		ft_putstr("\n");
	}
	return (1);
}

int		ft_unsetenv(char **str)
{
	int	i;

	if (ft_strcmp(str[0], "unsetenv") == 0)
		return (0);
	i = 0;
	while (ft_strcmpm(environ[i], str[1]) == 0 && environ[i])
		i++;
	while (environ[i])
	{
		environ[i] = environ[i + 1];
		i++;
	}
	return (1);
}

int		ft_setenv(char **str)
{
	int	i;
	char	*inside;

	if (ft_strcmp(str[0], "setenv") == 0)
		return (0);
	if (str[1] == 0 || str[2] == 0)
	{
		ft_putstr("invalid arg of fuction setenv\n");
		return (1);
	}
	inside = malloc(sizeof(char) * (ft_strlen(str[1]) + ft_strlen(str[2]) + 2));
	i = 0;
	ft_strcat(inside, str[1]);
	ft_strcat(inside, "=");
	ft_strcat(inside, str[2]);
	while (environ[i] != 0 && ft_strcmpm(environ[i], str[1]) == 0)
		i++;
	if (environ[i] == 0)
	{
		environ[i] = inside;
		environ[++i] = 0;
	}
	else
		environ[i] = inside;
	return (1);
}
