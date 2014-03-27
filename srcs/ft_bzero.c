/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:49:21 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/27 17:16:29 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char		*ft_bzero(char *str)
{
	char	*back;
	int		t;

	t = ft_strlen(str) + 1;
	back = malloc(sizeof(char) * t);
	while (t >= 0)
		back[t--] = 0;
	return (back);
}
