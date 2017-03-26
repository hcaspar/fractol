/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:04:24 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/16 20:53:41 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*prev;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	prev = new;
	while (lst->next)
	{
		lst = lst->next;
		prev->next = f(lst);
		prev = prev->next;
	}
	return (new);
}
