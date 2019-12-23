/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:19:29 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/23 23:03:07 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		rotate_x(int *y, int *z, int multi, double alpha)
{
	int			previous_y;
	int			previous_z;
	double		angle;

	angle = multi * alpha;
	previous_y = *y;
	previous_z = *z;
	*y = previous_y * cos(angle) + previous_z * sin(angle);
	*z = -previous_y * sin(angle) + previous_z * cos(angle);
}

void		rotate_y(int *x, int *z, int multi, double alpha)
{
	int			previous_x;
	int			previous_z;
	double		angle;

	angle = multi * alpha;
	previous_x = *x;
	previous_z = *z;
	*x = previous_x * cos(angle) + previous_z * sin(angle);
	*z = -previous_x * sin(angle) + previous_z * cos(angle);
}

void		rotate_z(int *x, int *y, int multi, double alpha)
{
	int			previous_x;
	int			previous_y;
	double		angle;

	angle = multi * alpha;
	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(angle) - previous_y * sin(angle);
	*y = previous_x * sin(angle) + previous_y * cos(angle);
}
