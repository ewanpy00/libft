/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"

static void uppercase_i(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

static void add_index_i(unsigned int i, char *c)
{
	*c = *c + i;
}

static void set_to_index(unsigned int i, char *c)
{
	*c = '0' + (i % 10);
}

void test_striteri(void)
{
	printf("\n=== Testing ft_striteri ===\n");

	char str1[] = "hello";
	char str2[] = "hello";
	ft_striteri(str1, uppercase_i);
	// Manual uppercase for comparison
	for (int i = 0; str2[i]; i++)
		if (str2[i] >= 'a' && str2[i] <= 'z')
			str2[i] -= 32;
	test_assert(strcmp(str1, str2) == 0 && strcmp(str1, "HELLO") == 0, "striteri: uppercase");
	
	// Add index
	char str3[] = "abc";
	char expected[] = "ace"; // a+0, b+1, c+2
	ft_striteri(str3, add_index_i);
	test_assert(strcmp(str3, expected) == 0, "striteri: add index");
	
	// Set to index
	char str4[] = "xxxxx";
	ft_striteri(str4, set_to_index);
	test_assert(str4[0] == '0' && str4[1] == '1' && str4[2] == '2' && str4[3] == '3' && str4[4] == '4', "striteri: set to index");
	
	// Empty string
	char str5[] = "";
	ft_striteri(str5, uppercase_i);
	test_assert(strcmp(str5, "") == 0, "striteri: empty string");
	
	// Single character
	char str6[] = "a";
	ft_striteri(str6, uppercase_i);
	test_assert(strcmp(str6, "A") == 0, "striteri: single char");
	
	// NULL input (should handle gracefully or crash)
	printf("[INFO] Testing NULL input (may crash)\n");
}

