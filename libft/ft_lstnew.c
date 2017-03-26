/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:26:02 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/02 15:06:01 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->next = NULL;
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	if ((new->content = (void*)malloc(sizeof(void) * (content_size + 1))) \
		== NULL)
		return (NULL);
	new->content = ft_memmove(new->content, content, content_size);
	new->content_size = content_size;
	return (new);
}
