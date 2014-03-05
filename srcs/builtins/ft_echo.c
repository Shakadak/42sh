/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 11:57:22 by cheron            #+#    #+#             */
/*   Updated: 2014/03/05 13:46:21 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_echo(char **cmd_split)
{
	int		i;
	int		j;
	char	*stop;

	stop = NULL;
	j = 0;
	i = (ft_strcmp(cmd_split[1], "-n") == 0 ? 2 : 1);
	while (cmd_split[i] && stop == NULL)
	{
		if (!(stop = ft_strstr(cmd_split[i], "\\c")))
			ft_putstr(cmd_split[i]);
		else
		{
			while (&cmd_split[i][j] != stop)
			{
				ft_putchar(cmd_split[i][j]);
				j++;
			}
		}
		i++;
		if (cmd_split[i] && stop == NULL)
			ft_putchar(' ');
	}
	if (ft_strcmp(cmd_split[1], "-n") != 0 && stop == NULL)
		ft_putchar('\n');
	else
		ft_putstr("\033[7m%\033[0m\n");
	return (0);
}

