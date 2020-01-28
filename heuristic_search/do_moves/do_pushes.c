/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_pushes.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:50:35 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/20 16:50:36 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../heuristic_search.h"

t_node	*do_pa(t_node *current)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new = node_stackdup(new, current);
	push(&(new->stack_b), &(new->stack_a));
	new->n_ops++;
	new->fitness = node_evaluate(new->stack_a, new->stack_b, new->n_ops);
	new->ops = ft_strjoin(current->ops, "pa\n");
	new->next = NULL;
	return (new);
}

t_node	*do_pb(t_node *current)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new = node_stackdup(new, current);
	push(&(new->stack_a), &(new->stack_b));
	new->n_ops++;
	new->fitness = node_evaluate(new->stack_a, new->stack_b, new->n_ops);
	new->ops = ft_strjoin(current->ops, "pb\n");
	new->next = NULL;
	return (new);
}
