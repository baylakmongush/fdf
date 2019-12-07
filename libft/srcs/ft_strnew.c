/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:32:47 by mgrass            #+#    #+#             */
/*   Updated: 2019/10/10 19:36:52 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *start;

	start = (char *)malloc((size + 1) * sizeof(*start));
	if (!start)
		return (NULL);
	ft_bzero(start, size + 1);
	return (start);
}
