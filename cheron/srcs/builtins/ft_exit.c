/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 17:14:14 by cheron            #+#    #+#             */
/*   Updated: 2014/01/21 15:16:13 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int		ft_exit(char *cmd)
{
	while (ft_isspace(*cmd))
		cmd++;
	ft_putstr("42sh: exit (");
	if (cmd)
		ft_putnbr(ft_atoi(&cmd[4]));
	ft_putendl(")");
	if (cmd[4])
		exit(ft_atoi(&cmd[4]));
	else
		exit(0);
}

int		ft_isexit_cmd(char *cmd)
{
	while (ft_isspace(*cmd))
		cmd++;
	if (strncmp(cmd, "exit", 4) != 0)
		return (0);
	else if (cmd[4] == 0 || cmd[4] == ' ')
		return (1);
	return (0);
}
