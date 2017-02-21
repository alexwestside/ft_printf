/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:22:36 by orizhiy           #+#    #+#             */
/*   Updated: 2016/12/01 11:47:54 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *sorc, size_t n)
{
	char *s;
	char *d;

	s = (char *)sorc;
	d = (char *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}
