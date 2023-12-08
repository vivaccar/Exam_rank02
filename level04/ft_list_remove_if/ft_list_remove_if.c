/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:20:37 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/05 19:19:54 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;

	if (*begin_list == NULL)
		return;
	current = *begin_list;
	if (cmp(current->data, data_ref) == 0)
	{
		*begin_list = current->next;
		free (current);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		current = *begin_list;
		ft_list_remove_if(&current->next, data_ref, cmp);
	}
}
void	append(t_list **head, void *data)
{
	t_list	*look;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	new_node ->data = data;
	new_node ->next = NULL;
	look = *head;
	if (!look)
		*head = new_node;
	else
	{
		while (look ->next)
		{
			look = look->next;
		}
		look ->next = new_node;
	}
}

int	cmp(int n1, int n2)
{
	if (n1 == n2)
		return (0);
	else 
		return (1);
}

int	main(void)
{
	t_list	*lista;
	t_list	*look;

	lista = malloc(sizeof(t_list));
	lista = NULL;
	append(&lista, (int *)10);
	append(&lista, (int *)3);
	append(&lista, (int *)4);
	append(&lista, (int *)3);
	look = lista;
	while (look)
	{
		printf("%p\n", (int *)look->data);
		look = look->next;
	}
	look = lista;
	ft_list_remove_if(&lista, (int *)4, cmp);
	while (look)
	{
		printf("%p\n", (int *)look->data);
		look = look->next;
	}
}