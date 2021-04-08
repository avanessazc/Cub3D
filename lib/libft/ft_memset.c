/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:20:16 by ayzapata          #+#    #+#             */
/*   Updated: 2019/11/14 12:42:05 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*ptr;
	size_t			l;
	unsigned char	tmp_c;

	tmp_c = (unsigned char)c;
	ptr = (char *)b;
	l = 0;
	while (l < len)
	{
		ptr[l] = tmp_c;
		l++;
	}
	return (b);
}
