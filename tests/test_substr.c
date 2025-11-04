/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <stdlib.h>

void test_substr(void)
{
	printf("\n=== Testing ft_substr ===\n");

	char *result;
	
	// Basic extraction
	result = ft_substr("Hello World", 6, 5);
	test_assert(result != NULL && strcmp(result, "World") == 0, "substr: basic extraction");
	free(result);
	
	// From beginning
	result = ft_substr("Hello World", 0, 5);
	test_assert(result != NULL && strcmp(result, "Hello") == 0, "substr: from beginning");
	free(result);
	
	// To end
	result = ft_substr("Hello World", 6, 10);
	test_assert(result != NULL && strcmp(result, "World") == 0, "substr: to end");
	free(result);
	
	// Len greater than remaining
	result = ft_substr("Hello World", 6, 20);
	test_assert(result != NULL && strcmp(result, "World") == 0, "substr: len > remaining");
	free(result);
	
	// Start at end
	result = ft_substr("Hello", 5, 5);
	test_assert(result != NULL && strcmp(result, "") == 0, "substr: start at end");
	free(result);
	
	// Start out of bounds
	result = ft_substr("Hello", 10, 5);
	test_assert(result != NULL && strcmp(result, "") == 0, "substr: start out of bounds");
	free(result);
	
	// Zero length
	result = ft_substr("Hello World", 6, 0);
	test_assert(result != NULL && strcmp(result, "") == 0, "substr: zero length");
	free(result);
	
	// Empty string
	result = ft_substr("", 0, 5);
	test_assert(result != NULL && strcmp(result, "") == 0, "substr: empty string");
	free(result);
	
	// Single character
	result = ft_substr("Hello", 0, 1);
	test_assert(result != NULL && strcmp(result, "H") == 0, "substr: single char");
	free(result);
	
	// Full string
	result = ft_substr("Hello", 0, 5);
	test_assert(result != NULL && strcmp(result, "Hello") == 0, "substr: full string");
	free(result);
	
	// NULL input (should handle gracefully or crash correctly)
	printf("[INFO] Testing NULL input (may crash)\n");
}

