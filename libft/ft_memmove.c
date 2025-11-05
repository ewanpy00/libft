/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:50:15 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/11/05 11:10:27 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;

	if (!src && !dest)
		return (NULL);
	if (dest == src || len == 0)
		return (dest);
	s = (unsigned const char *)src;
	d = (unsigned char *)dest;
	if (s > d)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		s += len;
		d += len;
		while (len--)
			*(--d) = *(--s);
	}
	return (dest);
}
