/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathy <tkathy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:43:21 by tkathy            #+#    #+#             */
/*   Updated: 2021/01/04 21:16:28 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **str)
{
	if (*str)
		free(*str);
}

char	*check_remainder(char *remainder, char **line)
{
	char *p_n;

	p_n = NULL;
	if (remainder)
	{
		if ((p_n = ft_strchr(remainder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(remainder);
			ft_strcpy(remainder, ++p_n);
		}
		else
		{
			*line = ft_strdup(remainder);
			*remainder = '\0';
		}
	}
	else
		*line = malloc(1);
	return (p_n);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			byte_read;
	char		*p_n;
	static char	*remainder;
	char		*tmp;

	if (fd < 0 || !line || (BUFFER_SIZE <= 0))
		return (-1);
	p_n = check_remainder(remainder, line);
	while (!p_n && (byte_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			p_n++;
			remainder = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		ft_free(&tmp);
	}
	return (((byte_read || ft_strlen(remainder)) || ft_strlen(*line)) ? 1 : 0);
}
