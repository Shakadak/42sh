/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 10:31:59 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/12 17:15:16 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	sig_handler(int sig)
{
	write(1, "segfault", 8);
	if (sig == 2)
		write(1, "\n$>", 3);
}

int three(char *buff)
{
	char	*tmp;
	int		i;
	int		t;
	int		fd;
	int		back;

	i = 0;
	t = ft_strlen(buff);
	tmp = malloc(sizeof(char) * (t + 1));
	while (t != 0)
		tmp[t--] = 0;
	fd = dup(0);
	while (buff[i] != 0)
	{
		t = 0;
		while (buff[i] != '<' && buff[i] != '>' && buff[i] != 0 && buff[i] != '|')
			tmp[t++] = buff[i++];
		tmp[t] = '\0';
		if (buff[i] == '|')
			back = ft_pipe(tmp);
		else if (buff[i] == '<')
			back = ft_in(tmp, buff, &i);
		else if (buff[i] == '>')
			back = ft_out(tmp, buff, &i);
		else
			back = ft_system(tmp);
		while (t != 0)
			tmp[t--] = 0;
		if (buff[i] != 0)
			i++;
	}
	free(tmp);
	dup2(fd, 0);
	return (back);
}

int	two(char *buff)
{
	char	*str;
	int		t;
	int		i;

	i = 0;
	t = ft_strlen(buff);
	str = (char *)malloc(sizeof(char) * (t + 1));
	t = 0;
	while(buff[i] != 0)
	{
		str[t++] = buff[i++];
		if (buff[i] == '|' && buff[i + 1] == '|')
		{
			str[t] = 0;
			if (three(str) == 1)
				return (1);
			while (t >= 0)
				str[t--] = 0;
			i = i + 2;
		}
		if (buff[i] == '&' && buff[i + 1] == '&')
		{
			str[t] = 0;
			if (three(str) != 1)
				return (0);
			while (t >= 0)
				str[t--] = 0;
			i = i + 2;
		}
	}
	str[t] = 0;
	three(str);
	free(str);
}

int	main()
{
	char	buff[2042];
	char	*str;
	int		t;
	int		i;

	i = 0;
	write(1, "$>", 2);
	t = read(0, buff, 2041);
	buff[t - 1] = 0;
	str = (char *)malloc(sizeof(char) * (t + 1));
	t = 0;
	while (buff[i] != 0)
	{
		str[t++] = buff[i++];
		if (buff[i] == '&' && buff[i + 1] == '&')
		{
			str[t++] = buff[i++];
			str[t++] = buff[i++];
		}
		if (buff[i] == '&' || buff[i] == ';')
		{
			str[t] = 0;
			two(str);
			while (t >= 0)
				str[t--] = 0;
			i = i + 1;
		}
	}
	str[t] = 0;
	two(str);
	free(str);
	main();
}
