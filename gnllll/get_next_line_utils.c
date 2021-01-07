/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamarei <aamarei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:19:49 by aamarei           #+#    #+#             */
/*   Updated: 2021/01/04 21:31:04 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_chr_instr(char *str, char c)
{
	int	k;

	k = 0;
	if (str == NULL)
		return (0);
	while (str[k] != c)
	{
		if (str[k] == '\0')
			return (0);
		k++;
	}
	return (k + 1);
}

int		ft_strlen(char *str)
{
	int	k;

	k = 0;
	if (!str)
		return (0);
	while (str[k] != '\0')
		k++;
	return (k);
}

void	ft_free(char **s)
{
	if (*s)
		free(*s);
}

char	*ft_strjoin(char *str, char *buf)
{
	unsigned char	*s;
	size_t			len1;
	size_t			len2;
	size_t			i;
	size_t			j;

	i = -1;
	j = 0;
	len1 = ft_strlen(str);
	len2 = ft_strlen(buf);
	if (!(s = (unsigned char *)malloc(sizeof(char) * (len1 + len2) + 1)))
	{
		ft_free(&str);
		free(buf);
		return (NULL);
	}
	while (++i < len1)
		s[i] = str[i];
	while (j < len2)
		s[i++] = buf[j++];
	s[i] = '\0';
	ft_free(&str);
	return ((char *)s);
}
