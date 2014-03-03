/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 11:37:07 by npineau           #+#    #+#             */
/*   Updated: 2014/03/03 13:01:57 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

static t_env		*new_elem(char *src);

t_env				*clone_env(void)
{
	extern char	**src;
	t_env		*new;
	t_env		*tmp;

	new = NULL;
	while (*src)
	{
		if (new == NULL)
		{
			tmp = new_elem(*src);
			new = tmp;
		}
		else
		{
			tmp->next = new_elem(*src);
			tmp = tmp->next;
		}
		src++;
	}
	return (new);
}

static t_env		*new_elem(char *src)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	new->var = ft_strncpy(src, (ft_strchr(src, '=') - 1) - src);
	new->value = ft_strdup(ft_strchr(src, '=') + 1);
	new->next = NULL;
	return (new);
}
