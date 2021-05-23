/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marczhan33@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:23:01 by mzhan             #+#    #+#             */
/*   Updated: 2021/05/23 14:34:35 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int		ft_wordcount(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static	char	*ft_wordcpy(char const *src, int n)
{
	char	*dest;

	if (!(dest = malloc((n + 1) * sizeof(char))))
		return (NULL);
	dest[n] = '\0';
	while (n--)
		dest[n] = src[n];
	return (dest);
}

static	int		ft_wordlength(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static	void	*ft_free_split(char **t, int columns)
{
	int i;

	i = 0;
	while (i < columns)
	{
		free(t[i++]);
	}
	free(t);
	return (NULL);
}

char			**ft_split(char *s, char c)
{
	char	**t;
	int		size;
	int		columns;
	int		i;
	int		n;

	size = ft_wordcount(s, c);
	if (!(t = (char **)malloc((size + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	columns = 0;
	while (columns < size)
	{
		while (s[i] && s[i] == c)
			i++;
		n = ft_wordlength(&s[i], c);
		if (!(t[columns] = ft_wordcpy(&s[i], n)))
			return (ft_free_split(t, columns));
		i = i + n;
		columns++;
	}
	t[size] = 0;
	return (t);
}
