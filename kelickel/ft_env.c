/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 14:14:54 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/25 17:51:20 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_env(char **arg)
{
	extern char	**environ;
	int			i;

	if (ft_strcmp(arg[0], "env") == 0)
		return (0);
	i = 0;
	while (environ[i] != 0)
	{
		ft_putstr(environ[i++]);
		ft_putchar('\n');
	}
	return (1);
}
