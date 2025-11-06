/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:54:29 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/11/06 15:10:32 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <limits.h>

static int	skip_spaces_and_sign(const char **str)
{
	int	sign;

	sign = 1;
	while ((**str >= '\t' && **str <= '\r') || **str == ' ')
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int	check_overflow(long long result, int digit, int sign)
{
	if (result > LLONG_MAX / 10
		|| (result == LLONG_MAX / 10 && digit > (LLONG_MAX % 10)))
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (42);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;
	int			digit;
	int			overflow;

	result = 0;
	sign = skip_spaces_and_sign(&str);
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		overflow = check_overflow(result, digit, sign);
		if (overflow != 42)
			return (overflow);
		result = result * 10 + digit;
		str++;
	}
	return ((int)(result * sign));
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	const char	*str0 = "2147483648";
// 	const char	*str1 = " -10000000000000000000000000000000000000000000000000000000000000000000000000";
// 	const char	*str2 = "42";
// 	const char	*str3 = "  +99";
// 	const char	*str4 = "   0005";
// 	const char	*str5 = "abc";

// 	// Invalid input; should return 0
// 	printf("Result 1: %d / %d\n", ft_atoi(str0), atoi(NULL)); // Expected: -1234
// 	printf("Result 1: %d / %d\n", ft_atoi(str1), atoi(str1)); // Expected: -1234
// 	printf("Result 2: %d\n", ft_atoi(str2));                  // Expected: 42
// 	printf("Result 3: %d\n", ft_atoi(str3));                  // Expected: 99
// 	printf("Result 4: %d\n", ft_atoi(str4));                  // Expected: 5
// 	printf("Result 5: %d\n", ft_atoi(str5));
// 	// Expected: 0 (invalid input)
// 	return (0);
// }
