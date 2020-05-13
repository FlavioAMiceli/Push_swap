/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_ops.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 20:02:40 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/14 20:02:41 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_stack **s)
{
	int	i;
	int	j;

	if ((*s)->len < 2)
		return (FALSE);
	i = stack_get(*s, 0);
	j = stack_get(*s, 1);
	stack_set(*s, j, 0);
	stack_set(*s, i, 1);
	return (TRUE);
}

int	push(t_stack **src, t_stack **dst)
{
	if ((*src)->len == 0 || (*dst)->len == (*dst)->size)
		return (FALSE);
	dec_start(dst);
	stack_set(*dst, stack_get(*src, 0), 0);
	(*dst)->len += 1;
	inc_start(src);
	(*src)->len -= 1;
	return (TRUE);
}

int	rot(t_stack **s)
{
	if ((*s)->len == 0)
		return (FALSE);
	else if ((*s)->len == 1)
		return (TRUE);
	inc_end(s);
	stack_set(*s, stack_get(*s, 0), (*s)->len);
	inc_start(s);
	return (TRUE);
}

int	rev_rot(t_stack **s)
{
	if ((*s)->len == 0)
		return (FALSE);
	else if ((*s)->len == 1)
		return (TRUE);
	dec_start(s);
	stack_set(*s, stack_get(*s, (*s)->len), 0);
	dec_end(s);
	return (TRUE);
}
