/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <stdlib.h>

static void free_split(char **arr)
{
	int i = 0;
	if (!arr)
		return;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int count_array(char **arr)
{
	int i = 0;
	if (!arr)
		return -1;
	while (arr[i])
		i++;
	return i;
}

void test_split(void)
{
	printf("\n=== Testing ft_split ===\n");

	char **result;
	
	// Basic split
	result = ft_split("hello world", ' ');
	test_assert(result != NULL && count_array(result) == 2 && strcmp(result[0], "hello") == 0 && strcmp(result[1], "world") == 0, "split: basic split");
	free_split(result);
	
	// Leading delimiters
	result = ft_split("   hello world", ' ');
	test_assert(result != NULL && count_array(result) == 2, "split: leading delimiters");
	free_split(result);
	
	// Trailing delimiters
	result = ft_split("hello world   ", ' ');
	test_assert(result != NULL && count_array(result) == 2, "split: trailing delimiters");
	free_split(result);
	
	// Multiple delimiters
	result = ft_split("hello   world", ' ');
	test_assert(result != NULL && count_array(result) == 2, "split: multiple delimiters");
	free_split(result);
	
	// Empty string
	result = ft_split("", ' ');
	test_assert(result != NULL && count_array(result) == 0, "split: empty string");
	free_split(result);
	
	// No delimiter
	result = ft_split("hello", ' ');
	test_assert(result != NULL && count_array(result) == 1 && strcmp(result[0], "hello") == 0, "split: no delimiter");
	free_split(result);
	
	// Only delimiters
	result = ft_split("   ", ' ');
	test_assert(result != NULL && count_array(result) == 0, "split: only delimiters");
	free_split(result);
	
	// Multiple words
	result = ft_split("one two three four", ' ');
	test_assert(result != NULL && count_array(result) == 4, "split: multiple words");
	free_split(result);
	
	// Different delimiter
	result = ft_split("a/b/c/d", '/');
	test_assert(result != NULL && count_array(result) == 4, "split: different delimiter");
	free_split(result);
	
	// NULL input
	result = ft_split(NULL, ' ');
	test_assert(result == NULL, "split: NULL input");
}

