/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:59:33 by cheron            #+#    #+#             */
/*   Updated: 2014/03/05 15:14:21 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <libft.h>
#include "../ft_minishell.h"

static void		ft_proceed_cmd(char *cmd, t_dat *dat);
static int		ft_check_builtin(char *cmd, t_dat *dat);
static int		ft_proceed_sys(char *cmd, t_dat *dat);
static int		ft_check_access(char **path, char **cmd_split, char **env);

void			ft_minishell(char *cmd, t_dat *dat)
{
	pid_t		pid;

	while (ft_isspace(*cmd) || *cmd == '\0')
	{
		if (*cmd == '\0')
			exit(0);
		cmd++;
	}
	if (ft_check_builtin(cmd, dat) == 0)
	{
		if ((pid = fork()) == -1)
			exit(1);
		if (pid > 0)
			wait(NULL);
		else if (pid == 0)
			ft_proceed_cmd(cmd, dat);
	}
}

static void		ft_proceed_cmd(char *cmd, t_dat *dat)
{
	if (ft_proceed_sys(cmd, dat) == -1)
		ft_print_error(cmd, 1);
	exit(0);
}

static int		ft_check_builtin(char *cmd, t_dat *dat)
{
	char	**cmd_split;

	cmd_split = ft_strsplit(cmd, ' ');
	if (ft_strcmp("env", cmd_split[0]) == 0)
		ft_env(dat->env);
	else if (ft_strcmp("cd", cmd_split[0]) == 0)
		ft_builtin_cd(dat, cmd_split);
	else if (ft_strcmp("setenv", cmd_split[0]) == 0)
		ft_setenv(dat->env, cmd_split);
	else if (ft_strcmp("unsetenv", cmd_split[0]) == 0)
		ft_unsetenv(dat, cmd_split);
	else
	{
		ft_free_tab(cmd_split);
		return (0);
	}
	ft_free_tab(cmd_split);
	return (1);
}

static int		ft_proceed_sys(char *cmd, t_dat *dat)
{
	char		**path;
	int			ret;
	char		**cmd_split;
	char		**env;

	env = tab_env(dat->env, 0);
	cmd_split = ft_strsplit(cmd, ' ');
	if (ft_strchr(cmd, '/'))
		ret = execve(cmd_split[0], cmd_split, env);
	path = ft_strsplit(ft_get_env(dat->env, "PATH"), ':');
	ret = ft_check_access(path, cmd_split, env);
	free(path);
	ft_free_tab(env);
	ft_free_tab(cmd_split);
	if (ret == -1)
		return (-1);
	return (1);
}

static int		ft_check_access(char **path, char **cmd_split, char **env)
{
	char		*try;
	int			ret;

	ret = -1;
	if (access(cmd_split[0], X_OK) == 0)
	{
		if (cmd_split[0][0] == '.' && cmd_split[0][1] == '/')
			ret = execve(cmd_split[0], cmd_split, env);
		return (ret);
	}
	while (*path)
	{
		try = ft_strfjoin(*path, "/");
		try = ft_strfjoin(try, cmd_split[0]);
		if (access(try, X_OK) == 0)
		{
			ret = execve(try, cmd_split, env);
			free(try);
			return (ret);
		}
		free(try);
		path++;
	}
	return (-1);
}
