/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_to_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:34:13 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/27 20:34:58 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		what_to_exec(char *buff, int *i, char *tmp)
{
	int	back;

	if (buff[*i] == '|')
		back = ft_pipe(tmp);
	else if (buff[*i] == '<')
		back = ft_in(tmp, buff, i);
	else if (buff[*i] == '>')
		back = ft_out(tmp, buff, i);
	else
		back = ft_system(tmp);
	return (back);
}

int		exec_in_two(char *str, char *buff, int i)
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

void	exec_after(char	*str, int oldfd, int param, char *tmp)
{
	int	fd;

	if (param == 0)
		fd = open(tmp, O_WRONLY | O_TRUNC | O_CREAT
				, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else
		fd = open(tmp, O_WRONLY | O_CREAT | O_APPEND
				, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		write(2, "Can't open the file\n", 20);
	else
	{
		dup2(fd, 1);
		ft_system(str);
		dup2(oldfd, 1);
		close(fd);
		close(oldfd);
	}
}
