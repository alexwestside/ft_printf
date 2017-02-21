/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:59:13 by orizhiy           #+#    #+#             */
/*   Updated: 2016/12/02 14:48:36 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *sorc, size_t n)
{
	(sorc > dest) ? ft_memcpy(dest, sorc, n) : ft_memcpy_rev(dest, sorc, n);
	return (dest);
}
