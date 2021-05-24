/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:30:26 by mzhan             #+#    #+#             */
/*   Updated: 2021/05/24 15:27:47 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int nb_int(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int main (int argc, char **argv)
{
	char **str;
	int *tab;
	size_t i;
	size_t len;

	i = 0;
	str = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
	}
	else 
	{
		str = (char **)malloc(sizeof(*str) * (argc + 1));
		if (!str)
			return (0);
		while ((int)i < argc )
		{
			str[i] = argv[i + 1];
			i++;
		}
	}
	i = 0;
	len = nb_int(str);	
	tab = (int *)malloc(sizeof(*tab) * (len + 1));
	if (!tab)
		return (-1);
	while (i < len)
	{
		tab[i] = ft_atoi(str[i]);
		printf("%d\n", tab[i]);
		i++;
	}
	tab[i] = '\0';
	return (0);
}
