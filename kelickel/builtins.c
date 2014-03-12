/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 10:36:52 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/12 13:52:54 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
int	ft_env(char **arg);

int	ft_echo(char **cmd)
{
	if (ft_strcmp(cmd[0], "echo") == 0)
		return (0);
	if (ft_strcmp(cmd[1], "-n") == 0)
	{
		ft_putstr(cmd[1]);
		ft_putchar('\n');
	}
	else
		ft_putstr(cmd[2]);
	return (1);
}

int	ft_exit(char **cmd)
{
	if (ft_strcmp(cmd[0], "exit") == 0)
		return (0);
	exit(ft_atoi(cmd[1]));
}

int	ft_cd(char **cmd)
{
	char	buf[256];

	if (ft_strcmp(cmd[0], "cd") == 0)
		return (0);
	chdir(cmd[1]);
	getcwd(buf, 256);
	return (1);
}

int	ft_builtins(char **cmd)
{
	int		(*fct[4])(char **);
	int		i;
	int		b;

	i = 0;
	b = 0;
	fct[0] = ft_exit;
	fct[1] = ft_cd;
	fct[2] = ft_echo;
	fct[3] = ft_env;
	while(i < 4 && b == 0)
		b = fct[i++](cmd);
	return (b);
}
