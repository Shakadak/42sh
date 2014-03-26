/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 11:57:22 by cheron            #+#    #+#             */
/*   Updated: 2014/03/05 18:29:59 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		ft_echo2(char **stop, char **cmd_split, int *i);

int				ft_echo(char **cmd_split)
{
	int		i;
	char	*stop;

	stop = NULL;
	if (!cmd_split[1])
	{
		ft_putendl("");
		return (0);
	}
	i = (ft_strcmp(cmd_split[1], "-n") == 0 ? 2 : 1);
	while (cmd_split[i] && stop == NULL)
		ft_echo2(&stop, cmd_split, &i);
	if (ft_strcmp(cmd_split[1], "-n") != 0 && stop == NULL)
		ft_putchar('\n');
	else
		ft_putstr("\033[7m%\033[0m\n");
	return (0);
}


static void		ft_echo2(char **stop, char **cmd_split, int *i)
{
	int		j;

	j = 0;
	if (!(*stop = ft_strstr(cmd_split[*i], "\\c")))
		ft_putstr(cmd_split[*i]);
	else
	{
		while (&cmd_split[*i][j] != *stop)
		{
			ft_putchar(cmd_split[*i][j]);
			j++;
		}
	}
	(*i)++;
	if (cmd_split[*i] && *stop == NULL)
		ft_putchar(' ');
}
