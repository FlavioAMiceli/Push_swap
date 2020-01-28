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
		new_nodes = node_insert(new_nodes, do_sa(current));
	if (move_stock & SB)
		new_nodes = node_insert(new_nodes, do_sb(current));
	if (move_stock & SS_RRR)
	{
		new_nodes = node_insert(new_nodes, do_ss(current));
		new_nodes = node_insert(new_nodes, do_rrr(current));
	}
	if (move_stock & PA_RRB)
	{
		new_nodes = node_insert(new_nodes, do_pa(current));
		new_nodes = node_insert(new_nodes, do_rrb(current));
	}
	if (move_stock & PB_RRA)
	{
		new_nodes = node_insert(new_nodes, do_pb(current));
		new_nodes = node_insert(new_nodes, do_rra(current));
	}
	if (move_stock & RA)
		new_nodes = node_insert(new_nodes, do_ra(current));
	if (move_stock & RB)
		new_nodes = node_insert(new_nodes, do_rb(current));
	if (move_stock & RR)
		new_nodes = node_insert(new_nodes, do_rr(current));
}
