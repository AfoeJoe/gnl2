#include "get_next_line.h"
#define BUFFERSIZE (1)

char	*check_remainder(char *remainder, char **line)
{
	char *p_n;

	p_n = NULL;
	if(remainder)
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

int	get_next_line(int fd, char **line)
{
	char	buf[BUFFERSIZE];
	int	byte_read;
	char	*p_n;
	static char	*remainder;

	p_n = check_remainder(remainder, line);
	while (!p_n && (byte_read = read(fd, buf, BUFFERSIZE)))
	{
		buf[byte_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			p_n++;
			remainder = ft_strdup(p_n);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}
