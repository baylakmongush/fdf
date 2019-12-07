/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:28:16 by rkina             #+#    #+#             */
/*   Updated: 2019/09/22 14:34:19 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_arrdel(void **res)
{
	void		**tmp;

	tmp = res;
	while (res && *res)
		free(*res++);
	free(tmp);
	tmp = NULL;
	return (tmp);
}

static int		ft_countwrd(char const *s, char c)
{
	int			countwrd;
	size_t		i;

	countwrd = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			countwrd++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (countwrd);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**words;
	size_t		nbr_words;
	size_t		i;
	size_t		k;

	if (!s || !(words = (char**)malloc(sizeof(*words) *
			((nbr_words = ft_countwrd(s, c)) + 1))))
		return (NULL);
	k = -1;
	while (++k < nbr_words)
	{
		while (*s == c)
			s++;
		i = 0;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (!(words[k] = ft_strnew(i)))
			return (ft_arrdel((void**)words));
		else if (!(i = 0))
			while (*s != c && *s)
				words[k][i++] = *s++;
	}
	words[k] = 0;
	return (words);
}
