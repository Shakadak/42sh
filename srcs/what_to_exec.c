/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_to_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:34:13 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/27 17:49:40 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int	what_to_exec(char *buff, int i, char *tmp)
{
	int	back;

	if (buff[i] == '|')
		back = ft_pipe(tmp);
	else if (buff[i] == '<')
		back = ft_in(tmp, buff, &i);
	else if (buff[i] == '>')
		back = ft_out(tmp, buff, &i);
	else
		back = ft_system(tmp);
	return (back);
}

int	exec_in_two(char *str, char *buff, int i)
{
	if (buff[i] == '|' && buff[i + 1] == '|')
	{
		if (three(str) == 1)
			return (1);
	}
	else if (buff[i] == '&' && buff[i + 1] == '&')
	{
		if (three(str) != 1)
			return (1);
	}
	return (0);
}
