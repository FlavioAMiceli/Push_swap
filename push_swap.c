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

// static	void sift(\
// 	t_stack **a, t_stack **b, int low, int hi, int *sorted, t_list **ops)
// {
// 	int	i;
//
// 	i = 0;
// 	while (i < hi - low)
// 	{
// 		if ((*a)->start[0] < sorted[(low + hi) / 2])
// 		{
// 			if ((*a)->start[1] < (*a)->start[0])
// 			{
// 				swap(a);
// 				ft_lstadd(ops, ft_lstnew("sa", 3));
// 				push(a, b);
// 				ft_lstadd(ops, ft_lstnew("pb", 3));
// 			}
// 			push(a, b);
// 			ft_lstadd(ops, ft_lstnew("pb", 3));
// 		}
// 		else
// 		{
// 			if ((*a)->start[1] > (*a)->start[0])
// 			{
// 				swap(a);
// 				ft_lstadd(ops, ft_lstnew("sa", 3));
// 				rot(a);
// 				ft_lstadd(ops, ft_lstnew("ra", 3));
// 			}
// 			rot(a);
// 			ft_lstadd(ops, ft_lstnew("ra", 3));
// 		}
// 		i--;
// 	}
// }

static int		is_sorted(\
	t_stack **stack_a, t_stack **stack_b, int *sorted, int n)
{
	shift_stack(stack_a);
	if ((*stack_b)->len != 0
	|| ft_memcmp(sorted, (*stack_a)->stack, n * sizeof(int)) != 0)
	{
		del_stacks(stack_a, stack_b);
		return (FALSE);
	}
	del_stacks(stack_a, stack_b);
	return (TRUE);
}

// static void push_swap(t_stack **a, t_stack **b, int *sorted, int n)
// {
// 	t_list	*ops;
// 	int		hi;
//
// 	ops = NULL;
// 	hi = n - 1;
// 	while (!is_sorted(a, b, sorted, n))
// 	{
// 		sift(a, b, 0, hi, sorted, &ops);
// 		sift(a, b, hi / 2, hi, sorted, &ops);
// 		shift_stack(a);
// 		for (int i = 0; i < n; i++)
// 		{
// 			ft_putnbr((*a)->stack[i]);
// 			ft_putchar('\n');
// 		}
// 		ft_putchar('\n');
// 	}
// }

static void push_swap(t_stack **a, t_stack **b, int *sorted, int n)
{
	int	to_b;

	to_b = TRUE;
	if (n <= BASE_CASE_LEN)
		basecase_heuristic(to_b ? a : b, TRUE, n);
	else
		ft_putstr("N TOO LARGE, ONLY BASECASE!");
	if (is_sorted(a, b, sorted, n))
		ft_putstr("Succes!");
	else
		ft_putstr("Boo!");
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
	push_swap(&stack_a, &stack_b, sorted_tab, argc - 1);
	return (0);
}

/*
**	1. Pick pivot.
**	2. Remember n and m numbers before and after pivot.
**	3. For n, if num < pivot && num < num + 1 push,
**		else if num > num + 1 swap and push,
**		else rotate.
**	4. Push pivot
**	5. For m, if num < pivot && num < num + 1 push,
**		else if num > num + 1 swap and push,
**		else rotate.
**	6. Reverse rotate other stack.
**	7. Repeat?
**	8. Done?
*/
