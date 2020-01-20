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

#include "push_swap.h"
#include "heuristic_search.h"

int		get_legal_moves(t_node *current)
{
	int	moves;

	moves = 0x0;
	if (current->stack_a->len > 0 && *(current->stack_a->end) != 0)
	{
		moves |= current->stack_a->len > 1 ? SA | PB_RRA : PB_RRA;
		moves |= *(current->stack_a->start) != 0 ? RA : 0x0;
	}
	if (current->stack_b->len > 0 && *(current->stack_b->end) != 0)
	{
		moves |= current->stack_b->len > 1 ? SB | PA_RRB : PA_RRB;
		moves |= *(current->stack_b->start) != 0 ? RB : 0x0;
	}
	moves |= moves & SA && moves & SB ? SS_RRR : 0x0;
	moves |= moves & RA && moves & RB ? RR : 0x0;
	return (moves);
}

void	do_moves(t_node **new_nodes, t_node *current, int move_stock)
{
	if (move_stock & SA)
		node_insert(new_nodes, do_sa(current));
	if (move_stock & SB)
		node_insert(new_nodes, do_sb(current));
	if (move_stock & SS_RRR)
	{
		node_insert(new_nodes, do_ss(current));
		node_insert(new_nodes, do_rrr(current));
	}
	if (move_stock & PA_RRB)
	{
		node_insert(new_nodes, do_pa(current));
		node_insert(new_nodes, do_rrb(current));
	}
	if (move_stock & PB_RRA)
	{
		node_insert(new_nodes, do_pb(current));
		node_insert(new_nodes, do_rra(current));
	}
	if (move_stock & RA)
		node_insert(new_nodes, do_ra(current));
	if (move_stock & RB)
		node_insert(new_nodes, do_rb(current));
	if (move_stock & RR)
		node_insert(new_nodes, do_rr(current));
}
