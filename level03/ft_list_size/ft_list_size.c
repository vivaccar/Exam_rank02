/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:43:20 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/02 16:30:00 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int	i = 0;

	while (begin_list)
	{
		begin_list = begin_list ->next;
		i++;
	}
	return (i);
}

t_list	*create_node(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node ->data = data;
	node ->next = NULL;
	return (node);
}

void	append(t_list **list, int data)
{
	t_list	*new_last;
	t_list	*temp;

	new_last = create_node(data);
	if (*list == NULL)
		*list = new_last;
	else
	{
		temp = *list;
		while (temp ->next != NULL)
			temp = temp->next;
		temp->next = new_last;
	}
		
}

void	print_list(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp != NULL)
	{
		printf("%i", temp->data);
		temp = temp->next;
		printf("\n");
	}
}

int	main(void)
{
	int	a = 1;
	int	b = 2;
	int	c = 3;
	t_list 	*stack;

	stack = NULL;
	append(&stack, a);
	append(&stack, b);
	append(&stack, c);

	print_list(stack);
}
