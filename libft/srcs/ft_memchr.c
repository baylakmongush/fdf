/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:42:01 by rkina             #+#    #+#             */
/*   Updated: 2019/09/21 18:30:39 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr1;

	ptr1 = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*ptr1 == (unsigned char)c)
			return (ptr1);
		ptr1++;
	}
	return (0);
}
