/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:36:08 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/22 17:19:49 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * ft_strlen(src));
	i = 0;
	while (src[i] != 0)
	{
		str[i] = src[i];
		i = i + 1;
	}
	str[i] = 0;
	return (str);
}
