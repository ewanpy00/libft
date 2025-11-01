/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:45:44 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/10/29 13:52:45 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t i;

	i = 0;
	unsigned char *p = (unsigned char *)s;
	while (i < len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}