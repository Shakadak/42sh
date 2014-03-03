/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 11:37:07 by npineau           #+#    #+#             */
/*   Updated: 2014/03/03 18:12:47 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "../ft_minishell.h"

static t_env		*new_elem(char *src);

t_env				*clone_env(void)
{
	extern char	**environ;
	t_env		*new;
	t_env		*tmp;

	new = NULL;
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

static t_env		*new_elem(char *src)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	new->var = ft_strsub(src, 0, ft_strchr(src, '=') - src);
	new->value = ft_strdup(ft_strchr(src, '=') + 1);
	new->next = NULL;
	return (new);
}
