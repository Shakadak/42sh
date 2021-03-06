/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 10:53:16 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/27 20:38:24 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int	ft_system(char *str)
{
	int			k;
	extern char	**environ;
	char		**arg;

	arg = ft_strsplit_r(str);
	if (ft_builtins(arg) != 0)
		return (1);
	k = fork();
	if (k == 0)
		ft_exec(environ, arg);
	else if (k > 0)
	{
		wait(&k);
		ft_free_all(arg);
		if (k == 0)
			return (1);
		else
			return (-1);
	}
	else
		exit(-1);
	return (1);
}

int	ft_pipe(char *str)
{
	int			fd[2];
	int			k;
	extern char	**environ;
	char		**arg;

	arg = ft_strsplit_r(str);
	pipe(fd);
	if ((k = fork()) == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ft_exec(environ, arg);
		close(fd[1]);
	}
	else if (k > 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(&k);
		close(fd[0]);
		ft_free_all(arg);
		if (k != 0)
			return (-1);
	}
	return (1);
}

int	ft_in(char *str, char *all, int *i)
{
	int		fd;
	char	*tmp;
	int		a;
	char	**ded;

	fd = 0;
	a = 0;
	*i = *i + 1;
	tmp = (char *)malloc(sizeof(char *) * ft_strlen(all));
	ded = ft_strsplit(str, '<');
	while (all[*i] == ' ')
		*i = *i + 1;
	while (all[*i] != ' ' && all[*i] != 0)
	{
		tmp[a++] = all[*i];
		*i = *i + 1;
	}
	tmp[*i] = 0;
	ft_in_standard(ded, tmp, fd);
	ft_free_all(ded);
	return (1);
}

int	ft_out(char *str, char *all, int *i)
{
	char	*tmp;
	int		a;
	int		oldfd;
	int		param;

	oldfd = dup(1);
	a = 0;
	*i = *i + 1;
	param = 0;
	if (all[*i] == '>')
	{
		param = 1;
		*i = *i + 1;
	}
	while (all[*i] == ' ' || all[*i] == '\t')
		*i = *i + 1;
	tmp = malloc(sizeof(char *) * ft_strlen(all));
	while (all[*i] != ' ' && all[*i] != '\0' && all[*i] != ';')
	{
		tmp[a++] = all[*i];
		*i = *i + 1;
	}
	tmp[a] = 0;
	exec_after(str, oldfd, param, tmp);
	return (1);
}
