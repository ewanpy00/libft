/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:26:13 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/11/01 15:42:36 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char)){
    char *res;
    size_t i;

    i = 0;
    while(s[i])
        i++;
    res = malloc(i + 1);
    if(!res)
        return NULL;
    i = 0;
    while(s[i]){
        res[i] = f(i, s[i]);
        i++;
    }
    res[i] = '\0';
    return res;
}

int main(){
    
}