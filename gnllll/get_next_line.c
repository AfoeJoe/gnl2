/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamarei <aamarei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:14:37 by aamarei           #+#    #+#             */
/*   Updated: 2021/01/07 19:46:47 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *str)
{
	char	*s;
	size_t	t;

	t = 0;
	while (str[t] != '\n' && str[t] != '\0')
		t++;
	if (!(s = malloc(sizeof(char) * (t + 1))))
	{
		ft_free(&str);
		return (0);
	}
	t = 0;
	while (str[t] != '\0' && str[t] != '\n')
	{
		s[t] = str[t];
		t++;
	}
	s[t] = '\0';
	return (s);
}

char	*ft_remainder(char *str)
{
	char	*s;
	int		t;
	int		i;

	t = 0;
	i = 0;
	while (str && str[t] != '\n' && str[t] != '\0')
		t++;
	if (str[t] == '\0')
	{
		ft_free(&str);
		return (0);
	}
	if (!(s = malloc(sizeof(char) * (ft_strlen(str) - t + 1))))
	{
		ft_free(&str);
		return (0);
	}
	t++;
	while (str[t] != '\0')
		s[i++] = str[t++];
	s[i] = '\0';
	ft_free(&str);
	return (s);
}

int		get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*buf;
	int			t;

	if (fd < 0 || !line || (BUFFER_SIZE <= 0))
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	t = 1;
	while (t != 0 && !ft_chr_instr(remainder, '\n'))
	{
		if ((t = read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free(buf);
			return (-1);
		}
		buf[t] = '\0';
		if (!(remainder = ft_strjoin(remainder, buf)))
			return (-1);
	}
	free(buf);
	*line = ft_line(remainder);
	remainder = ft_remainder(remainder);
	return ((t == 0) ? 0 : 1);
}
