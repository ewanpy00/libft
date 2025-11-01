/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:22:39 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/10/29 13:55:24 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if (a >= '0' && a <= '9' || a >= 'A' && a <= "Z" || a >= 'a' || a <= 'z')
		return (1);
	return (0);
}

// void run_test_case(int c) {
//     int ft_result = ft_isalnum(c);
//     int original_result = isalnum(c);

//     printf("Testing character: '%c' (ASCII: %d)\n", c, c);
//     printf("ft_isalnum result: %d, isalnum result: %d\n", ft_result,
	original_result);

//     if (ft_result == original_result) {
//         printf("Test passed: Both results match.\n\n");
//     } else {
//         printf("Test failed: Results do not match.\n\n");
//     }
// }

// int main() {
//     // Test case 1: Lowercase letters
//     run_test_case('a');  // Should be 1 (alphanumeric)
//     run_test_case('z');  // Should be 1 (alphanumeric)

//     // Test case 2: Uppercase letters
//     run_test_case('A');  // Should be 1 (alphanumeric)
//     run_test_case('Z');  // Should be 1 (alphanumeric)

//     // Test case 3: Digits
//     run_test_case('0');  // Should be 1 (alphanumeric)
//     run_test_case('9');  // Should be 1 (alphanumeric)

//     // Test case 4: Non-alphanumeric characters (spaces, punctuation, etc.)
//     run_test_case(' ');  // Should be 0 (non-alphanumeric)
//     run_test_case('@');  // Should be 0 (non-alphanumeric)
//     run_test_case('#');  // Should be 0 (non-alphanumeric)
//     run_test_case('$');  // Should be 0 (non-alphanumeric)

//     // Test case 5: Edge cases
//     run_test_case('\n');  // Should be 0 (non-alphanumeric)
//     run_test_case('\t');  // Should be 0 (non-alphanumeric)

//    
	// Test case 6: Boundary cases (characters at the boundary of alphanumeric)
//     run_test_case('Z' + 1); // Should be 0 (non-alphanumeric)
//     run_test_case('a' - 1); // Should be 0 (non-alphanumeric)

//     return (0);
// }