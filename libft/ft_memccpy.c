/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:35:17 by orizhiy           #+#    #+#             */
/*   Updated: 2016/11/30 19:09:02 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *sorc, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char*)dest = *(unsigned char *)sorc;
		if (*(unsigned char *)sorc == (unsigned char)c)
			return (dest + 1);
		return (ft_memccpy(dest + 1, sorc + 1, c, n));
	}
	return (NULL);
}
