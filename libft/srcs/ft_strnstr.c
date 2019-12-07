/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:19:56 by rkina             #+#    #+#             */
/*   Updated: 2019/09/22 18:35:01 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = ft_strlen(needle);
	if (!size)
		return ((char*)haystack);
	while (len && haystack[i])
	{
		j = 0;
		if (len < size)
			return (NULL);
		while ((needle[j] == haystack[j + i]))
		{
			if (j++ == size - 1)
				return ((char*)haystack + i);
		}
		len--;
		i++;
	}
	return (NULL);
}
