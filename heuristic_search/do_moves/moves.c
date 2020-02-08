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
**	Helper function to get_legal_moves. See glm comment.
*/
static	int glm_single_stack_ops(
	t_stack *s, int len, int has_bound, int stack_is_a)
{
	int moves;

	moves = 0x0;
	if (stack_is_a)
	{
		if (stack_get(s, 0) != 0)
			moves |= len > 1 && stack_get(s, 1) != 0 ? SA_RA | PB : PB;
		moves |= has_bound == FALSE || stack_get(s, len) != 0 ? RRA : 0x0;
	}
	else
	{
		if (stack_get(s, 0) != 0)
			moves |= len > 1 && stack_get(s, 1) != 0 ? SB_RB | PA : PA;
		moves |= has_bound == FALSE || stack_get(s, len) != 0 ? RRB : 0x0;
	}
	return (moves);
}

/*
**	Checks which moves are legal and non-trivial.
**
**	Pushing is allowed when length is greater than 1 and the top entry != 0.
**
**	Swapping is allowed when pushing is allowed and the entry at index 1 != 0.
**
**	Rotating is allowed when swapping is allowed, so we use the same flag.
**
**	Reverse rotating is allowed when the last element is not 0 (part boundary)
**
**	Double ops are allowed whenever an operator is allowed on both stacks.
*/
int		get_legal_moves(t_node *current, int size_type)
{
	int	moves;
	int	a_len;
	int b_len;
	int has_bound;

	moves = 0x0;
	a_len = current->s_a->len;
	b_len = current->s_b->len;
	has_bound = (a_len + b_len == current->s_a->size / size_type) ? FALSE : TRUE;
	if (a_len > 0)
		moves |= glm_single_stack_ops(current->s_a, a_len, has_bound, TRUE);
	if (b_len > 0)
		moves |= glm_single_stack_ops(current->s_b, b_len, has_bound, FALSE);
	moves |= (moves & SA_RA) && (moves & SB_RB) ? SS_RR : 0x0;
	moves |= (moves & RRA) && (moves & RRB) ? RRR : 0x0;
	return (moves);
}

static	int		list_len(t_node *node)
{
	// REMOVE ME!
	int i;

	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	do_moves(t_node **new_nodes, t_node *current, int move_stock)
{
	printf("do_moves: %#x\n", move_stock);
	if (move_stock & SA_RA)
	{
		printf("	do_moves: 1\n");
		node_insert(new_nodes, do_sa(current));
		printf("new_nodes after inserting do_sa: %p\n", *new_nodes);
		node_insert(new_nodes, do_ra(current));
		printf("new_nodes after inserting do_ra: %p\n", *new_nodes);
		printf("!!!new_nodes len: %d\n", list_len(*new_nodes));
	}
	if (move_stock & SB_RB)
	{
		printf("	do_moves: 2\n");
		node_insert(new_nodes, do_sb(current));
		node_insert(new_nodes, do_rb(current));
	}
	if (move_stock & SS_RR)
	{
		printf("	do_moves: 3\n");
		node_insert(new_nodes, do_ss(current));
		node_insert(new_nodes, do_rr(current));
	}
	if (move_stock & PA) {
		printf("	do_moves: 4\n");
		node_insert(new_nodes, do_pa(current));
	}
	if (move_stock & PB) {
		printf("	do_moves: 5\n");
		node_insert(new_nodes, do_pb(current));
	}
	if (move_stock & RRB) {
		printf("	do_moves: 6\n");
		node_insert(new_nodes, do_rrb(current));
	}
	if (move_stock & RRA) {
		printf("	do_moves: 7\n");
		node_insert(new_nodes, do_rra(current));
	}
	if (move_stock & RRR) {
		printf("	do_moves: 8\n");
		node_insert(new_nodes, do_rrr(current));
	}
	printf("After do_moves new len: %d\n", list_len(*new_nodes));
}
