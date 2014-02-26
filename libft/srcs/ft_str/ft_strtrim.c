/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:00:08 by cheron            #+#    #+#             */
/*   Updated: 2013/11/26 17:17:43 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	len;
	char	*str;

	if (s == NULL)
		return (NULL);
	start = 0;
	len = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
	i = start;
	while (s[i] != '\0')
		{
			if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
				len = (i - (start - 1));
			i++;
		}
	str = ft_strsub(s, start, len);
	if (str == NULL)
		return (NULL);
	return (str);
}
