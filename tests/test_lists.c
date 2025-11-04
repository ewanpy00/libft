/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <stdlib.h>

static void dummy_del(void *content)
{
	(void)content;
}

static void *dummy_map(void *content)
{
	char *str = (char *)content;
	char *new = malloc(strlen(str) + 1);
	if (!new)
		return NULL;
	strcpy(new, str);
	return new;
}

void test_lstnew(void)
{
	printf("\n=== Testing ft_lstnew ===\n");
	
	t_list *node = ft_lstnew("test");
	test_assert(node != NULL, "lstnew: allocation");
	test_assert(node->content != NULL && strcmp((char *)node->content, "test") == 0, "lstnew: content");
	test_assert(node->next == NULL, "lstnew: next is NULL");
	free(node);
	
	// NULL content
	node = ft_lstnew(NULL);
	test_assert(node != NULL, "lstnew: NULL content");
	test_assert(node->content == NULL, "lstnew: content is NULL");
	test_assert(node->next == NULL, "lstnew: next is NULL");
	free(node);
}

void test_lstadd_front(void)
{
	printf("\n=== Testing ft_lstadd_front ===\n");
	
	t_list *list = NULL;
	t_list *node1 = ft_lstnew("first");
	t_list *node2 = ft_lstnew("second");
	
	ft_lstadd_front(&list, node1);
	test_assert(list == node1, "lstadd_front: first node");
	test_assert(list->next == NULL, "lstadd_front: first node next");
	
	ft_lstadd_front(&list, node2);
	test_assert(list == node2, "lstadd_front: second node");
	test_assert(list->next == node1, "lstadd_front: second node next");
	test_assert(list->next->next == NULL, "lstadd_front: final next");
	
	free(node2);
	free(node1);
}

void test_lstadd_back(void)
{
	printf("\n=== Testing ft_lstadd_back ===\n");
	
	t_list *list = NULL;
	t_list *node1 = ft_lstnew("first");
	t_list *node2 = ft_lstnew("second");
	
	ft_lstadd_back(&list, node1);
	test_assert(list == node1, "lstadd_back: first node");
	test_assert(list->next == NULL, "lstadd_back: first node next");
	
	ft_lstadd_back(&list, node2);
	test_assert(list == node1, "lstadd_back: list still points to first");
	test_assert(list->next == node2, "lstadd_back: second node added");
	test_assert(list->next->next == NULL, "lstadd_back: final next");
	
	free(node1);
	free(node2);
}

void test_lstsize(void)
{
	printf("\n=== Testing ft_lstsize ===\n");
	
	t_list *list = NULL;
	test_assert(ft_lstsize(list) == 0, "lstsize: empty list");
	
	list = ft_lstnew("first");
	test_assert(ft_lstsize(list) == 1, "lstsize: one node");
	
	t_list *node2 = ft_lstnew("second");
	list->next = node2;
	test_assert(ft_lstsize(list) == 2, "lstsize: two nodes");
	
	t_list *node3 = ft_lstnew("third");
	node2->next = node3;
	test_assert(ft_lstsize(list) == 3, "lstsize: three nodes");
	
	free(list);
	free(node2);
	free(node3);
}

void test_lstlast(void)
{
	printf("\n=== Testing ft_lstlast ===\n");
	
	t_list *list = NULL;
	test_assert(ft_lstlast(list) == NULL, "lstlast: empty list");
	
	list = ft_lstnew("first");
	test_assert(ft_lstlast(list) == list, "lstlast: single node");
	
	t_list *node2 = ft_lstnew("second");
	list->next = node2;
	test_assert(ft_lstlast(list) == node2, "lstlast: two nodes");
	
	t_list *node3 = ft_lstnew("third");
	node2->next = node3;
	test_assert(ft_lstlast(list) == node3, "lstlast: three nodes");
	
	free(list);
	free(node2);
	free(node3);
}

void test_lstdelone(void)
{
	printf("\n=== Testing ft_lstdelone ===\n");
	
	char *content = malloc(10);
	strcpy(content, "test");
	t_list *node = ft_lstnew(content);
	
	ft_lstdelone(node, free);
	test_assert(1, "lststdelone: deletion (no crash)");
	
	// Test with NULL del
	node = ft_lstnew("test");
	ft_lstdelone(node, NULL);
	test_assert(1, "lststdelone: NULL del function");
}

void test_lstclear(void)
{
	printf("\n=== Testing ft_lstclear ===\n");
	
	t_list *list = NULL;
	ft_lstclear(&list, dummy_del);
	test_assert(list == NULL, "lstclear: empty list");
	
	char *c1 = malloc(10);
	char *c2 = malloc(10);
	strcpy(c1, "first");
	strcpy(c2, "second");
	
	list = ft_lstnew(c1);
	t_list *node2 = ft_lstnew(c2);
	list->next = node2;
	
	ft_lstclear(&list, free);
	test_assert(list == NULL, "lstclear: cleared list");
	
	// Test with NULL
	ft_lstclear(NULL, dummy_del);
	test_assert(1, "lstclear: NULL list");
}

static int g_sum = 0;

static void add_to_sum(void *content)
{
	g_sum += *(int *)content;
}

void test_lstiter(void)
{
	printf("\n=== Testing ft_lstiter ===\n");
	
	int a = 1, b = 2, c = 3;
	t_list *list = ft_lstnew(&a);
	t_list *node2 = ft_lstnew(&b);
	t_list *node3 = ft_lstnew(&c);
	list->next = node2;
	node2->next = node3;
	
	g_sum = 0;
	ft_lstiter(list, add_to_sum);
	test_assert(g_sum == 6, "lstiter: iterate and sum");
	
	free(list);
	free(node2);
	free(node3);
	
	// Test with NULL
	ft_lstiter(NULL, add_to_sum);
	test_assert(1, "lstiter: NULL list");
}

void test_lstmap(void)
{
	printf("\n=== Testing ft_lstmap ===\n");
	
	char *str1 = "hello";
	char *str2 = "world";
	
	t_list *list = ft_lstnew(str1);
	t_list *node2 = ft_lstnew(str2);
	list->next = node2;
	
	t_list *new_list = ft_lstmap(list, dummy_map, free);
	test_assert(new_list != NULL, "lstmap: allocation");
	test_assert(strcmp((char *)new_list->content, "hello") == 0, "lstmap: first content");
	test_assert(new_list->next != NULL, "lstmap: second node exists");
	test_assert(strcmp((char *)new_list->next->content, "world") == 0, "lstmap: second content");
	test_assert(new_list->next->next == NULL, "lstmap: final next");
	
	ft_lstclear(&new_list, free);
	free(list);
	free(node2);
	
	// Test with NULL
	new_list = ft_lstmap(NULL, dummy_map, free);
	test_assert(new_list == NULL, "lstmap: NULL list");
}

