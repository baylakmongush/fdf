/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:29:25 by rkina             #+#    #+#             */
/*   Updated: 2019/12/10 16:54:20 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		check_el(char *el)
{
	int			i;

	i = 0;
	if (el[i] == '-')
		i++;
	while (el[i] >= '0' && el[i] <= '9')
		i++;
	if (el[i] == ',')
	{
		if (el[i + 1] != '0' && el[i + 2] != 'x')
			ft_err();
		i += 3;
		while ((el[i] >= '0' && el[i] <= '9') || (el[i] >= 'A' && el[i] <= 'F') || (el[i] >= 'a' && el[i] <= 'f'))
			i++;
		if (el[i] != '\0')
			ft_err();
	}
	if (el[i] != '\0')
		ft_err();
}

int				count_size(char *line)
{
	int			size;
	char		**tmp;

	tmp = ft_strsplit((const char*)line, ' ');
	size = 0;
	while (tmp[size])
	{
		check_el(tmp[size]);
		free(tmp[size]);
		size++;
	}
	free(tmp);
	return (size);
}

static void		check_file(char *file_name)
{
	if (ft_strstr(file_name, ".fdf") == 0)
		ft_err();
}

void			check_valid(char *file_name)
{
	char		*line;
	int			size;
	int			next_size;
	int			fd;

	check_file(file_name);
	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	size = count_size(line);
	while (get_next_line(fd, &line) > 0)
	{
		next_size = count_size(line);
		if (next_size != size)
			ft_err();
	}
}
