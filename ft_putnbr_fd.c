/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:30:05 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/11/01 16:39:31 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ilength(long n){
    size_t len;

    len = 0;
    if(n < 0){
        n *= -1;
        len++;
    }
    while(n > 0){
        n = n / 10;
        len++;
    }
    return len;
}

char *make_str(long n, char *res, int i){
    int sign;

    res[i] = '\0';
    sign = 1;
    if(n == 0){
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    if(n < 0){
        n *= -1;
        sign = -1;
    }
    while(i > 0){
        res[i - 1] = n % 10 + '0';
        n = n / 10;
        i--;
    }
    if(sign == -1)
        res[0] = '-';
    return res;
}

char	*ft_itoa(int n){
    char *result;
    long num;
    int i;

    num = n;
    i = ilength(n);
    result = malloc(i + 1);
    if(!result)
        return NULL;
    return (make_str(num, result, i));
}

void ft_putnbr_fd(int n, int fd){
    char *str;

    str = ft_itoa(n);
    while(*str){
        write(fd, &*str, 1);
        str++;
    }
}

int main(){
    ft_putnbr_fd(1234567, 1);
}