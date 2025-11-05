/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:54:29 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/11/05 15:58:22 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	long long		result;
	int				sign;
	unsigned int	digit;

	result = 0;
	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		if (result > (long long)(LLONG_MAX / 10)
			|| (result == (long long)(LLONG_MAX / 10)
				&& (long long)digit > (long long)(LLONG_MAX % 10)))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		result = result * 10 + digit;
		str++;
	}
	return ((int)result * sign);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*str0 = "2147483648";
// 	const char	*str1 = 
//" -100000000000000000000000000000000000000000000
//00000000000000000000000000000";
// 	const char	*str2 = "42";
// 	const char	*str3 = "  +99";
// 	const char	*str4 = "   0005";
// 	const char	*str5 = "abc";

// 	// Invalid input; should return 0
// 	printf("Result 1: %d / %d\n", ft_atoi(str0), atoi(str0)); // Expected: -1234
// 	printf("Result 1: %d / %d\n", ft_atoi(str1), atoi(str1)); // Expected: -1234
// 	printf("Result 2: %d\n", ft_atoi(str2));                  // Expected: 42
// 	printf("Result 3: %d\n", ft_atoi(str3));                  // Expected: 99
// 	printf("Result 4: %d\n", ft_atoi(str4));                  // Expected: 5
// 	printf("Result 5: %d\n", ft_atoi(str5));
// 	// Expected: 0 (invalid input)
// 	return (0);
// }
