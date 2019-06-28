/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 18:32:48 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/14 18:32:49 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*set_stack(char **tab, int len)
{
	int	*stack;
	int	i;

	stack = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		stack[i] = ft_atoi(tab[i]);
		i++;
	}
	return (stack);
}

void 		init_stacks(t_stack **addr_a, t_stack **addr_b, char **tab, int len)
{
	(*addr_a)->size = len;
	(*addr_a)->len = len;
	(*addr_a)->stack = set_stack(tab, len);
	(*addr_a)->start = (*addr_a)->stack;
	(*addr_a)->end = (*addr_a)->stack + len - 1;
	(*addr_b)->size = len;
	(*addr_b)->len = 0;
	(*addr_b)->stack = (int *)malloc(sizeof(int) * len);
	(*addr_b)->start = (*addr_b)->stack;
	(*addr_b)->end = (*addr_b)->stack;
}
