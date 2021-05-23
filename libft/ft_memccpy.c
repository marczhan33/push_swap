/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marczhan33@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:46:32 by mzhan             #+#    #+#             */
/*   Updated: 2021/02/01 16:29:53 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		((char *)dest)[i] = ((char *)src)[i];
		if (((char*)src)[i] == ((char)c))
			return (dest + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
