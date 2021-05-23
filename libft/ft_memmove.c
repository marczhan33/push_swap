/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 22:26:19 by mzhan             #+#    #+#             */
/*   Updated: 2021/02/02 19:28:46 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*csrc;
	char	*cdest;

	csrc = (char *)src;
	cdest = (char *)dest;
	if (!dest)
		return (NULL);
	if (cdest < csrc)
		ft_memcpy(dest, src, len);
	else if (cdest > csrc)
	{
		i = len;
		while (i-- > 0)
			cdest[i] = csrc[i];
	}
	return (dest);
}
