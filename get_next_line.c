#include "get_next_line.h"
#define BUFFERSIZE (10)

int	get_next_line(int fd, char **line)
{
	char	buf[BUFFERSIZE];
	int	byte_read;
	char	*p_n;
	int	flag;

	flag = 1;
	*line = malloc(1);
	while (flag && (byte_read = read(fd, buf, BUFFERSIZE)))
	{
		buf[byte_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			flag = 0;
		}
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}
