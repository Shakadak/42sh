/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 11:37:07 by npineau           #+#    #+#             */
/*   Updated: 2014/03/05 14:42:13 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "../ft_minishell.h"

static t_env	*new_elem(char *src);

t_env			*clone_env(void)
{
	extern char	**environ;
	t_env		*new;
	t_env		*tmp;

	new = NULL;
	if (!environ)
		return (NULL);
	while (*environ)
	{
		if (new == NULL)
		{
			tmp = new_elem(*environ);
			new = tmp;
		}
		else
		{
			tmp->next = new_elem(*environ);
			tmp = tmp->next;
		}
		environ++;
	}
	return (new);
}

static t_env	*new_elem(char *src)
{
	t_env		*new;

	new = (t_env *)malloc(sizeof(t_env));
	new->var = ft_strsub(src, 0, ft_strchr(src, '=') - src);
	new->value = ft_strdup(ft_strchr(src, '=') + 1);
	new->next = NULL;
	return (new);
}

char			**tab_env(t_env *env, int length)
{
	char	**new;
	char	*tmp;
	char	*tmp2;

	if (!env)
	{
		new = (char **)malloc(sizeof(char *) * (length + 1));
		new[length + 1] = NULL;
		return (new);
	}
	new = tab_env(env->next, length + 1);
	tmp = ft_strjoin(env->var, "=");
	tmp2 = ft_strjoin(tmp, env->value);
	free(tmp);
	new[length] = tmp2;
	return (new);
}
