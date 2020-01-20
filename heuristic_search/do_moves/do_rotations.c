/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_rotations.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:45:25 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/20 16:45:25 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "heuristic_search.h"

t_node	*do_ra(t_node *current)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new = node_stackdup(new, current);
	rot(&(new->stack_a));
	new->n_ops++;
	new->fitness = get_fitness(new->stack_a, new->stack_b, new->n_ops);
	new->ops = ft_strjoin(new->ops, "ra\n");
	new->next = NULL;
	return (new);
}

t_node	*do_rb(t_node *current)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new = node_stackdup(new, current);
	rot(&(new->stack_b));
	new->n_ops++;
	new->fitness = get_fitness(new->stack_a, new->stack_b, new->n_ops);
	new->ops = ft_strjoin(new->ops, "rb\n");
	new->next = NULL;
	return (new);
}

t_node	*do_rr(t_node *current)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new = node_stackdup(new, current);
	rot(&(new->stack_a));
	rot(&(new->stack_b));
	new->n_ops++;
	new->fitness = get_fitness(new->stack_a, new->stack_b, new->n_ops);
	new->ops = ft_strjoin(new->ops, "rr\n");
	new->next = NULL;
	return (new);
}
