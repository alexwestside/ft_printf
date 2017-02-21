/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:10:00 by orizhiy           #+#    #+#             */
/*   Updated: 2016/12/05 14:07:44 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	char	*p1;
	char	**p2;

	if (!s || !(res = malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	p2 = res;
	while (*s)
	{
		while (*s == c && *s && s++)
			;
		if (*s)
		{
			if (!(p1 = malloc(ft_len_char(s, c) + 1)))
				return (NULL);
			*res = p1;
			while (*s != c && *s && (*p1++ = *s++))
				;
			*p1 = '\0';
			res++;
		}
	}
	*res = NULL;
	return (p2);
}
