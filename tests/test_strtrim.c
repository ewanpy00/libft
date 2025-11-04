/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <stdlib.h>

void test_strtrim(void)
{
	printf("\n=== Testing ft_strtrim ===\n");

	char *result;
	
	// Basic trim
	result = ft_strtrim("   hello world   ", " ");
	test_assert(result != NULL && strcmp(result, "hello world") == 0, "strtrim: basic spaces");
	free(result);
	
	// Leading only
	result = ft_strtrim("   hello", " ");
	test_assert(result != NULL && strcmp(result, "hello") == 0, "strtrim: leading spaces");
	free(result);
	
	// Trailing only
	result = ft_strtrim("hello   ", " ");
	test_assert(result != NULL && strcmp(result, "hello") == 0, "strtrim: trailing spaces");
	free(result);
	
	// No trimming needed
	result = ft_strtrim("hello", " ");
	test_assert(result != NULL && strcmp(result, "hello") == 0, "strtrim: no trim needed");
	free(result);
	
	// All trimmed
	result = ft_strtrim("   ", " ");
	test_assert(result != NULL && strcmp(result, "") == 0, "strtrim: all spaces");
	free(result);
	
	// Multiple characters in set
	result = ft_strtrim("xxhelloyy", "xy");
	test_assert(result != NULL && strcmp(result, "hello") == 0, "strtrim: multiple chars");
	free(result);
	
	// Empty string
	result = ft_strtrim("", " ");
	test_assert(result != NULL && strcmp(result, "") == 0, "strtrim: empty string");
	free(result);
	
	// Empty set
	result = ft_strtrim("hello", "");
	test_assert(result != NULL && strcmp(result, "hello") == 0, "strtrim: empty set");
	free(result);
	
	// Special characters
	result = ft_strtrim("\t\nhello\t\n", "\t\n");
	test_assert(result != NULL && strcmp(result, "hello") == 0, "strtrim: special chars");
	free(result);
	
	// NULL input
	result = ft_strtrim(NULL, " ");
	test_assert(result == NULL, "strtrim: NULL string");
}

