/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:10:33 by orizhiy           #+#    #+#             */
/*   Updated: 2016/12/05 12:34:33 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy_rev(void *dest, const void *sorc, size_t n)
{
	char *s;
	char *d;

	s = (char *)sorc;
	d = (char *)dest;
	while (n--)
		d[n] = s[n];
	return (dest);
}
