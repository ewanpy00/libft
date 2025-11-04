/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <stdlib.h>
#include <limits.h>

void test_itoa(void)
{
	printf("\n=== Testing ft_itoa ===\n");

	char *result;
	char buffer[20];
	
	// Zero
	result = ft_itoa(0);
	test_assert(result != NULL && strcmp(result, "0") == 0, "itoa: zero");
	free(result);
	
	// Positive
	result = ft_itoa(42);
	test_assert(result != NULL && strcmp(result, "42") == 0, "itoa: positive");
	free(result);
	
	// Negative
	result = ft_itoa(-42);
	test_assert(result != NULL && strcmp(result, "-42") == 0, "itoa: negative");
	free(result);
	
	// INT_MAX
	sprintf(buffer, "%d", INT_MAX);
	result = ft_itoa(INT_MAX);
	test_assert(result != NULL && strcmp(result, buffer) == 0, "itoa: INT_MAX");
	free(result);
	
	// INT_MIN
	sprintf(buffer, "%d", INT_MIN);
	result = ft_itoa(INT_MIN);
	test_assert(result != NULL && strcmp(result, buffer) == 0, "itoa: INT_MIN");
	free(result);
	
	// Single digit positive
	result = ft_itoa(1);
	test_assert(result != NULL && strcmp(result, "1") == 0, "itoa: single digit pos");
	free(result);
	
	// Single digit negative
	result = ft_itoa(-1);
	test_assert(result != NULL && strcmp(result, "-1") == 0, "itoa: single digit neg");
	free(result);
	
	// Large positive
	result = ft_itoa(123456789);
	test_assert(result != NULL && strcmp(result, "123456789") == 0, "itoa: large positive");
	free(result);
	
	// Large negative
	result = ft_itoa(-987654321);
	test_assert(result != NULL && strcmp(result, "-987654321") == 0, "itoa: large negative");
	free(result);
	
	// Powers of 10
	result = ft_itoa(10);
	test_assert(result != NULL && strcmp(result, "10") == 0, "itoa: power of 10");
	free(result);
	
	result = ft_itoa(100);
	test_assert(result != NULL && strcmp(result, "100") == 0, "itoa: 100");
	free(result);
	
	result = ft_itoa(1000);
	test_assert(result != NULL && strcmp(result, "1000") == 0, "itoa: 1000");
	free(result);
}

