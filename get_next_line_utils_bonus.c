/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:05:19 by msaidi            #+#    #+#             */
/*   Updated: 2022/11/18 08:05:34 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	char	*res;
	size_t	lenjoin;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	lenjoin = ft_strlen(s1) + ft_strlen(s2);
	s = malloc (sizeof(char) * (lenjoin + 1));
	if (!s)
		return (NULL);
	res = s;
	while (*s1)
		*s++ = *s1++;
	while (*s2)
		*s++ = *s2++;
	*s = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char) c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *) s);
}

char	*ft_strdup(const char *s1)
{
	char	*dp;
	size_t	i;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	dp = (char *)malloc (sizeof(char) * (i + 1));
	if (!dp)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dp[i] = s1[i];
		i++;
	}
	dp[i] = '\0';
	return (dp);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	slen;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (ft_strlen(s + start) <= len)
		sub = malloc (sizeof(char) * (ft_strlen(s + start) + 1));
	else
		sub = malloc (sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[start] && i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
