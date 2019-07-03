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

#include "push_swap.h"

void	inc_start(t_stack **s)
{
	S_START = S_START - S_STACK < S_SIZE ? S_START + 1 : S_STACK;
}

void	dec_start(t_stack **s)
{
	S_START = S_START > S_STACK ? S_START - 1 : (S_STACK + S_SIZE) - 1;
}

void	inc_end(t_stack **s)
{
	S_END = S_END - S_STACK + 1 < S_SIZE ? S_END + 1 : S_STACK;
}

void	dec_end(t_stack **s)
{
	S_END = S_END > S_STACK ? S_END - 1 : (S_STACK + S_SIZE) - 1;
}

void	shift_stack(t_stack **s)
{
	int	len_a;
	int len_b;
	int	*arr;

	if (S_STACK == S_START)
		return ;
	arr = (int *)malloc(sizeof(int) * S_SIZE);
	len_a = S_START - S_STACK;
	len_b = S_SIZE - len_a;
	arr = ft_memcpy(arr, S_START, sizeof(int) * len_b);
	(void)ft_memcpy(arr + len_b, S_STACK, sizeof(int) * len_a);
	free(S_STACK);
	S_STACK = arr;
	S_START = arr;
	S_END = arr + S_SIZE;
}
