/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <stdlib.h>

static char uppercase(unsigned int i, char c)
{
	(void)i;
	return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

static char add_index(unsigned int i, char c)
{
	return c + i;
}

static char identity(unsigned int i, char c)
{
	(void)i;
	return c;
}

void test_strmapi(void)
{
	printf("\n=== Testing ft_strmapi ===\n");

	char *result;
	
	// Uppercase function
	result = ft_strmapi("hello", uppercase);
	test_assert(result != NULL && strcmp(result, "HELLO") == 0, "strmapi: uppercase");
	free(result);
	
	// Add index
	result = ft_strmapi("abc", add_index);
	test_assert(result != NULL && result[0] == 'a' && result[1] == 'c' && result[2] == 'e', "strmapi: add index");
	free(result);
	
	// Identity function
	result = ft_strmapi("test", identity);
	test_assert(result != NULL && strcmp(result, "test") == 0, "strmapi: identity");
	free(result);
	
	// Empty string
	result = ft_strmapi("", identity);
	test_assert(result != NULL && strcmp(result, "") == 0, "strmapi: empty string");
	free(result);
	
	// Single character
	result = ft_strmapi("a", uppercase);
	test_assert(result != NULL && strcmp(result, "A") == 0, "strmapi: single char");
	free(result);
	
	// NULL input
	result = ft_strmapi(NULL, identity);
	test_assert(result == NULL, "strmapi: NULL input");
}

