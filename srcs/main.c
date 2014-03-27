/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 10:31:59 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/27 18:29:08 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	sig_handler(int sig)
{
	if (sig == 2)
		ft_putstr_fd("\n\033[1;34m42Sh\033[0m >> ", 1);
	if (sig == SIGTSTP)
		return ;
}

int		three(char *buff)
{
	char	*tmp;
	int		i;
	int		t;
	int		fd;
	int		back;

	i = 0;
	fd = dup(0);
	tmp = ft_bzero(buff);
	while (buff[i] != 0)
	{
		t = 0;
		while (buff[i] != '<' && buff[i] != '>' && buff[i] && buff[i] != '|')
			tmp[t++] = buff[i++];
		tmp[t] = '\0';
		back = what_to_exec(buff, i, tmp);
		while (t != 0)
			tmp[t--] = 0;
		if (buff[i] != 0)
			i++;
	}
	free(tmp);
	dup2(fd, 0);
	return (back);
}

int		two(char *buff)
{
	char	*str;
	int		t;
	int		i;

	i = 0;
	str = ft_bzero(buff);
	t = 0;
	while (buff[i] != 0)
	{
		while ((buff[i] != '|' || buff[i + 1] != '|') && buff[i] &&
				(buff[i] != '&' || buff[i + 1] != '&'))
			str[t++] = buff[i++];
		str[t] = 0;
		if (exec_in_two(str, buff, i) == 1)
			return (1);
		if (buff[i])
		{
			while (t >= 0)
				str[t--] = 0;
			i = i + 2;
		}
	}
	three(str);
	free(str);
	return (1);
}

void	first(char *buff)
{
	char	*str;
	int		t;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(buff) + 1));
	t = 0;
	while (buff[i] != '\0')
	{
		str[t++] = buff[i++];
		if ((buff[i] == '&' || buff[i] == ';') &&
				buff[i + 1] != '&' && buff[i - 1] != '&')
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
}

int		main(int ac, char **av, char **env)
{
	char	*str;

	(void)ac;
	(void)av;
	g_list = NULL;
	g_environ = env;
	ft_putstr_fd("\033[1;34m42Sh\033[0m >> ", 1);
	signal(SIGINT, sig_handler);
	signal(SIGTSTP, sig_handler);
	while (get_next_line(0, &str) != 0)
	{
		add_history(&g_list, create(str));
		first(new_str(str));
		ft_putstr_fd("\033[1;34m42Sh\033[0m >> ", 1);
		free(str);
	}
	return (1);
}
