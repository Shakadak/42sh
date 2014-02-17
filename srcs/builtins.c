/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 10:36:52 by kelickel          #+#    #+#             */
/*   Updated: 2014/02/17 11:45:52 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int	ft_exit(char **cmd)
{
	if (ft_strcmp(cmd[0], "exit") == 0)
	{
		return (0);
	}
	exit(ft_atoi(cmd[1]));
}

int	ft_cd(char **cmd)
{
	cmd = cmd;
	return (1);
}
