/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:51:06 by cheron            #+#    #+#             */
/*   Updated: 2014/03/03 18:24:30 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../ft_minishell.h"

static void		ft_put_uname(t_env *env);
static void		ft_put_pwd(t_env *env);

void			ft_put_prompt(t_env *env)
{
	ft_put_uname(env);
	ft_put_pwd(env);
}

static void		ft_put_pwd(t_env *env)
{
	int				i;
	char			*pwd;
	char			*home;

	pwd = ft_get_env(env, "PWD");
	home = ft_get_env(env, "HOME");
	i = ft_strlen(home);
	ft_putstr("[42sh]");
	if (ft_strnstr(pwd, home, i))
	{
		ft_putstr("[");
		ft_putstr("~");
		ft_putstr(&pwd[i]);
		ft_putstr("]");
	}
	else
		ft_putstr(pwd);
	ft_putstr("~>\033[0m");
}

static void		ft_put_uname(t_env *env)
{
	int				i;
	char			*uname;

	i = 0;
	uname = ft_get_env(env, "USER");
	if (!uname)
		return ;
	ft_putstr("\033[1;1m[");
	ft_putstr(uname);
	ft_putstr("]");
}
