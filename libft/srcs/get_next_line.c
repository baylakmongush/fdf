/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:39:27 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/23 21:57:41 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*check_fd(const int fd, t_list **fd_lst)
{
	t_list			*lst;

	lst = *fd_lst;
	while (lst)
	{
		if ((int)(lst->content_size) == fd)
			return (lst);
		lst = lst->next;
	}
	lst = ft_lstnew("", fd);
	ft_lstadd(fd_lst, lst);
	return (lst);
}

int					read_from_fd(const int fd, char **content)
{
	char			buff[BUFF_SIZE + 1];
	int				size_read;
	char			*tmp;

	while ((size_read = read(fd, buff, BUFF_SIZE)))
	{
		buff[size_read] = '\0';
		tmp = ft_strjoin(*content, buff);
		free(*content);
		*content = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (size_read);
}

int					count(char *str)
{
	int				i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int					get_next_line(const int fd, char **line)
{
	t_list			*lst;
	static t_list	*fd_lst;
	char			*content;
	int				size_read;
	char			buff[BUFF_SIZE];

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0 || BUFF_SIZE < 0)
		return (-1);
	lst = check_fd(fd, &fd_lst);
	content = lst->content;
	size_read = read_from_fd(fd, &content);
	lst->content = content;
	if (size_read == 0 && (content == 0 || content[0] == '\0'))
		return (0);
	size_read = count(content);
	content = lst->content;
	*line = ft_strsub(lst->content, 0, size_read);
	if (content[size_read] == '\0')
		ft_strclr(content);
	else
	{
		lst->content = ft_strdup((char*)lst->content + size_read + 1);
		free(content);
	}
	return (1);
}
