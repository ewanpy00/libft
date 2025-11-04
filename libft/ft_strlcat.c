/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:39:15 by ivan              #+#    #+#             */
/*   Updated: 2025/11/03 16:16:31 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t src_len;
	size_t dst_len;
	size_t i;

	i = 0;
	dst_len = 0;
	src_len = strlen(src);
	while (dst_len < size && dst[dst_len])
		dst_len++;
	if (dst_len >= size)
		return (src_len + size);
	while (src[i] && (dst_len + i + 1 < size))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// typedef struct s_test {
//     const char *initial_dst;
//     const char *src;
//     size_t size;
// } t_test;

// void run_test(int num, const char *initial_dst, const char *src, size_t size)
// {
//     char dst1[50];
//     char dst2[50];
//     size_t ret_ft, ret_sys;

//     // Инициализируем буферы одинаковыми данными
//     strncpy(dst1, initial_dst, sizeof(dst1));
//     strncpy(dst2, initial_dst, sizeof(dst2));

//     ret_ft = ft_strlcat(dst1, src, size);
//     ret_sys = strlcat(dst2, src, size);

//     printf("=== Тест %d ===\n", num);
//     printf("  dst_init: \"%s\"\n", initial_dst);
//     printf("  src     : \"%s\"\n", src);
//     printf("  size    : %zu\n", size);
//     printf("  -----------------------------------\n");
//     printf("  ft_strlcat -> \"%s\" (ret=%zu)\n", dst1, ret_ft);
//     printf("  strlcat    -> \"%s\" (ret=%zu)\n", dst2, ret_sys);

//     if (strcmp(dst1, dst2) == 0 && ret_ft == ret_sys)
//         printf("  ✅ Совпадает!\n\n");
//     else
//         printf("  ❌ Ошибка!\n\n");
// }

// int main(void)
// {
//     t_test tests[] = {
//         {"Hello", " World!", 20},
//         {"Hello", " World!", 5},
//         {"", "Test", 10},
//         {"Hello", "", 10},
//         {"12345", "6789", 0},
//         {"Short", " veryverylongstring", 10},
//         {"", "", 1},
//     };

//     int num_tests = sizeof(tests) / sizeof(tests[0]);

//     printf("=== Тестирование ft_strlcat ===\n\n");

//     for (int i = 0; i < num_tests; i++) {
//         run_test(i + 1, tests[i].initial_dst, tests[i].src, tests[i].size);
//     }

//     return 0;
// }