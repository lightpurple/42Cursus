/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:15:40 by euhong            #+#    #+#             */
/*   Updated: 2021/05/05 23:17:46 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if ((unsigned char)c > 'A' && (unsigned char)c < 'Z')
		return (1);
	else if ((unsigned char)c > 'a' && (unsigned char)c < 'z')
		return (1);
	else
		return (0);
}
