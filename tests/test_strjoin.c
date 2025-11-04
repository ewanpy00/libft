/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <stdlib.h>

void test_strjoin(void)
{
	printf("\n=== Testing ft_strjoin ===\n");

	char *result;
	
	// Basic join
	result = ft_strjoin("Hello, ", "World!");
	test_assert(result != NULL && strcmp(result, "Hello, World!") == 0, "strjoin: basic join");
	free(result);
	
	// First empty
	result = ft_strjoin("", "World!");
	test_assert(result != NULL && strcmp(result, "World!") == 0, "strjoin: first empty");
	free(result);
	
	// Second empty
	result = ft_strjoin("Hello, ", "");
	test_assert(result != NULL && strcmp(result, "Hello, ") == 0, "strjoin: second empty");
	free(result);
	
	// Both empty
	result = ft_strjoin("", "");
	test_assert(result != NULL && strcmp(result, "") == 0, "strjoin: both empty");
	free(result);
	
	// Long strings
	result = ft_strjoin("This is a longer string, ", "and this is another one.");
	test_assert(result != NULL && strlen(result) == strlen("This is a longer string, ") + strlen("and this is another one."), "strjoin: long strings");
	free(result);
	
	// Special characters
	result = ft_strjoin("Line1\n", "Line2\tTabbed");
	test_assert(result != NULL && strcmp(result, "Line1\nLine2\tTabbed") == 0, "strjoin: special chars");
	free(result);
	
	// Single characters
	result = ft_strjoin("a", "b");
	test_assert(result != NULL && strcmp(result, "ab") == 0, "strjoin: single chars");
	free(result);
	
	// NULL inputs (should return NULL)
	result = ft_strjoin(NULL, "test");
	test_assert(result == NULL, "strjoin: NULL first");
	
	result = ft_strjoin("test", NULL);
	test_assert(result == NULL, "strjoin: NULL second");
	
	result = ft_strjoin(NULL, NULL);
	test_assert(result == NULL, "strjoin: both NULL");
}

