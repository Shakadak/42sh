/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 13:03:28 by cheron            #+#    #+#             */
/*   Updated: 2014/03/03 13:37:06 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "../ft_minishell.h"

static t_env		*new_elem(char **src)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	new->var = ft_strdup(src[1]);
	new->value = ft_strdup(src[2]);
	new->next = NULL;
	return (new);
}

void			ft_setenv(t_env *env, char **cmd)
{
	int		ret;

	if (env->next && !(ret = ft_strequ(env->var, cmd[1])))
		ft_setenv(env->next, cmd);
	else if (!ret)
	{
		if (!cmd[1] && !cmd[2])
			ft_putendl("Usage: setenv VAR value.");
		else
			env->next = new_elem(cmd);
	}
	else if (ret)
		env->value = ft_strdup(cmd[2]);
}
