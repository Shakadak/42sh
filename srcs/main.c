/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 10:04:14 by kelickel          #+#    #+#             */
/*   Updated: 2014/02/25 12:49:37 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int	ft_builtins(char **cmd)
{
	int	(*fct[1])(char **);
	int	i;
	int	b;

	i = 0;
	b = 0;
	fct[0] = ft_exit;
	while(i < 1 && b == 0)
		b = fct[i++](cmd);
	return (b);
}

int	main(void)
{
	char	*str;
	char	**tab;

	ft_prompt();
	while (get_next_line(0, &str))
	{
		tab = ft_strsplit(str, ' ');
		if (ft_builtins(tab) == 1)
			write(1, "exe\n", 4);
		ft_prompt();
	}
	return (0);
}
