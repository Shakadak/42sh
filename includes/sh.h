/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 12:19:40 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/02/25 12:46:27 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

/*
** Includes for 42sh
*/

# include "libsh.h"
# include "gnl.h"
# include <sys/types.h>
# include <sys/uio.h>

/*
** Builtin for 42sh
*/

int		ft_exit(char **cmd);

/*
** Useful functions for 42sh
*/

void	ft_prompt(void);

#endif /* !SH_H */
