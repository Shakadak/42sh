/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 12:09:12 by cheron            #+#    #+#             */
/*   Updated: 2014/02/21 14:38:23 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYS_TYPES_H
# define SYS_TYPES_H
# include <sys/types.h>
#endif /* !SYS_TYPES_H */
#ifndef SYS_UIO_H
# define SYS_UIO_H
# include <sys/uio.h>
#endif /* !SYS_UIO_H  */
#ifndef STDLIB_H
# define STDLIB_H
# include <stdlib.h>
#endif /* !STDLIB_H  */
#ifndef UNISTD_H
# define UNISTD_H
# include <unistd.h>
#endif /* !UNISTD_H  */
#ifndef LIBFT_H
# include <libft.h>
#endif /* !LIBFT_H  */
#ifndef GET_NEXT_LINE_H
# include <get_next_line.h>
#endif /* !GET_NEXT_LINE_H  */

char	*ft_join_free(char **line, char *buff)
{
	char		*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buff);
	ft_strdel(&tmp);
	return (*line);
}

int		ft_buff_leftover(char *buff, char **line)
{
	char		*next_line;

	if ((next_line = ft_strchr(buff, '\n')))
	{
		next_line[0] = '\0';
		if (!(*line = ft_join_free(line, buff)))
			return (-1);
		buff = ft_memmove(buff, &next_line[1], (ft_strlen(&next_line[1]) + 1));
		return (1);
	}
	else
	{
		if (!(*line = ft_join_free(line, buff)))
			return (-1);
		ft_strclr(buff);
		return (0);
	}
}

int		ft_join_move(char **line, char *buff, char *next_line, int nbread)
{

	*next_line = '\0';
	if (!(*line = ft_join_free(line, buff)))
		return (-1);
	buff = ft_memmove(buff, &next_line[1], ft_strlen(&next_line[1]) + 1);
	if (buff == NULL)
		return (-1);
	return (nbread);
}

int		ft_readfile(int const fd, char ** line, char *buff)
{
	char		*next_line;
	ssize_t		nbread;

	while ((nbread = read(fd, (void *) buff, (size_t) BUFF_SIZE)))
	{
		if (nbread == -1)
		{
			ft_strdel(&buff);
			return (-1);
		}
		buff[nbread] = '\0';
		if (!(next_line = ft_strchr(buff, '\n')))
		{
			if (!(*line = ft_join_free(line, buff)))
				return (-1);
			ft_strclr(buff);
		}
		else
			return (ft_join_move(line, buff, next_line, nbread));
	}
	return (nbread);
}

int		get_next_line(int const fd, char **line)
{
	static char	*buff;
	int			ret;

	if (BUFF_SIZE < 1 || fd < 0 || BUFF_SIZE > 2147483647)
		return (-1);
	if (!buff)
		buff = ft_strnew(((size_t) BUFF_SIZE));
	*line = ft_strnew(0);
	if (!buff)
		return (-1);
	ret = ft_buff_leftover(buff, line);
	if (ret == 1)
		return (1);
	if (strchr(buff, '\n') == NULL)
		ret = ft_readfile(fd, line, buff);
	if (ret == 0 && *line[0] != '\0')
		return (1);
	if (ret == 0)
			ft_strdel(&buff);
	if (ret > 0)
		ret = 1;
	return (ret);
}

