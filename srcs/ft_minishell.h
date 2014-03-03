/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:44:39 by cheron            #+#    #+#             */
/*   Updated: 2014/03/03 16:35:50 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define NB_BUILTINS 1

typedef struct		s_env
{
	char			*var;
	struct s_env	*next;
}					t_env;

typedef struct	s_dat
{
	t_env	**env;
}				t_dat;

void			ft_minishell(char *cmd, t_dat *dat);
void			ft_print_error(char *cmd, int code);
void			ft_env(t_env *env);
void			ft_setenv(t_env *env, char **cmd)
void			ft_unsetenv(t_dat *dat, char **cmd)
void			ft_put_prompt(char **env);
t_env			*clone_env();
void			ft_cd(t_dat *dat, char **cmd_split);
void			ft_check_cd(char *av);
int				ft_builtin_cd(t_dat *dat, char **cmd_split);
int				check_error(char **cmd_split);
void			ft_check_cd(char *dir);
char			*ft_get_env(t_env *env, char *search)
int				ft_exit(char *cmd);
int				ft_isexit_cmd(char *cmd);

#endif
