/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:54:29 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/10/29 14:14:34 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str > 1 && *str <= 31) || *str == ' ')
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
		result = result * 10 + *str - '0';
		str++;
	}
	if (sign == -1)
		result *= -1;
	return (result);
}

#include <stdio.h>

int	main(void)
{
	const char	*str1 = "  100000000000000000000000";
	const char	*str2 = "42";
	const char	*str3 = "  +99";
	const char	*str4 = "   0005";
	const char	*str5 = "abc";

	// Invalid input; should return 0
	printf("Result 1: %d / %d\n", ft_atoi(str1), atoi(str1)); // Expected: -1234
	printf("Result 2: %d\n", ft_atoi(str2));                  // Expected: 42
	printf("Result 3: %d\n", ft_atoi(str3));                  // Expected: 99
	printf("Result 4: %d\n", ft_atoi(str4));                  // Expected: 5
	printf("Result 5: %d\n", ft_atoi(str5));
	// Expected: 0 (invalid input)
	return (0);
}
