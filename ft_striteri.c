/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:36:48 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/11/01 16:22:22 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*)){
    size_t i;

    i = 0;
    while(s[i])
    {
        f(i, &s[i]);
        i++;
    }
    return s;
}