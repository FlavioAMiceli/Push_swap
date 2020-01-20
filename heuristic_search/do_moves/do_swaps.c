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

#include "push_swap.h"
#include "heuristic_search.h"

t_node	*do_sa(t_node *current)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new = node_stackdup(new, current);
	swap(&(new->stack_a));
	new->n_ops++;
	new->fitness = get_fitness(new->stack_a, new->stack_b, new->n_ops);
	new->ops = ft_strjoin(new->ops, "sa\n");
	new->next = NULL;
	return (new);
}

t_node	*do_sb(t_node *current)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new = node_stackdup(new, current);
	swap(&(new->stack_b));
	new->n_ops++;
	new->fitness = get_fitness(new->stack_a, new->stack_b, new->n_ops);
	new->ops = ft_strjoin(new->ops, "sb\n");
	new->next = NULL;
	return (new);
}

t_node	*do_ss(t_node *current)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new = node_stackdup(new, current);
	swap(&(new->stack_a));
	swap(&(new->stack_b));
	new->n_ops++;
	new->fitness = get_fitness(new->stack_a, new->stack_b, new->n_ops);
	new->ops = ft_strjoin(new->ops, "ss\n");
	new->next = NULL;
	return (new);
}
