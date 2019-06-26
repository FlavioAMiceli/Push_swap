/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_stack.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 18:32:48 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/14 18:32:49 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*set_stack(t_stack **astack, char **tab, int len)
{
	int	i;
	int	*num;

	i = len - 1;
	while (i >= 0)
	{
		num = (int *)malloc(sizeof(int));
		*num = ft_atoi(tab[i]);
		ft_dlladd(&(*astack)->head, ft_dllnew(num, sizeof(int)));
		i--;
	}
	return (*astack);
}
