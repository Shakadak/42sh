/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 10:41:26 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/27 18:38:48 by kelickel         ###   ########.fr       */
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
# define BUFF_SIZE 4096

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

typedef struct		s_root
{
	char			*str;
	struct s_root	*next;
	struct s_root	*prev;
}					t_root;

t_root				*g_list;
int					g_check_exec;
char				**g_environ;

int					ft_out(char *str, char *all, int *i);
void				affp(void);
void				the_cd(char *arg);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
int					built(char **arg);
char				*xread(int fildes, char *buf);
pid_t				xfork(void);
char				*ft_getenv(char *srch);
char				**ft_strsplit(char const *s, char c);
char				*ft_path();
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strnew(size_t size);
size_t				ft_strlen(const char *s);
void				ft_putstr(char const *s);
int					ft_strcmpm(char *one, char *two);
int					ft_strcmp(char *one, char *two);
char				*ft_epur(char *str);
int					ft_exec(char **env, char **arg);
int					middle(char *str);
void				to_execute(char **arg);
int					ft_atoi(const char *str);
void				after_that(char *str);
void				sig_contc(int sig);
int					get_next_line(int fd, char **line);
int					ft_execenv(char **env, char **arg);
int					ft_unsetenv(char **str);
int					ft_setenv(char **str);
int					ft_env(char **arg);
int					ft_builtins(char **cmd);
int					ft_in(char *str, char *all, int *i);
int					ft_pipe(char *str);
int					ft_in(char *str, char *all, int *i);
int					ft_system(char *str);
int					ft_pipe(char *str);
char				*ft_strdup(char *src);
void				ft_putendl(char *str);
void				ft_free_all(char **str);
void				ft_putstr_fd(char const *s, int fd);
char				**ft_strsplit_r(char *str);
void				add_history(t_root **list, t_root *item);
t_root				*create(char *str);
int					add_in_history(char **arg);
char				*new_str(char *str);
char				**ft_old_pwd(char **ch_env);
void				ft_in_standard(char **ded, char *tmp, int fd);
int					what_to_exec(char *buff, int i, char *tmp);
char				*ft_bzero(char *str);
int					three(char *buff);
int					exec_in_two(char *str, char *buff, int i);

#endif /* !FT_SH_H */
