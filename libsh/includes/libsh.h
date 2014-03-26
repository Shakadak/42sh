/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 12:10:22 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/02/25 12:43:49 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSH_H
# define LIBSH_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char const *str, int fd);
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	**ft_strsplit(char const *s, char c);

# endif /* !LIBSH_H */
