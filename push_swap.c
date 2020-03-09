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
#include "./heuristic_search/heuristic_search.h"

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

static void 	sift_to_b(t_stacks *s, int *sorted, int lo, int hi)
{
	if (hi - lo <= BASE_CASE_LEN)
		basecase_heuristic(&(s->a), &(s->b), hi - lo, 0);
	else
	{
		// SIFT
		// REVROT IF NEEDED
		sift_to_b(s, sorted, lo, (lo + hi) / 2);
		sift_to_a(s, sorted, lo, hi);
	}
}

static void 	sift_to_a(t_stacks *s, int *sorted, int lo, int hi)
{
	if (hi - lo <= BASE_CASE_LEN)
		basecase_heuristic(&(s->a), &(s->b), 0, hi - lo);
	else
	{
		// SIFT
		// REVROT IF NEEDED
		sift_to_b(s, sorted, lo, (lo + hi) / 2);
		sift_to_a(s, sorted, lo, hi);
	}
}

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

static void push_swap(t_stack **a, t_stack **b, int *sorted, int n)
{
	t_stacks	s;

	s.a = *a;
	s.b = *b;
	if (n <= BASE_CASE_LEN)
		basecase_heuristic(a, b, n, 0);
	else
		sift_to_b(&s, sorted, 0, n - 1);
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
