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

#include "heuristic_search.h"

static int		is_solved(t_node *node, int n)
{
	if (node->s_a->start == node->s_a->stack &&
		node->s_a->len == n)
		return (TRUE);
	return (FALSE);
}

static t_node	*expand_best_node(t_node **nodes)
{
	t_node	*new_nodes;
	int		move_stock;

	move_stock = get_legal_moves(*nodes);
	do_moves(&new_nodes, *nodes, move_stock);
	nodes = node_delhead(nodes);
	nodes = merge_new_nodes(nodes, &new_nodes);
	return (*nodes);
}

char			*heuristic_search(t_stack **a, t_stack **b, size_t n)
{
	t_node	*nodes;
	char	*ops;

	nodes = node_queue_init(&nodes, a, b);
	while (!is_solved(nodes, n))
		nodes = expand_best_node(&nodes);
	ops = ft_strdup(nodes->ops);
	node_delall(&nodes);
	return (ops);
}
