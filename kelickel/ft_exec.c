/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 10:22:08 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/22 20:17:12 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int				ft_exec(char **env, char **arg)
{
	return (ft_execenv(env, arg));
}

int				ft_execenv(char **env, char **arg)
{
	char		*str;
	int			a;
	char		*x;

	check_exec = 1;
	execve(arg[0], arg, env);
	a = 0;
	while (a < 8)
	{
		str = ft_path();
		if (str == 0)
		{
			ft_putstr("$: Command not found: ");
			ft_putstr(arg[0]);
			ft_putchar('\n');
			check_exec = 0;
			exit(-1);
		}
		x = ft_strnew(ft_strlen(str) + ft_strlen(arg[0]) + 2);
		ft_strcat(x, str);
		ft_strcat(x, "/");
		ft_strcat(x, arg[0]);
		execve(x, arg, env);
		a = a + 1;
	}
	exit (-1);
}
