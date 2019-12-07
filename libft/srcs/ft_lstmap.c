/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:56:59 by rkina             #+#    #+#             */
/*   Updated: 2019/09/22 17:50:19 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ptr;

	if (lst && f)
	{
		while (lst)
		{
			ptr = (*f)(lst);
			ptr->next = ft_lstmap(lst->next, f);
			return (ptr);
		}
	}
	return (NULL);
}
