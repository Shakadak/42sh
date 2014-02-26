/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:56:59 by cheron            #+#    #+#             */
/*   Updated: 2013/12/28 15:01:43 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	ret;
	int	sign;

	i = 0;
	ret = 0;
	sign = 1;
	while ((str[i] == '\f') || (str[i] == ' ') || (str[i] == '\n')
		  || (str[i] == '\t') || (str[i] == '\r') || (str[i] == '\v'))
		i++;
	if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
	while (ft_isdigit(str[i]))
		{
			ret = (ret * 10) + (str[i] - '0');
			i++;
		}
	return (sign * ret);
}
