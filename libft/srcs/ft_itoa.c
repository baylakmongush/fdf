/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:00:50 by rkina             #+#    #+#             */
/*   Updated: 2019/09/21 15:42:05 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		j;
	char	*s;

	j = ft_nbrlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = (char *)malloc(sizeof(char) * (ft_nbrlen(n) + 1));
	if (s == NULL)
		return (NULL);
	s[j--] = '\0';
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (n > 9)
	{
		s[j--] = n % 10 + '0';
		n /= 10;
	}
	s[j] = n + '0';
	return (s);
}
