/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:58:36 by cheron            #+#    #+#             */
/*   Updated: 2013/11/29 17:52:33 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	i;
	size_t	len;

	if (s == NULL || f == NULL)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
		{
			f(&s[i]);
			i++;
		}
}

