/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <stdlib.h>
#include <string.h>

void test_calloc(void)
{
	printf("\n=== Testing ft_calloc ===\n");

	// Basic allocation
	void *ptr1 = ft_calloc(10, sizeof(int));
	void *orig1 = calloc(10, sizeof(int));
	test_assert(ptr1 != NULL && orig1 != NULL, "calloc: basic allocation");
	if (ptr1 && orig1)
		test_assert(memcmp(ptr1, orig1, 10 * sizeof(int)) == 0, "calloc: zero initialization");
	free(ptr1);
	free(orig1);
	
	// Single element
	void *ptr2 = ft_calloc(1, sizeof(char));
	void *orig2 = calloc(1, sizeof(char));
	test_assert(ptr2 != NULL && orig2 != NULL, "calloc: single element");
	if (ptr2 && orig2)
		test_assert(memcmp(ptr2, orig2, 1) == 0, "calloc: single element zero");
	free(ptr2);
	free(orig2);
	
	// Large allocation
	void *ptr3 = ft_calloc(1000, sizeof(char));
	void *orig3 = calloc(1000, sizeof(char));
	test_assert(ptr3 != NULL && orig3 != NULL, "calloc: large allocation");
	if (ptr3 && orig3)
	{
		int all_zero = 1;
		char *p = (char *)ptr3;
		for (int i = 0; i < 1000; i++)
		{
			if (p[i] != 0)
			{
				all_zero = 0;
				break;
			}
		}
		test_assert(all_zero == 1, "calloc: large zero initialization");
	}
	free(ptr3);
	free(orig3);
	
	// Zero size
	void *ptr4 = ft_calloc(0, sizeof(int));
	void *orig4 = calloc(0, sizeof(int));
	// Result is implementation-defined, just check no crash
	test_assert(1, "calloc: zero size (no crash)");
	if (ptr4) free(ptr4);
	if (orig4) free(orig4);
	
	// Zero count
	void *ptr5 = ft_calloc(10, 0);
	void *orig5 = calloc(10, 0);
	test_assert(1, "calloc: zero element size (no crash)");
	if (ptr5) free(ptr5);
	if (orig5) free(orig5);
	
	// String allocation
	char *ptr6 = (char *)ft_calloc(100, sizeof(char));
	char *orig6 = (char *)calloc(100, sizeof(char));
	test_assert(ptr6 != NULL && orig6 != NULL, "calloc: string allocation");
	if (ptr6 && orig6)
	{
		strcpy(ptr6, "test");
		strcpy(orig6, "test");
		test_assert(strcmp(ptr6, orig6) == 0, "calloc: string usage");
	}
	free(ptr6);
	free(orig6);
}

