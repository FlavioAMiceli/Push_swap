/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ops.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 20:02:40 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/14 20:02:41 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **stack)
{
	t_list	*node;

	node = ft_lstunlink(stack, (*stack)->next);
	ft_lstadd(stack, node);
}

void push(t_list **src, t_list **dst)
{
	t_list	*node;

	node = ft_lstdequeue(src);
	ft_lstadd(dst, node);
}

void rotate(t_list **stack)
{
	t_list	*node;

	node = ft_lstdequeue(stack);
	ft_lstappend(stack, node);
}

void reverse_rotate(t_list **stack)
{
	t_list	*new_end;
	t_list	*node;

	node = *stack;
	while (node->next != NULL)
	{
		new_end = node;
		node = node->next;
	}
	new_end->next = NULL;
	ft_lstadd(stack, node);
}
