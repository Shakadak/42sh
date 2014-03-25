/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 10:41:26 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/25 17:34:03 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_memory
{
	char			*str;
	struct s_memory	*next;
}				t_memory;

int		check_exec;
extern char	**environ;

int	ft_out(char *str, char *all, int *i);
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
int		ft_unsetenv(char **str);
int		ft_setenv(char **str);
int		ft_env(char	**arg);
int		ft_builtins(char **cmd);
int		ft_in(char *str, char *all, int *i);
int		ft_pipe(char *str);
int		ft_in(char *str, char *all, int *i);
int		ft_system(char *str);
int		ft_pipe(char *str);
char	*ft_strdup(char *src);
void	ft_putendl(char *str);
void	ft_free_all(char **str);
void	ft_putstr_fd(char const *s, int fd);
#endif
