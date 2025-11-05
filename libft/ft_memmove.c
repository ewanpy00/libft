/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:50:15 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/11/05 13:24:08 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;

	if (!src && !dest && len != 0)
		return (NULL);
	s = (unsigned const char *)src;
	d = (unsigned char *)dest;
	if (s > d)
		ft_memcpy(d, s, len);
	else
	{
		while(len--)
			d[len] = s[len];
	}
	return (dest);
}
