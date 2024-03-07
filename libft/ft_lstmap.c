/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:42:50 by ealbayra          #+#    #+#             */
/*   Updated: 2023/11/05 14:42:50 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ad;
	t_list	*ap;

	ad = NULL;
	while (lst)
	{
		ap = ft_lstnew(f(lst -> content));
		if (!ap)
		{
			ft_lstclear(&ad, del);
			return (NULL);
		}
		ft_lstadd_back(&ad, ap);
		lst = lst -> next;
	}
	return (ad);
}
