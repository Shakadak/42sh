/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 00:35:55 by croy              #+#    #+#             */
/*   Updated: 2014/03/26 17:43:01 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_sh.h"

t_root	*create(char *str)
{
	t_root	*item;
	item = NULL;
	item = (t_root *) malloc(sizeof(t_root));
	item->str = ft_strdup(str);
	item->next = NULL;
	return (item);
}

void	add_history(t_root **list, t_root *item)
{
	t_root	*parcours;

	if (item == NULL || list == NULL)
		return ;
	if (*list == NULL)
		*list = item;
	else
	{
		parcours = *list;
		while (parcours->next)
			parcours = parcours->next;
		parcours->next = item;
		parcours->next->prev = parcours;
	}
}

int		add_in_history(char **arg)
{
	int	i;

	i = 0;
	if (ft_strcmp(arg[0], "history") == 0)
		return (0);
	if (g_list->next == NULL)
		return (1);
	while (g_list->next)
		g_list = g_list->next;
	while (g_list->prev && i < 15)
	{
		g_list = g_list->prev;
		i++;
	}
	while (g_list->next)
	{
		ft_putendl(g_list->str);
		g_list = g_list->next;
	}
	return (1);
}
