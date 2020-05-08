/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_pointer_ops.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/28 20:36:23 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/28 20:36:23 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	inc_start(t_stack **s)
{
	(*s)->start =
		(*s)->start - (*s)->stack < (int)((*s)->size / sizeof(int)) - 1 ?
		(*s)->start + 1 : (*s)->stack;
}

void	dec_start(t_stack **s)
{
	(*s)->start = (*s)->start > (*s)->stack ?
		(*s)->start - 1 : (*s)->stack + (((*s)->size / sizeof(int)) - 1);
}

void	inc_end(t_stack **s)
{
	(*s)->end = (*s)->end - (*s)->stack < (int)((*s)->size / sizeof(int)) - 1 ?
		(*s)->end + 1 : (*s)->stack;
}

void	dec_end(t_stack **s)
{
	(*s)->end = (*s)->end > (*s)->stack ?
		(*s)->end - 1 : (*s)->stack + (((*s)->size / sizeof(int)) - 1);
}

/*
**	Used to align start of stack with index 0 of array?
*/

void	shift_stack(t_stack **s)
{
	int	len_a;
	int len_b;
	int	*arr;

	if ((*s)->stack == (*s)->start)
		return ;
	arr = (int *)ft_memalloc(sizeof(int) * (*s)->size);
	if (arr == NULL)
		ft_putstr_fd("Error in shift_stack\n", 2);
	len_a = (*s)->start - (*s)->stack;
	len_b = ((*s)->size / sizeof(int)) - len_a;
	arr = ft_memcpy(arr, (*s)->start, sizeof(int) * len_b);
	(void)ft_memcpy(arr + len_b, (*s)->stack, sizeof(int) * len_a);
	free((*s)->stack);
	(*s)->stack = arr;
	(*s)->start = arr;
	(*s)->end = arr + (((*s)->size / sizeof(int)) - 1);
}
