/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:20:56 by mgrass            #+#    #+#             */
/*   Updated: 2019/10/10 15:56:48 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		i = -1;
		j = 0;
		if (!(res = (char *)malloc(sizeof(char) * len1
		+ len2 + 1)))
			return (NULL);
		while (++i < len1)
			res[i] = s1[i];
		while (j < len2)
			res[i++] = s2[j++];
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
