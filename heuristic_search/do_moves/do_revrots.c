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

#include "../heuristic_search.h"

t_node	*do_rra(t_node *current, int bound)
{
	t_node	*new;

	new = (t_node*)ft_memalloc(sizeof(t_node));
	new = node_stackdup(new, current);
	if (!new ||
		!rev_rot(&(new->s_a)))
		ft_putstr_fd("Error in do_rra\n", 2);
	new->n_ops++;
	new->fitness = node_evaluate(new->s_a, new->s_b, new->n_ops, bound);
	new->ops = ft_strjoin(current->ops, "rra\n");
	new->next = NULL;
	new->last_op = RRA | (current->last_op & B_OPS);
	return (new);
}

t_node	*do_rrb(t_node *current, int bound)
{
	t_node	*new;

	new = (t_node*)ft_memalloc(sizeof(t_node));
	new = node_stackdup(new, current);
	if (!new ||
		!rev_rot(&(new->s_b)))
		ft_putstr_fd("Error in do_rrb\n", 2);
	new->n_ops++;
	new->fitness = node_evaluate(new->s_a, new->s_b, new->n_ops, bound);
	new->ops = ft_strjoin(current->ops, "rrb\n");
	new->next = NULL;
	new->last_op = RRB | (current->last_op & A_OPS);
	return (new);
}

t_node	*do_rrr(t_node *current, int bound)
{
	t_node	*new;

	new = (t_node*)ft_memalloc(sizeof(t_node));
	new = node_stackdup(new, current);
	if (!new ||
		!rev_rot(&(new->s_a)) ||
		!rev_rot(&(new->s_b)))
		ft_putstr_fd("Error in do_rrr\n", 2);
	new->n_ops++;
	new->fitness = node_evaluate(new->s_a, new->s_b, new->n_ops, bound);
	new->ops = ft_strjoin(current->ops, "rrr\n");
	new->next = NULL;
	new->last_op = RRA | RRB;
	return (new);
}
