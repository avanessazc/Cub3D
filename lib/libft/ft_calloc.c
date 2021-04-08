/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 08:09:17 by ayzapata          #+#    #+#             */
/*   Updated: 2019/11/14 12:37:39 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr_m;
	size_t			i;

	i = 0;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr_m = malloc(size * count);
	if (!ptr_m)
		return (NULL);
	while (i < count * size)
	{
		ptr_m[i] = '\0';
		i++;
	}
	return (ptr_m);
}
