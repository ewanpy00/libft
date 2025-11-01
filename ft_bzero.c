/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:26:18 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/10/29 13:55:36 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t len)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < len)
	{
		p[i] = 0;
		i++;
	}
}

// void print_array(unsigned char *arr, size_t len) {
//     for (size_t i = 0; i < len; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// // Function to compare both ft_bzero and original bzero
// void run_test_case(unsigned char *arr, size_t len) {
//     unsigned char ft_arr[len];
//     unsigned char original_arr[len];

//     // Copy original array into both arrays
//     memcpy(ft_arr, arr, len);
//     memcpy(original_arr, arr, len);

//     // Apply ft_bzero
//     ft_bzero(ft_arr, len);
//     printf("ft_bzero result: ");
//     print_array(ft_arr, len);

//     // Apply original bzero
//     bzero(original_arr, len);
//     printf("bzero result: ");
//     print_array(original_arr, len);

//     // Check if both results are identical
//     if (memcmp(ft_arr, original_arr, len) == 0) {
//         printf("Test passed: Both results match.\n\n");
//     } else {
//         printf("Test failed: Results do not match.\n\n");
//     }
// }

// int main() {
//     // Test case 1: Set a small array of size 5 to zero
//     printf("Test case 1: Small array of size 5\n");
//     unsigned char arr1[] = {1, 2, 3, 4, 5};
//     run_test_case(arr1, 5);

//     // Test case 2: Set a large array of size 10 to zero
//     printf("Test case 2: Large array of size 10\n");
//     unsigned char arr2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
//     run_test_case(arr2, 10);

//     // Test case 3: Set an empty array (size 0) to zero
//     printf("Test case 3: Empty array (size 0)\n");
//     unsigned char arr3[] = {};
//     run_test_case(arr3, 0);

//     // Test case 4: Set a single element array to zero
//     printf("Test case 4: Single element array (size 1)\n");
//     unsigned char arr4[] = {1};
//     run_test_case(arr4, 1);

//     // Test case 5: Set an array of size 1 with non-zero value to zero
//     printf("Test case 5: Single element array with non-zero value (size 1)\n");
//     unsigned char arr5[] = {255};
//     run_test_case(arr5, 1);

//     // Test case 6: Set a larger array to zero (edge case with larger memory)
//     printf("Test case 6: Larger array (size 1000)\n");
//     unsigned char arr6[1000];
//     for (size_t i = 0; i < 1000; i++) {
//         arr6[i] = i + 1;  // Fill with non-zero values
//     }
//     run_test_case(arr6, 1000);

//     return (0);
// }