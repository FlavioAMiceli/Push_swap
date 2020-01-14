/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_management.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 18:32:48 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/14 18:32:49 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Converts strings in tab to an int array.
*/
static int	*tab_to_stack(char **tab, int len)
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

/*
**	Frees both t_stacks.
*/
void		del_stacks(t_stack **addr_a, t_stack **addr_b)
{
	free((*addr_a)->stack);
	free((*addr_b)->stack);
	free(*addr_a);
	free(*addr_b);
}

/*
**	Initializes both the a and b stack.
**	Puts all ints from the tab to stack a.
**	Sets all atrributes to correct values.
*/
void		init_stacks(
	t_stack **addr_a, t_stack **addr_b, char **tab, int len)
{
	init_stacks_no_tab(addr_a, addr_b, len, sizeof(int));
	(*addr_a)->stack = (int *)malloc(sizeof(int) * len);
	(*addr_a)->stack = tab_to_stack((*addr_a)->stack, tab, len);
	(*addr_a)->start = (*addr_a)->stack;
	(*addr_a)->end = (*addr_a)->stack + (len - 1);
	(*addr_b)->stack = (int *)malloc(sizeof(int) * len);
	(*addr_b)->start = (*addr_b)->stack;
	(*addr_b)->end = (*addr_b)->stack;
}

/*
**	Like init_stacks_tab,
**	but stack itself aswell as start and end remain untouched.
*/
void		init_stacks_no_tab(
	t_stack **addr_a, t_stack **addr_b, size_t len, size_t size_type)
{
	*addr_a = (t_stack *)malloc(sizeof(t_stack));
	*addr_b = (t_stack *)malloc(sizeof(t_stack));
	(*addr_a)->size = len * size_type;
	(*addr_a)->len = len;
	(*addr_b)->size = len * size_type;
	(*addr_b)->len = 0;
}
