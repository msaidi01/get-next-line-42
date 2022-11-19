/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:40:49 by msaidi            #+#    #+#             */
/*   Updated: 2022/11/19 14:24:15 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_lennew(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*read_fd(int fd, char *buff, char *str)
{
	int		i;
	char	*tmp;

	i = 1;
	buff[0] = 0;
	while (i > 0 && !ft_strchr(buff, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		if (i == 0)
		{
			free(buff);
			return (str);
		}
		buff[i] = 0;
		tmp = str;
		str = ft_strjoin(tmp, buff);
		free(tmp);
	}
	free(buff);
	return (str);
}

char	*get_rest(char *str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	temp = malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!temp)
		return (free(str), NULL);
	i++;
	j = 0;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*s[10241];
	char		*line;
	char		*tmp;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	s[fd] = read_fd(fd, buff, s[fd]);
	if (!s[fd])
		return (NULL);
	if (!*s[fd])
		return (free(s[fd]), s[fd] = NULL);
	tmp = s[fd];
	line = ft_substr(tmp, 0, ft_lennew(tmp) + 1);
	if (!line)
		return (free(line), line = NULL);
	s[fd] = get_rest(s[fd]);
	return (line);
}
