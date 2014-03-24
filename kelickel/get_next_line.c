/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:11:04 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/22 21:59:36 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					ft_strlenm(char *str, int *a)
{
	int				i;

	i = *a;
	while (str[i] != 0 && str[i] != '\n')
		i = i + 1;
	return (i);
}

char				*to_line(char *buff, int fd, int *bck)
{
	static int		i;
	char			*str;
	int				a;

	a = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlenm(buff, &i) + 1));
	if (str == 0)
		return ((char *)-1);
	while (buff[i] != '\n')
	{
		str[a++] = buff[i++];
		if (buff[i] == 0)
		{
			*bck = read(fd, buff, 511);
			if (*bck == 0)
				return (0);
			else if (*bck == -1)
				return ((char *)-1);
			str[a] = 0;
			buff[*bck] = 0;
			i = 0;
		}
	}
	str[a] = 0;
	if (buff[i + 1] != 0)
		i++;
	else
	{
		i = 0;
		*bck = 0;
	}
	return (str);
}

int				get_next_line(int fd, char **line)
{
	static char	buff[512];
	static int	a;

	if (fd < 0)
		return (-1);
	if (a == 0)
	{
		a = read(fd, buff, 511);
		if (a > 0)
			buff[a] = 0;
		else
			return (0);
	}
	*line = to_line(buff, fd, &a);
	if (*line == (char *)0)
		return (0);
	else if (*line == (char *)-1)
		return (-1);
	return (1);
}
