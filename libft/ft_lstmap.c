/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <marczhan33@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 13:44:44 by mzhan             #+#    #+#             */
/*   Updated: 2021/02/02 19:28:12 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;
	void	*tmp;

	start = NULL;
	while (lst)
	{
		if (!(tmp = (*f)(lst->content)))
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		new = ft_lstnew(tmp);
		if (new == NULL)
		{
			ft_lstclear(&start, del);
			del(tmp);
			return (start);
		}
		ft_lstadd_back(&start, new);
		lst = lst->next;
	}
	return (start);
}
