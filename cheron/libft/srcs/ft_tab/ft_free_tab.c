/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 17:14:14 by cheron            #+#    #+#             */
/*   Updated: 2014/01/21 15:16:13 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	ft_free_tab(char **tab)
{
	char **tmp;

	tmp = tab;
	if (!tab)
		return ;
	while (*tab)
	{
		ft_strdel(tab);
		tab++;
	}
	free(tmp);
}