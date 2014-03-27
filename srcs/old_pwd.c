/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:32:07 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/27 16:04:45 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	**ft_old_pwd(char **ch_env)
{
	char	buf[512];

	ch_env = malloc(sizeof(char *) * 3);
	ch_env[0] = ft_strdup("setenv");
	ch_env[1] = ft_strdup("OLDPWD");
	ch_env[2] = getcwd(buf, 511);
	return (ch_env);
}
