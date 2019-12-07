/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:53:54 by rkina             #+#    #+#             */
/*   Updated: 2019/09/12 15:55:08 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	char			*ptr1;
	int				i;

	chr = (unsigned char)c;
	ptr1 = (char *)s;
	i = 0;
	while (ptr1[i])
		i++;
	while (ptr1[i] != chr && i >= 0)
		i--;
	if (i < 0)
		return (0);
	else
		return (ptr1 + i);
}
