/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 16:29:38 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/27 23:19:06 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		free(str[i++]);
	if (str)
		free(str);
}
