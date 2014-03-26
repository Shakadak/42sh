/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:07:27 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/26 20:28:26 by croy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char					*ft_strnew(size_t size)
{
	char				*str;
	unsigned int		i;

	str = malloc(sizeof(char) * size);
	if (str == 0)
		return (0);
	i = 0;
	while (i != size)
	{
		str[i] = 0;
		i = i + 1;
	}
	return (str);
}
