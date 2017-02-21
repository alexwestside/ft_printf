/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 02:34:52 by orizhiy           #+#    #+#             */
/*   Updated: 2016/12/05 12:45:34 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*f;

	if (!s || !(f = ft_strdup(s)))
		return (NULL);
	s = f;
	while (*f)
		f++;
	while (ft_isspace(*s))
		s++;
	while (ft_isspace(*f) || (*f == '\0'))
		f--;
	*++f = '\0';
	return (ft_strdup(s));
}
