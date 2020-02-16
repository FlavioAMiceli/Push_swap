/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_wrapper_functions.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 21:05:21 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/14 21:05:22 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
**	Returns value at index i in stack.
*/
int		stack_get(t_stack *s, int i)
{
	// TODO
	// TEST EVERYTHING!
	// IF start = S_SIZE - (S_START - S_STACK) is wrong,
	// Than it's also wrong in shift_stack in stack_pointer_ops!
	int	start_n;

	start_n = s->start - s->stack;
	return (s->stack[(i + start_n) % (s->size / sizeof(int))]);
}

/*
**	Sets value at index i in stack.
*/
void	stack_set(t_stack *s, int value, int i)
{
	int	start_n;

	start_n = s->start - s->stack;
	s->stack[(i + start_n) % (s->size / sizeof(int))] = value;
}
