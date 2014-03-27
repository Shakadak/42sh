/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 10:36:52 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/27 16:09:02 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_print_echo(char **cmd, int i, int opt)
{
	while (cmd[i] != 0)
	{
		if (cmd[i][0] != '$')
			ft_putstr(cmd[i]);
		else
			ft_putstr(ft_getenv(cmd[i] + 1));
		i++;
		if (cmd[i] != 0)
			ft_putchar(' ');
	}
	if (opt == 1)
		ft_putchar('\n');
	return ;
}

int		ft_echo(char **cmd)
{
	if (ft_strcmp(cmd[0], "echo") == 0)
		return (0);
	if (ft_strcmp(cmd[1], "-n") == 0)
		ft_print_echo(cmd, 1, 1);
	else
		ft_print_echo(cmd, 2, 0);
	return (1);
}

int		ft_exit(char **cmd)
{
	if (ft_strcmp(cmd[0], "exit") == 0)
		return (0);
	ft_putendl("Shell exited sucessfull");
	exit(ft_atoi(cmd[1]));
}

int		ft_cd(char **cmd)
{
	char	buf[512];
	char	**ch_env;
	char	*to_move;

	if (ft_strcmp(cmd[0], "cd") == 0)
		return (0);
	ch_env = 0;
	ch_env = ft_old_pwd(ch_env);
	if (cmd[1] == 0)
		to_move = ft_getenv("HOME");
	else if (ft_strcmp(cmd[1], "-") == 1)
		to_move = ft_getenv("OLDPWD");
	else
		to_move = cmd[1];
	if (chdir(to_move) == 0)
	{
		ft_setenv(ch_env);
		ch_env[1] = ft_strdup("PWD");
		ch_env[2] = getcwd(buf, 256);
		ft_setenv(ch_env);
		free(ch_env);
		return (1);
	}
	return (1);
}

int		ft_builtins(char **cmd)
{
	int		(*fct[7])(char **);
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
	fct[6] = add_in_history;
	while (i < 7 && b == 0)
		b = fct[i++](cmd);
	return (b);
}
