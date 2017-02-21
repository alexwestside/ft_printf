/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:36:25 by orizhiy           #+#    #+#             */
/*   Updated: 2016/12/02 13:02:54 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *p;
	char *pp;

	if (s && f)
	{
		if ((p = ft_strnew(ft_strlen(s))))
		{
			pp = p;
			while (*s)
			{
				*p++ = (*f)(*s);
				s++;
			}
			return (pp);
		}
	}
	return (NULL);
}
