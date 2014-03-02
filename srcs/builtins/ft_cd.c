/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 14:00:21 by cheron            #+#    #+#             */
/*   Updated: 2014/02/26 15:59:23 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "../ft_minishell.h"

static void		ft_set_env_cd(t_dat *dat, char *cmd, char *arg1, char *arg2)
{
	char		**cmd_split;

	cmd_split = (char **) malloc(sizeof(char *) * 4);
	cmd_split[0] = ft_strdup(cmd);
	cmd_split[1] = ft_strdup(arg1);
	if (arg2)
		cmd_split[2] = ft_strdup(arg2);
	else
		cmd_split[2] = 0;
	cmd_split[3] = 0;
	ft_setenv(dat, cmd_split);
	ft_free_tab(cmd_split);
	cmd_split = NULL;
}

static void	ft_change_env_dir(t_dat * dat, char *str)
{
	DIR		*dir;
	char	*tmp;

	tmp = NULL;
	dir = opendir(str);
	if (dir == NULL)
		ft_check_cd(str);
	else
	{
		tmp = getcwd(tmp, 0);
		chdir(str);
		ft_set_env_cd(dat, "setenv", "OLDPWD", tmp);
		ft_strdel(&tmp);
		tmp = getcwd(tmp, 0);
		ft_set_env_cd(dat, "setenv", "PWD", tmp);
		ft_strdel(&tmp);
		closedir(dir);
	}
}

void	ft_cd(t_dat *dat, char **cmd_split)
{
	char		*tmp;

	if (check_error(cmd_split))
		return ;
	if (cmd_split[1] == NULL || (ft_strcmp(cmd_split[1], "~") == 0))
		{
			if ((tmp = ft_get_env(dat, "HOME=")))
				ft_change_env_dir(dat, &tmp[5]);
			return ;
		}
	else if ((ft_strcmp(cmd_split[1], "-") == 0))
		{
			if ((tmp = ft_get_env(dat, "OLDPWD=")))
				{
					ft_change_env_dir(dat, &tmp[7]);
					ft_putendl(ft_get_env(dat, "PWD=") + 4);
				}
			else
				ft_putendl_fd("cd: can't find OLDPWD", 2);
			return ;
		}
	ft_change_env_dir(dat, cmd_split[1]);
}

