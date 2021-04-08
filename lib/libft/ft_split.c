/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:22:55 by ayzapata          #+#    #+#             */
/*   Updated: 2019/11/14 12:43:21 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\0' && s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (count);
}

static	char	*ft_malloc(char const *s, char c)
{
	char	*sub_dst;
	int		n;

	n = 0;
	while (s[n] != '\0' && s[n] != c)
		n++;
	sub_dst = (char *)malloc(sizeof(char) * (n + 1));
	if (!sub_dst)
		return (NULL);
	n = 0;
	while (s[n] != c && s[n] != '\0')
	{
		sub_dst[n] = s[n];
		n++;
	}
	sub_dst[n] = '\0';
	return (sub_dst);
}

char			**ft_split(char const *s, char c)
{
	char	**dst;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			dst[j] = ft_malloc(&s[i], c);
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	dst[j] = NULL;
	return (dst);
}
