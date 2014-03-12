/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 10:41:26 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/12 11:12:34 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>

int		check_exec;

void	affp(void);
void	the_cd(char *arg);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
int		built(char **arg);
char	*xread(int fildes, char *buf);
pid_t	xfork(void);
char	*ft_getenv(char *srch);
char	**ft_strsplit(char const *s, char c);
char	*ft_path();
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *s);
void	ft_putstr(char const *s);
int		ft_strcmpm(char *one, char *two);
int		ft_strcmp(char *one, char *two);
char	*ft_epur(char *str);
int		ft_exec(char **env, char **arg);
int		middle(char *str);
void	to_execute(char **arg);
int		ft_atoi(const char *str);
void	after_that(char *str);
void	sig_contc(int sig);
int		get_next_line(int fd, char **line);
int		ft_execenv(char **env, char **arg);

#endif
