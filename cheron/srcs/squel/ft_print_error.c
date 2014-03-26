/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 15:00:40 by cheron            #+#    #+#             */
/*   Updated: 2014/03/03 19:35:32 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../ft_minishell.h"

void	ft_print_error(char *cmd, int code)
{
	if (code == 1)
	{
		ft_putstr_fd("42sh: command not found: ", 2);
		ft_putendl_fd(cmd, 2);
	}
}
