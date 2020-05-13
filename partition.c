/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   partition.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 19:42:26 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/10 19:42:26 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition_to_a(t_stacks *s, int *sorted, int lo, int hi)
{
	int	pivot_i;

	if ((hi - lo) + 1 <= BASE_CASE_LEN)
		bc_to_a(s, lo, hi);
	else
	{
		pivot_i = (lo + hi) / 2;
		sift_to_a(s, sorted[pivot_i], hi - pivot_i);
		partition_to_b(s, sorted, pivot_i + 1, hi);
		partition_to_a(s, sorted, lo, pivot_i);
	}
}

void		partition_to_b(t_stacks *s, int *sorted, int lo, int hi)
{
	int	pivot_i;

	if ((hi - lo) + 1 <= BASE_CASE_LEN)
		bc_to_b(s, lo, hi);
	else
	{
		pivot_i = (lo + hi) / 2;
		sift_to_b(s, sorted[pivot_i], pivot_i - lo + 1);
		partition_to_b(s, sorted, pivot_i + 1, hi);
		partition_to_a(s, sorted, lo, pivot_i);
	}
}
