/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_to_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:34:13 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/27 16:44:08 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int	what_to_exec(char *buff, int i, char *tmp)
{
	int	back;

	if (buff[i] == '|')
		back = ft_pipe(tmp);
	else if (buff[i] == '<')
		back = ft_in(tmp, buff, &i);
	else if (buff[i] == '>')
		back = ft_out(tmp, buff, &i);
	else
		back = ft_system(tmp);
	return (back);
}
