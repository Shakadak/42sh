/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:16:01 by kelickel          #+#    #+#             */
/*   Updated: 2014/02/07 12:17:21 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	nomore(const char *str, int *i, int *back)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
	{
		*i = *i + 1;
	}
	if (str[*i] == '+' || str[*i] == 1)
	{
		*back = 1;
		*i = *i + 1;
	}
	else if (str[*i] == '-' || str[*i] == 1)
	{
		*back = -1;
		*i = *i + 1;
	}
}

int			ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		back;

	if (str == 0)
		return (0);
	res = 0;
	i = 0;
	back = 1;
	nomore(str, &i, &back);
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + str[i] - 48;
		i = i + 1;
	}
	return (res * back);
}
