/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 16:18:14 by cheron            #+#    #+#             */
/*   Updated: 2014/02/05 12:55:10 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8

char	*ft_join_free(char **line, char *buff);
int		ft_buff_leftover(char *buff, char **line);
int		ft_join_move(char **line, char *buff, char *next_line, int nbread);
int		ft_readfile(int const fd, char ** line, char *buff);
int		get_next_line(int const fd, char ** line);

#endif /* !GET_NEXT_LINE_H */
