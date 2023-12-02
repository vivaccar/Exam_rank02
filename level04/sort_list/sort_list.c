/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:50:48 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/02 20:28:08 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sort_list.list.h"
#include <stdio.h>

int ascending(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		data;
	t_list	*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			data = lst->data;
			lst->data = lst->next->data;
			lst->next->data = data;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

t_list	*create_node(int data)
{
	t_list	*node;
	
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return(NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	append(t_list **lst, int n)
{
	t_list	*tmp;
	t_list	*new_last;

	new_last = create_node(n);
	if (*lst == NULL)
		*lst = new_last;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_last;
	}
}

int	main(void)
{
	t_list	*lista;
	t_list	*test;

	lista = NULL;
	test = NULL;
	append(&lista, 8);
	append(&lista, 2);
	append(&lista, 4);
	append(&lista, 1);

	test = lista;
	while (lista)
	{
		printf("%i", lista->data);
		lista = lista->next;
		printf("\n");
	}
	lista = sort_list(test, ascending);
	while (test)
	{
		printf("%i", test->data);
		test = test->next;
		printf("\n");		
	}
}