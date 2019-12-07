/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:49:04 by rkina             #+#    #+#             */
/*   Updated: 2019/10/19 18:00:20 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*ft_getcurr(int fd, t_list **archive)
{
	t_list *tmp;

	if (!archive)
		return (NULL);
	tmp = *archive;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(archive, tmp);
	return (tmp);
}

static int			ft_read(const int fd, char **content)
{
	int				read_return;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];

	while ((read_return = read(fd, buf, BUFF_SIZE)))
	{
		buf[read_return] = '\0';
		tmp = *content;
		if (!(*content = ft_strjoin(*content, buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (read_return);
}

static int			ft_linecpy(char **line, char *content, char c)
{
	int				i;

	i = 0;
	while (content[i] && content[i] != c)
		i++;
	if (!(*line = ft_strndup(content, i)))
		return (0);
	return (i);
}

int					get_next_line(const int fd, char **line)
{
	size_t			read_return;
	static t_list	*archive;
	t_list			*current;
	char			*tmp;

	if (fd < 0 || !line || (read(fd, 0, 0)) < 0 ||
			(!(current = ft_getcurr(fd, &archive))))
		return (-1);
	tmp = current->content;
	read_return = ft_read(fd, &tmp);
	current->content = tmp;
	if (!read_return && !*tmp)
		return (0);
	read_return = ft_linecpy(line, current->content, '\n');
	tmp = current->content;
	if (tmp[read_return] != '\0')
	{
		current->content = ft_strdup(&((current->content)[read_return + 1]));
		free(tmp);
	}
	else
		tmp[0] = '\0';
	return (1);
}
