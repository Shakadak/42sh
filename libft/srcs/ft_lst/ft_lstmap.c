/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:32:56 by cheron            #+#    #+#             */
/*   Updated: 2014/01/11 18:59:07 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	del(void *d, size_t s)
{
	free(d);
	(void)s;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	lst = f(lst);
	if (!(new = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
		start = new;
	while (lst->next)
	{
		lst = f(lst->next);
		if (!(new->next = ft_lstnew(lst->content, lst->content_size)))
		{
			ft_lstdel(&start, del);
			return (NULL);
		}
		new = new->next;
	}
	return (start);
}
