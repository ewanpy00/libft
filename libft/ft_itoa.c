/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:49:26 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/11/05 15:44:20 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ilength(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len += 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*make_str(long n, char *res, int i)
{
	int	sign;

	res[i] = '\0';
	sign = 1;
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	if (n < 0)
	{
		n *= -1;
		sign = -1;
	}
	while (i > 0)
	{
		res[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	num;
	int		i;

	num = n;
	i = ilength(n);
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	return (make_str(num, result, i));
}

// int main(void)
// {
//     int tests[] = {
//         0,
//         1,
//         -1,
//         42,
//         -42,
//         123456789,
//         -987654321,
//         2147483647,
//         -2147483648
//     };

//     int num_tests = sizeof(tests) / sizeof(tests[0]);

//     printf("=== Testing ft_itoa ===\n\n");

//     for (int i = 0; i < num_tests; i++)
//     {
//         char *result = ft_itoa(tests[i]);
//         if (result == NULL)
//         {
//             printf("Test %d: ft_itoa(%d) returned NULL ❌\n", i + 1,
// tests[i]);
//             continue ;
//         }
//         printf("Test %2d: ft_itoa(%d) -> \"%s\"\n", i + 1, tests[i], result);
//         free(result); // important if your ft_itoa uses malloc
//     }

//     printf("\nAll tests completed ✅\n");
//     return (0);
// }