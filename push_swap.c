/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 18:05:33 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/14 18:05:34 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// More error checks. Empty input, letters as input,
// size of input int out of bound for int.

// static int		is_sorted(\
// 	t_stack **stack_a, t_stack **stack_b, int *sorted, int n)
// {
// 	shift_stack(stack_a);
// 	if ((*stack_b)->len != 0
// 	|| ft_memcmp(sorted, (*stack_a)->start, n * sizeof(int)) != 0)
// 	{
// 		del_stacks(stack_a, stack_b);
// 		return (FALSE);
// 	}
// 	del_stacks(stack_a, stack_b);
// 	return (TRUE);
// }

static void	push_swap(t_stack **a, t_stack **b, int *sorted)
{

}

int			main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		sorted_tab[argc - 1];

	if (argc < 2 || tab_is_valid(&argv[1], argc - 1) == FALSE)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	init_stacks(&stack_a, &stack_b, &argv[1], argc - 1);
	(void)set_tab(sorted_tab, &argv[1], argc - 1);
	(void)ft_quicksort(sorted_tab, argc - 1);
	push_swap(&stack_a, &stack_b, sorted_tab);
	return (0);
}
