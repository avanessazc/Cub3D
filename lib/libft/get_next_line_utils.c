/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:03:00 by ayzapata          #+#    #+#             */
/*   Updated: 2019/12/02 16:35:25 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr_gnl(const char *s, int c)
{
	char	tmp_c;
	char	*tmp_s;
	int		i;

	tmp_c = (char)c;
	tmp_s = (char *)s;
	i = 0;
	while (tmp_s[i] != '\0' && tmp_s[i] != tmp_c)
		i++;
	if (tmp_s[i] == tmp_c)
		return (i);
	return (-1);
}

char	*ft_strdup_gnl(const char *s1)
{
	int		i;
	int		len;
	char	*dest;

	len = 0;
	while (s1[len] != '\0')
		len++;
	dest = (char*)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*dst;

	l = ft_strlen_gnl(s1) + size;
	dst = (char *)malloc(sizeof(char) * (l + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	size_t				i;
	size_t				j;
	char				*dst;
	unsigned int		len_s;

	if (s == NULL)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	len_s = ft_strlen_gnl(s);
	i = start;
	j = 0;
	while (s[i] != '\0' && i < len + start && start < len_s)
	{
		dst[j] = s[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
