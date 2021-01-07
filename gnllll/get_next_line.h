/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamarei <aamarei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:16:12 by aamarei           #+#    #+#             */
/*   Updated: 2021/01/04 21:04:12 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_chr_instr(char *str, char c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *str, char *buf);
char	*ft_line(char *str);
char	*ft_remainder(char *str);
int		get_next_line(int fd, char **line);
void	ft_free(char **s);

#endif
