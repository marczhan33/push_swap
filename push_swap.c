/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:30:26 by mzhan             #+#    #+#             */
/*   Updated: 2021/05/28 15:30:45 by mzhan            ###   ########.fr       */
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

int check_nb(char **str, int argc)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < argc - 1)
	{
		if ((str[i][j] >= '0' && str[i][j] <= '9') || (str[i][j] == '-'))
		{
			if (str[i][j] == '-')
			{	
				j++;
				if(str[i][j] <= '0' || str[i][j] >= 9)
				{
					write(1, "ERROR", 5);
					return (0);
				}
			}
			while (str[i][j] >= '0' && str[i][j] <= '9')
				j++;
			if (str[i][j] != '\0')
			{
				write(1, "ERROR", 5);
				return (0);
			}
			j = 0;
		}
		else
		{
			write(1, "ERROR", 5);
			return (0);
		}
		i++;
	}
	return (1);
}

int check_duplicate(int * tab, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < len)
	{
		while (j < len)
		{	
			if (tab[i] == tab[j])
			{
				write(1,"ERROR", 5);
				return (0);
			}
			j++;
		}
		i++;
		j = i;
	}
	return (1);
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
		str = ft_split(argv[1], ' ');
	else 
	{
		str = (char **)malloc(sizeof(*str) * (argc + 1));
		if (!str)
			return (1);
		while ((int)i < argc )
		{
			str[i] = argv[i + 1];
			i++;
		}
	}
	if (!check_nb(str, argc))
		return (1);
	i = 0;
	len = nb_int(str);	
	tab = (int *)malloc(sizeof(*tab) * (len + 1));
	if (!tab)
		return (1);
	while (i < len)
	{
		tab[i] = ft_atoi(str[i]);
		printf("%d\n", tab[i]);
		i++;
	}
	tab[i] = '\0';
	if (!check_duplicate(tab, len))
		return (1);
	return (0);
}
			//[i][i][i][i]
			//[j][j][j][j]
			//[j][j][j][j]
			//[j][j][j][j]
