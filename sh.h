/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 10:44:28 by kelickel          #+#    #+#             */
/*   Updated: 2014/02/17 11:37:34 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int		ft_exit(char **cmd);
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		get_next_line(int fd, char **line);
char	**ft_strsplit(char const *s, char c);

#endif
