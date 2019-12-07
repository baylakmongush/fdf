/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:31:52 by rkina             #+#    #+#             */
/*   Updated: 2019/09/22 17:31:17 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_atoi(const char *str)
{
	unsigned long long int	nbr;
	int						sign;
	int						i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
		nbr = nbr * 10 + str[i++] - 48;
	if (sign > 0 && nbr > 9223372036854775807ULL)
		return (-1);
	if (sign < 0 && nbr > 9223372036854775808ULL)
		return (0);
	return (nbr * sign);
}
