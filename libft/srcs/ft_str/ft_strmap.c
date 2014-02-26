/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:51:14 by cheron            #+#    #+#             */
/*   Updated: 2013/11/26 17:06:32 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*str;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	while (i < len)
		{
			str[i] = f(s[i]);
			i++;
		}
	return (str);
}

