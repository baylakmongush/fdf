/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:22:33 by mgrass            #+#    #+#             */
/*   Updated: 2019/09/22 17:36:06 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	int	i;
	int	j;

	i = 0;
	if (s)
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		j = ft_strlen(s);
		if (!j && !i)
			return (ft_strdup(s));
		while (s[j - 1] && ft_isspace(s[j - 1]))
			j--;
		if (j < i)
			j = i;
		return (ft_strsub(s, i, (j - i)));
	}
	return (NULL);
}
