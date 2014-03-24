/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 10:36:52 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/22 20:35:08 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int	ft_echo(char **cmd)
{
	if (ft_strcmp(cmd[0], "echo") == 0)
		return (0);
	if (ft_strcmp(cmd[1], "-n") == 0)
	{
		if (cmd[1][0] != '$')
			ft_putstr(cmd[1]);
		else
			ft_putstr(ft_getenv(cmd[1] + 1));
		ft_putchar('\n');
	}
	else
	{
		if (cmd[2][0] != '$')
			ft_putstr(cmd[2]);
		else
			ft_putstr(ft_getenv(cmd[2] + 1));
	}
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
	char	buf[512];
	char	**ch_env;
	char	*to_move;

	if (ft_strcmp(cmd[0], "cd") == 0)
		return (0);
	ch_env = (char **)malloc(sizeof(char *) * 3);
	ch_env[0] = ft_strdup("setenv");
	ch_env[1] = ft_strdup("OLDPWD");
	ch_env[2] = getcwd(buf, 511);
	if (cmd[1] == 0)
		to_move = ft_getenv("HOME");
	else if (ft_strcmp(cmd[1], "-") == 1)
		to_move = ft_getenv("OLDPWD");
	else
		to_move = cmd[1];
	ft_putstr(to_move);
	ft_putstr("\n");
	if (chdir(to_move) == 0)
	{
		ft_setenv(ch_env);
		ch_env[1] = ft_strdup("PWD");
		ch_env[2] = getcwd(buf, 256);
		ft_setenv(ch_env);
		return (1);
	}
	return (0);
}

int	ft_builtins(char **cmd)
{
	int		(*fct[6])(char **);
	int		i;
	int		b;

	i = 0;
	b = 0;
	fct[0] = ft_exit;
	fct[1] = ft_cd;
	fct[2] = ft_echo;
	fct[3] = ft_env;
	fct[4] = ft_setenv;
	fct[5] = ft_unsetenv;
	while(i < 6 && b == 0)
		b = fct[i++](cmd);
	return (b);
}
