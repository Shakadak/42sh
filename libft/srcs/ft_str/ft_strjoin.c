/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 21:37:17 by cheron            #+#    #+#             */
/*   Updated: 2013/12/29 16:38:29 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	int		len;

	if (!(s1 && s2))
		return (NULL);
	len = ft_strlen(s1);
	new = ft_strnew(len + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcpy(&new[len], s2);
	return (new);
}
