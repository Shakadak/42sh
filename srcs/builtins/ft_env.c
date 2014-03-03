/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 15:27:37 by cheron            #+#    #+#             */
/*   Updated: 2014/03/03 13:11:08 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../ft_minishell.h"

void		ft_env(t_env *env)
{
	if (!env)
		return ;
	ft_putstr(env->var);
	ft_putchar('=');
	ft_putendl(env->value);
	msh_env(env->next);
}
