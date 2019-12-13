/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:13:51 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/13 15:36:25 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int     power(int nbr, int pow)
{
    int res;

    res = nbr;
    if (pow == 0)
        return (1);
    while (pow > 1)
    {
        res *= nbr;
        pow--;
    }
    return (res);
}

static int     convert(char c)
{
	if (c >= '0' && c <= '9')
		return  (c - 48);
	else if (c >= 'A' && c <= 'F')
		return  (c - 55);
    else if (c >= 'a' && c <= 'f')
		return (c - 87);
    return (0);
}

int			atoi_hex(char *nb)
{
	int		result;
	int		length;

	result = 0;
	length = ft_strlen(nb) - 1;
	while (*nb && length >= 0)
	{
		result += convert(*nb) * power(16, length);
		nb++;
		length--;
	}
	return (result);
}
