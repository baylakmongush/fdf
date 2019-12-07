/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:56:51 by rkina             #+#    #+#             */
/*   Updated: 2019/09/21 15:05:10 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;

	if (alst && *alst && del)
	{
		ptr = *alst;
		(*del)(ptr->content, ptr->content_size);
		free(ptr);
		*alst = NULL;
	}
}
