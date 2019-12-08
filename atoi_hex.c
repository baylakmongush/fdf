/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 23:07:26 by rkina             #+#    #+#             */
/*   Updated: 2019/12/08 16:21:33 by npetrell         ###   ########.fr       */
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
    return (0);
}

int     atoi_hex(char *nbr)
{
    int res;
    int len;

    res = 0;
    len = 0;
    while (nbr[len])
        len++;
    len--;
    while (*nbr)
    {
        res += convert(*nbr) * power(16, len);
        nbr++;
        len--;
    }
    return (res);
}