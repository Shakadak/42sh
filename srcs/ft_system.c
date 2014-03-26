/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 10:53:16 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/26 20:29:20 by croy             ###   ########.fr       */
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
	k = fork();
	if (k == 0)
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
		if (k == 0)
			return (1);
		else
			return (-1);
	}
	return (1);
}

int	ft_in(char *str, char *all, int *i)
{
	int		fd;
	char	*tmp;
	int		a;

	a = 0;
	*i = *i + 1;
	str = str;/* checker si il a exectable avant;*/
	tmp = malloc(sizeof(char *) * ft_strlen(all));
	while (all[*i] == ' ')
		*i = *i + 1;
	while (all[*i] != ' ')
	{
		tmp[a++] = all[*i];
		*i = *i + 1;
	}
	tmp[*i] = 0;
	fd = open(tmp, O_RDONLY);
	free(tmp);
	if (fd == -1)
		write(2, "Can't open file\n", 17);
	else
		dup2(fd, 0);
	return (1);
}

int	ft_out(char *str, char *all, int *i)
{
	int		fd;
	char	*tmp;
	int		a;
	int		oldfd;
	int		param;

	oldfd = dup(1);
	a = 0;
	*i = *i + 1;
	if (all[*i] == '>')
	{
		param = 1;
		*i = *i + 1;
	}
	else
		param = 0;
	while (all[*i] == ' ' || all[*i] == '\t')
		*i = *i + 1;
	tmp = malloc(sizeof(char *) * ft_strlen(all));
	while (all[*i] != ' ' && all[*i] != '\0')
	{
		tmp[a++] = all[*i];
		*i = *i + 1;
	}
	tmp[*i] = 0;
	if (param == 0)
		fd = open(tmp, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else
		fd = open(tmp, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
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
	return (1);
}
