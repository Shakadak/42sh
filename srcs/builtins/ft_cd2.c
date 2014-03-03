/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 14:14:33 by cheron            #+#    #+#             */
/*   Updated: 2014/02/26 15:59:23 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "../ft_minishell.h"

void	ft_check_cd(char *dir)
{
	if (access(dir, F_OK) == -1)
	{
		write(2, "cd: no such file or directory: ", 31);
		ft_putendl_fd(dir, 2);
	}
	else if (access(dir, R_OK) == -1)
	{
		write(2, "cd: permission denied: ", 23);
		ft_putendl_fd(dir, 2);
	}
	else if (access(dir, X_OK) == -1)
	{
		write(2, "cd: not a directory: ", 21);
		ft_putendl_fd(dir, 2);
	}
}

int		check_error(char **cmd_split)
{
	if (cmd_split[1] != NULL && cmd_split[2] != NULL)
	{
		ft_putendl_fd("cd: too many arguments", 2);
		return (-1);
	}
	return (0);
}

int		ft_builtin_cd(t_dat *dat, char **cmd_split)
{
	ft_cd(dat, cmd_split);
	return (1);
}

char	*ft_get_env(t_dat *dat, char *search)
{
	int			i;
	size_t		len;


	i = 0;
	len = ft_strlen(search);
	while (dat->env[i])
		{
			if (ft_strncmp(dat->env[i], search, len) == 0)
				return (dat->env[i]);
			i++;
		}
	return (NULL);
}

