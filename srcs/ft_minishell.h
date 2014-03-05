/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:44:39 by cheron            #+#    #+#             */
/*   Updated: 2014/03/05 12:15:01 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define NB_BUILTINS 1

typedef struct	s_dat
{
	char	**env;
}				t_dat;


void			ft_minishell(char *cmd, t_dat *dat);
void			ft_print_error(char *cmd, int code);
void			ft_env(t_dat *dat);
void			ft_setenv(t_dat *dat, char **cmd_split);
void			ft_unsetenv(t_dat *dat, char **cmd_split);
void			ft_put_prompt(char **env);
char			**ft_cpenv();
void			ft_cd(t_dat *dat, char **cmd_split);
void			ft_check_cd(char *av);
int				ft_builtin_cd(t_dat *dat, char **cmd_split);
int				check_error(char **cmd_split);
void			ft_check_cd(char *dir);
char			*ft_get_env(t_dat *dat, char *search);
int				ft_exit(char *cmd);
int				ft_isexit_cmd(char *cmd);
int				ft_echo(char **cmd_split);

#endif
