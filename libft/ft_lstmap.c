/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:16:42 by euhong            #+#    #+#             */
/*   Updated: 2021/05/10 19:38:57 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	if (!(temp = (ft_lstnew((*f)(lst->content)))))
		return (NULL);
	res = temp;
	lst = lst->next;
	while (lst)
	{
		if (!(temp->next = (ft_lstnew((*f)(lst->content)))))
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (res);
}
