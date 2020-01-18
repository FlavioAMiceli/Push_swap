/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heuristic_search.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 21:35:30 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/14 21:35:31 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// /*
// **	moves is a stock that stores all legal moves
// */
// t_node	*node_init(t_node **node, t_stack **a, t_stack **b, t_size n)
// {
// 	t_node	**new_nodes;
// 	char 	moves;
//
// 	moves = get_legal_moves(a, b, n);
// 	get_new_nodes(moves);
// 	while (moves)
// }

static int				is_solved(t_node *node, int n)
{
	if (node->stack_a->start == node->stack_a->stack &&
		node->stack_a->len == n)
		return (TRUE);
	return (FALSE);
}

static unsigned char	get_legal_moves(t_node *current)
{
	int	moves;

	moves = 0x0;
	if (current->stack_a->len > 0 && *(current->stack_a->end) != 0)
	{
		if (*(current->stack_a->end) != 0)
			moves |= current->stack_a->len > 1 ? SA | PB_RRA : PB_RRA;
		moves |= *(current->stack_a->start) != 0 ? RA : 0x0;
	}
	if (current->stack_b->len > 0 && *(current->stack_b->end) != 0)
	{
		if (*(current->stack_b->end) != 0)
			moves |= current->stack_b->len > 1 ? SB | PA_RRB : PA_RRB;
		moves |= *(current->stack_b->start) != 0 ? RB : 0x0;
	}
	moves |= moves & SA && moves & SB ? SS_RRR : 0x0;
	moves |= moves & RA && moves & RB ? RR : 0x0;
	return (moves);
}

static void 			expand_best_node(t_node **nodes)
{
	t_node	**new_nodes;
	int		move_stock;

	move_stock = get_legal_moves(*nodes);
	nodes = node_delhead(nodes);
	new_nodes = do_moves(new_nodes, move_stock);
	nodes = insert_new_nodes(nodes, new_nodes);
	return (nodes);
}

char					*heuristic_search(t_stack **a, t_stack **b, t_size n)
{
	t_node	**nodes;
	char	*ops;

	nodes = node_init(nodes, a, b, n);
	while (!is_solved(*nodes, n))
		nodes = expand_best_node(nodes);
	ops = ft_strdup((*nodes)->ops);
	node_delall(nodes);
	return (ops);
}