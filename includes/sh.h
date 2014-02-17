/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 10:44:28 by kelickel          #+#    #+#             */
/*   Updated: 2014/02/17 16:10:13 by croy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

/*
** Includes for 42sh
*/

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/*
** Builtin for 42sh
*/

int		ft_exit(char **cmd);

/*
** Useful functions for 42sh
*/

void	ft_prompt(void);

void	ft_putstr_fd(char const *str, int fd);
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		get_next_line(int fd, char **line);
char	**ft_strsplit(char const *s, char c);

#endif /* !SH_H */
