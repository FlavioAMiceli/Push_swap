/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_pointer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/28 20:36:23 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/28 20:36:23 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void inc_start(t_stack **stack)
{
	(*stack)->start = (*stack)->start - (*stack)->stack < (*stack)->size \
	? (*stack)->start++
	: (*stack)->stack;
}

void dec_start(t_stack **stack)
{
	(*stack)->start = (*stack)->start > (*stack)->stack \
	? (*stack)->start--
	: (*stack)->stack + (*stack)->size - 1;
}

void inc_end(t_stack **stack)
{
	(*stack)->end = (*stack)->end - (*stack)->stack < (*stack)->size \
	? (*stack)->end++
	: (*stack)->stack;
}

void dec_end(t_stack **stack)
{
	(*stack)->end = (*stack)->end > (*stack)->stack \
	? (*stack)->end--
	: (*stack)->stack + (*stack)->size - 1;
}

int	*shift_stack(t_stack **stack)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * (*stack)->size);
	arr = ft_memcpy(arr, (*stack)->start, sizeof(int) * )
}
