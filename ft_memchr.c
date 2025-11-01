/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:54:35 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/10/29 13:55:00 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*p;

	p = (unsigned const char *)s;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (0);
}

// void compare_memchr_results(const char *arr, char target, size_t n) {
//     // Calling standard memchr
//     void *std_result = memchr(arr, target, n);

//     // Calling custom ft_memchr
//     void *ft_result = ft_memchr(arr, target, n);

//     // Output results from standard memchr
//     if (std_result) {
//         printf("Standard memchr found '%c' at position: %ld\n", target,
//(char *)std_result - arr);
//     } else {
//         printf("Standard memchr did not find '%c'.\n", target);
//     }

//     // Output results from custom ft_memchr
//     if (ft_result) {
//         printf("Custom ft_memchr found '%c' at position: %ld\n", target,
//(char *)ft_result - arr);
//     } else {
//         printf("Custom ft_memchr did not find '%c'.\n", target);
//     }

//     // Comparing the results
//     if (std_result == ft_result) {
//         printf("Both functions returned the same result.\n\n");
//     } else {
//         printf("The results differ.\n\n");
//     }
// }

// int main() {
//     // Test Case 1: Finding the character in the middle of the array
//     char arr1[] = "Hello, world!";
//     char target1 = 'o';
//     printf("Test Case 1: Finding 'o' in the middle of the array:\n");
//     compare_memchr_results(arr1, target1, 13);

//     // Test Case 2: Finding the character at the start of the array
//     char arr2[] = "apple";
//     char target2 = 'a';
//     printf("Test Case 2: Finding 'a' at the start of the array:\n");
//     compare_memchr_results(arr2, target2, 5);

//     // Test Case 3: Finding the character at the end of the array
//     char arr3[] = "banana";
//     char target3 = 'a';
//     printf("Test Case 3: Finding 'a' at the end of the array:\n");
//     compare_memchr_results(arr3, target3, 6);

//     // Test Case 4: Not finding the character (it doesn't exist in the array)
//     char arr4[] = "grape";
//     char target4 = 'z';
//     printf("Test Case 4: Searching for a character that doesn't exist in the array:\n");
//     compare_memchr_results(arr4, target4, 5);

//     // Test Case 5: Searching an empty array
//     char arr5[] = "";
//     char target5 = 'x';
//     printf("Test Case 5: Searching in an empty array:\n");
//     compare_memchr_results(arr5, target5, 0);

//     // Test Case 6: Edge case: searching with n = 0 (empty search space)
//     char arr6[] = "orange";
//     char target6 = 'r';
//     printf("Test Case 6: Searching with n = 0 (empty search space):\n");
//     compare_memchr_results(arr6, target6, 0);

//     return (0);
// }