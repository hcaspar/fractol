/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:41:34 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/14 13:19:59 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->content && (*alst)->content_size)
		del((*alst)->content, (*alst)->content_size);
	if (*alst)
		free(*alst);
	*alst = NULL;
}
