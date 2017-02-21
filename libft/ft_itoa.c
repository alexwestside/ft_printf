/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 06:47:28 by orizhiy           #+#    #+#             */
/*   Updated: 2016/12/04 19:51:16 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int				len;
	unsigned int	num;
	char			*str;

	len = 0;
	len = ft_len_int(n);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (0);
	str[len--] = '\0';
	num = ft_int_min(n);
	while (len >= 0)
	{
		str[len--] = num % 10 + 48;
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
