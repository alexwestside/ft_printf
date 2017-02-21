/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:55:06 by orizhiy           #+#    #+#             */
/*   Updated: 2016/11/28 00:12:59 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *b;
	const char *l;

	if (!*little)
		return ((char*)big);
	while (*big)
	{
		b = big;
		l = little;
		while (*l && *b && *l == *b)
		{
			l++;
			b++;
		}
		if (!*l)
			return ((char*)big);
		big++;
	}
	return (NULL);
}
