/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:55:16 by tbergkul          #+#    #+#             */
/*   Updated: 2019/10/24 15:01:07 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*element;

	if (!lst || !f)
		return (NULL);
	element = f(lst);
	newlst = element;
	while (lst->next)
	{
		lst = lst->next;
		if (!(element->next = f(lst)))
		{
			free(element->next);
			return (NULL);
		}
		element = element->next;
	}
	return (newlst);
}
