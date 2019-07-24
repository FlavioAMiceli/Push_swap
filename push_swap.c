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

static void	merge_to_a(t_stack **a, t_stack **b, int i)
{
	t_lengths	len_parts;
	int			n_parts;
	int			part;

	n_parts = get_n_parts(N_INTS, i);
	// ft_putstr("i:       "); ft_putnbr(i); ft_putchar('\n');
	// ft_putstr("n:       "); ft_putnbr(N_INTS); ft_putchar('\n');
	// ft_putstr("n_parts: "); ft_putnbr(n_parts); ft_putchar('\n');
	part = 0;
	while (part < n_parts / 2)
	{
		get_part_len(N_INTS, n_parts, part, &len_parts);
		merge_desc(b, a, TRUE, &len_parts);
		part++;
	}
	while (part < n_parts)
	{
		get_part_len(N_INTS, n_parts, part, &len_parts);
		merge_asc(b, a, TRUE, &len_parts);
		part++;
	}
}

static void	ps_merge(t_stack **a, t_stack **b, int i)
{
	int	n_parts;
	int	part;

	n_parts = get_n_parts(N_INTS, i);
	ft_putstr("i:       "); ft_putnbr(i); ft_putchar('\n');
	ft_putstr("n:       "); ft_putnbr(N_INTS); ft_putchar('\n');
	ft_putstr("n_parts: "); ft_putnbr(n_parts); ft_putchar('\n');
	part = 0;
	while (part < n_parts / 2)
	{
		get_part_len(N_INTS, n_parts, part, &len_parts);
		merge_asc(a, b, FALSE, &len_parts);
		part++;
	}
	while (part < n_parts)
	{
		get_part_len(N_INTS, n_parts, part, &len_parts);
		merge_desc(a, b, FALSE, &len_parts);
		part++;
	}
	if (i * 2 < ceil_log(2, N_INTS))
		merge_to_a(a, b, i + 1);
	else
		move_to_a(a, b);
}

static void	push_swap(t_stack **a, t_stack **b, int *sorted)
{
	int	i;

	i = 1;
	while (i * 2 < ceil_log(2, N_INTS))
	// while (!is_sorted(a, b, sorted, n))
	{
		ps_merge(a, b, i);
		i += 2;
	}
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
