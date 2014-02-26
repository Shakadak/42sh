/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 15:00:40 by cheron            #+#    #+#             */
/*   Updated: 2014/02/26 16:25:40 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../ft_minishell.h"

void	ft_print_error(char *cmd, int code)
{
	if (code == 1)
	{
		ft_putstr_fd("ft_minishell: command not found: ", 2);
		ft_putendl_fd(cmd, 2);
	}
}
