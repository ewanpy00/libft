/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:51:33 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/11/05 10:57:47 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	if(!dest && !src)
		return NULL;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
