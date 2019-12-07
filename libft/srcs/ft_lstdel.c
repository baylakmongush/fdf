/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:56:53 by rkina             #+#    #+#             */
/*   Updated: 2019/09/21 15:05:17 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	t_list *tmp;

	if (alst && *alst && del)
	{
		ptr = *alst;
		while (ptr)
		{
			tmp = ptr->next;
			(*del)(ptr->content, ptr->content_size);
			free(ptr);
			ptr = tmp;
		}
		*alst = NULL;
	}
}
