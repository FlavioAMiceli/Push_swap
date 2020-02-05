/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 19:13:23 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/20 19:13:23 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../heuristic_search.h"
#include <stdio.h> // remove me!

/*
**	Checks which moves are legal and non-trivial.
**
**	Pushing is allowed when length is greater than 1 and the top entry != 0.
**
**	Swapping is allowed when pushing is allowed and the entry at index 1 != 0.
**
**	Rotating is allowed when swapping is allowed, so we use the same flag.
**
**	Reverse rotating is allowed when pushing is allowed and;
**	length is greater than 1 or (length is 1 AND len_a + len_b < size / sizeof()
**
**	Double ops are allowed whenever an operator is allowed on both stacks.
*/
int		get_legal_moves(t_node *current)
{
	int	moves;
	int	a_len;
	int b_len;

	moves = 0x0;
	a_len = current->s_a->len;
	b_len = current->s_b->len;
	if (a_len > 0 && stack_get(current->s_a, 0) != 0)
	{
		moves |= a_len > 1 && stack_get(current->s_a, 1) ? SA_RA | PB : PB;
	 	moves |= a_len > 1 ||
			(a_len == 1 && a_len + b_len == current->s_a->size / sizeof(int)) ?
			RRA : 0x0;
	}
	if (b_len > 0 && stack_get(current->s_b, 0) != 0)
	{
		moves |= b_len > 1 && stack_get(current->s_b, 1) ? SB_RB | PA : PA;
	 	moves |= b_len > 1 ||
			(b_len == 1 && a_len + b_len == current->s_a->size / sizeof(int)) ?
			RRB : 0x0;
	}
	moves |= moves & SA_RA && moves & SB_RB ? SS_RR : 0x0;
	moves |= moves & RRA && moves & RRB ? RRR : 0x0;
	return (moves);
}

void	do_moves(t_node **new_nodes, t_node *current, int move_stock)
{
	if (move_stock & SA_RA)
	{
		new_nodes = node_insert(new_nodes, do_sa(current));
		new_nodes = node_insert(new_nodes, do_ra(current));
	}
	if (move_stock & SB_RB)
	{
		new_nodes = node_insert(new_nodes, do_sb(current));
		new_nodes = node_insert(new_nodes, do_rb(current));
	}
	if (move_stock & SS_RR)
	{
		new_nodes = node_insert(new_nodes, do_ss(current));
		new_nodes = node_insert(new_nodes, do_rr(current));
	}
	if (move_stock & PB)
		new_nodes = node_insert(new_nodes, do_pb(current));
	if (move_stock & PA)
		new_nodes = node_insert(new_nodes, do_pa(current));
	if (move_stock & RRB)
		new_nodes = node_insert(new_nodes, do_rrb(current));
	if (move_stock & RRA)
		new_nodes = node_insert(new_nodes, do_rra(current));
	if (move_stock & RRR)
		new_nodes = node_insert(new_nodes, do_rrr(current));
}
