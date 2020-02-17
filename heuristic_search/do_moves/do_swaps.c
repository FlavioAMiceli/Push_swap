/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_swaps.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:32:31 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/20 16:32:31 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../heuristic_search.h"

t_node	*do_sa(t_node *current)
{
	t_node	*new;

	new = (t_node*)ft_memalloc(sizeof(t_node));
	new = node_stackdup(new, current);
	if (!new ||
		!swap(&(new->s_a)))
		ft_putstr_fd("Error in do_sa\n", 2);
	new->n_ops++;
	new->fitness = node_evaluate(new->s_a, new->s_b, new->n_ops);
	new->ops = ft_strjoin(current->ops, "sa\n");
	new->next = NULL;
	new->last_op = SA | (current->last_op & B_OPS);
	return (new);
}

t_node	*do_sb(t_node *current)
{
	t_node	*new;

	new = (t_node*)ft_memalloc(sizeof(t_node));
	new = node_stackdup(new, current);
	if (!new ||
		!swap(&(new->s_b)))
		ft_putstr_fd("Error in do_sb\n", 2);
	new->n_ops++;
	new->fitness = node_evaluate(new->s_a, new->s_b, new->n_ops);
	new->ops = ft_strjoin(current->ops, "sb\n");
	new->next = NULL;
	new->last_op = SB | (current->last_op & A_OPS);
	return (new);
}

t_node	*do_ss(t_node *current)
{
	t_node	*new;

	new = (t_node*)ft_memalloc(sizeof(t_node));
	new = node_stackdup(new, current);
	if (!new ||
		!swap(&(new->s_a)) ||
		!swap(&(new->s_b)))
		ft_putstr_fd("Error in do_ss\n", 2);
	new->n_ops++;
	new->fitness = node_evaluate(new->s_a, new->s_b, new->n_ops);
	new->ops = ft_strjoin(current->ops, "ss\n");
	new->next = NULL;
	new->last_op = SA | SB;
	return (new);
}
