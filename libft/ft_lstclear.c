/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhan <mzhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:34:59 by mzhan             #+#    #+#             */
/*   Updated: 2021/01/31 21:25:52 by mzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_lstavance(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	else
	{
		ft_lstavance(lst->next, del);
		ft_lstdelone(lst, del);
	}
}

void			ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;

	if ((lst == NULL) || (*lst == NULL))
		return ;
	tmp = *lst;
	ft_lstavance(tmp, del);
	*lst = NULL;
}
