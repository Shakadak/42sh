/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:41:56 by cheron            #+#    #+#             */
/*   Updated: 2014/03/03 15:36:00 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../ft_minishell.h"

static t_env	*get_pre(t_env *env, char *src)
{
	if (env->next)
	{
		if (ft_strequ(env->next->var, src))
			return (env);
		else
			return (get_prev(env->next, src));
	}
	return (NULL);
}

void			ft_unsetenv(t_dat *dat, char **cmd)
{
	t_env		*tmp;
	t_env		*swap;

	if (!cmd[1])
	{
		ft_putendl("Usage: unsetenv VAR");
		return ;
	}
	if (ft_strequ(dat->env->var, cmd[1]))
	{
		tmp = dat->env;
		dat->env = dat->env->next;
		//////////////////////////////////free dis shiet
		return ;
	}
	else
	{
		swap = get_pre(dat->env, cmd[1]);
		if (!swap)
			return ;
		tmp = swap->next;
		swap->next = tmp->next;
		//////////////////////////////////free dis shiet
	}
}
