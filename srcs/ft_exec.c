/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 10:22:08 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/27 22:21:17 by kelickel         ###   ########.fr       */
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
	char		*x;

	g_check_exec = 1;
	execve(arg[0], arg, env);
	str = (char *)1;
	while (str)
	{
		str = ft_path();
		if (str == 0)
		{
			ft_putstr_fd("$: Command not found: ", 2);
			ft_putstr_fd(arg[0], 2);
			write(2, "\n", 1);
			g_check_exec = 0;
			exit(-1);
		}
		x = ft_strnew(ft_strlen(str) + ft_strlen(arg[0]) + 2);
		ft_strcat(x, str);
		ft_strcat(x, "/");
		ft_strcat(x, arg[0]);
		execve(x, arg, env);
	}
	exit (-1);
}
