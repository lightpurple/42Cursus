/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:27:02 by euhong            #+#    #+#             */
/*   Updated: 2021/05/10 11:11:40 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	if (!*lst)
	{
		free(lst);
		return ;
	}
	temp = (*lst)->next;
	del(*lst);
	while (temp)
	{
		*lst = temp;
		temp = temp->next;
		del(*lst);
	}
	free(lst);
}
