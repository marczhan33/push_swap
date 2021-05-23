/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:30:26 by mzhan             #+#    #+#             */
/*   Updated: 2021/05/23 16:25:07 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	char **str;
	int *tab;
	size_t i;
	int j;
	size_t len;

	i = 0;
	j = 0;
	str = NULL;
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		len = ft_strlen(*str);
		tab = (int *)malloc(sizeof(*tab) * (len + 1));
		if (!tab)
			return (-1);
		while (i < len)
		{
			tab[i] = ft_atoi(str[i]);
			i++;
		}
		tab[i] = '\0';
	}
	return (0);
}
