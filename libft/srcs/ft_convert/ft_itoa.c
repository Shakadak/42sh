/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:04:43 by cheron            #+#    #+#             */
/*   Updated: 2014/01/11 18:58:25 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_iterative_itoa(char *str, size_t len, int n);

static void	ft_iterative_itoa(char *str, size_t len, int n)
{
	int		u;

	while (len)
		{
			len--;
			u = n % 10;
			if (u < 0)
				u = -u;
			str[len] = u + '0';
			n = n / 10;
		}
}

char		*ft_itoa(int n)
{
	size_t	len;
	int		u;
	int		sign;
	char	*str;

	len = 1;
	sign = n;
	if (n < 0)
		len++;
	u = n;
	while (u <= -10 || u >= 10)
		{
			u = u / 10;
			len++;
		}
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	ft_iterative_itoa(str, len, n);
	if (sign < 0)
		str[0] = '-';
	return (str);
}

