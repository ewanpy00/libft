/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:14:53 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/11/03 16:44:14 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*p;

	p = NULL;
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)c)
			p = (char *)str;
		str++;
	}
	if((unsigned char)*str == (unsigned char)c)
		return (char *) str;
	return p;
}
