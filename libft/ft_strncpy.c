/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:44:56 by orizhiy           #+#    #+#             */
/*   Updated: 2016/12/05 19:36:55 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *sorc, size_t len)
{
	char *d;
	char *s;

	d = (char *)dest;
	s = (char *)sorc;
	while (*s && len > 0)
	{
		*d++ = *s++;
		len--;
	}
	while (len > 0)
	{
		*d++ = '\0';
		--len;
	}
	return (dest);
}
