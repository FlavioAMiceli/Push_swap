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

int swap(t_stack **stack)
{
	if ((*stack)->len < 2)
		return (FALSE);
	(*stack)->stack[0] ^= (*stack)->stack[1];
	(*stack)->stack[1] ^= (*stack)->stack[0];
	(*stack)->stack[0] ^= (*stack)->stack[1];
	return (TRUE);
}

int push(t_stack **src, t_stack **dst)
{
	if ((*src)->len == 0 || (*dst)->len == (*dst)->size)
		return (FALSE);
	inc_end(dst);
	(*dst)->len++;
	(*dst)->end = (*src)->end;
	dec_end(src);
	(*src)->len--;
	return (TRUE);
}

int rot(t_stack **stack)
{
	if ((*stack)->len == 0)
		return (FALSE);
	else if ((*stack)->len == 1)
		return (TRUE);
	inc_end(stack);
	*((*stack)->end) = *((*stack)->start);
	inc_start(stack);
	return (TRUE);
}

int rev_rot(t_stack **stack)
{
	if ((*stack)->len == 0)
		return (FALSE);
	else if ((*stack)->len == 1)
		return (TRUE);
	dec_start(stack);
	*((*stack)->start) = *((*stack)->end);
	dec_end(stack);
	return (TRUE);
}
