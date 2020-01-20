/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_revrots.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:49:10 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/20 16:49:10 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "heuristic_search.h"

t_node	*do_rra(t_node *current)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new = node_stackdup(new, current);
	rev_rot(&(new->stack_a));
	new->n_ops++;
	new->fitness = node_evaluate(new->stack_a, new->stack_b, new->n_ops);
	new->ops = ft_strjoin(current->ops, "rra\n");
	new->next = NULL;
	return (new);
}

t_node	*do_rrb(t_node *current)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new = node_stackdup(new, current);
	rev_rot(&(new->stack_b));
	new->n_ops++;
	new->fitness = node_evaluate(new->stack_a, new->stack_b, new->n_ops);
	new->ops = ft_strjoin(current->ops, "rrb\n");
	new->next = NULL;
	return (new);
}

t_node	*do_rrr(t_node *current)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new = node_stackdup(new, current);
	rev_rot(&(new->stack_a));
	rev_rot(&(new->stack_b));
	new->n_ops++;
	new->fitness = node_evaluate(new->stack_a, new->stack_b, new->n_ops);
	new->ops = ft_strjoin(current->ops, "rrr\n");
	new->next = NULL;
	return (new);
}
