/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <stdlib.h>

void test_strdup(void)
{
	printf("\n=== Testing ft_strdup ===\n");

	// Basic strings
	char *dup1 = ft_strdup("hello");
	char *orig1 = strdup("hello");
	test_assert(strcmp(dup1, orig1) == 0, "strdup: basic string");
	free(dup1);
	free(orig1);
	
	// Empty string
	char *dup2 = ft_strdup("");
	char *orig2 = strdup("");
	test_assert(strcmp(dup2, orig2) == 0, "strdup: empty string");
	free(dup2);
	free(orig2);
	
	// Single character
	char *dup3 = ft_strdup("a");
	char *orig3 = strdup("a");
	test_assert(strcmp(dup3, orig3) == 0, "strdup: single char");
	free(dup3);
	free(orig3);
	
	// Long string
	char long_str[1000];
	memset(long_str, 'a', 999);
	long_str[999] = '\0';
	char *dup4 = ft_strdup(long_str);
	char *orig4 = strdup(long_str);
	test_assert(strcmp(dup4, orig4) == 0, "strdup: long string");
	free(dup4);
	free(orig4);
	
	// Special characters
	char *dup5 = ft_strdup("test\n\t");
	char *orig5 = strdup("test\n\t");
	test_assert(strcmp(dup5, orig5) == 0, "strdup: special chars");
	free(dup5);
	free(orig5);
	
	// String with spaces
	char *dup6 = ft_strdup("hello world");
	char *orig6 = strdup("hello world");
	test_assert(strcmp(dup6, orig6) == 0, "strdup: string with spaces");
	free(dup6);
	free(orig6);
	
	// Null in string (should copy until null)
	char *dup7 = ft_strdup("test\0hidden");
	char *orig7 = strdup("test\0hidden");
	test_assert(strcmp(dup7, orig7) == 0, "strdup: null in string");
	free(dup7);
	free(orig7);
}

