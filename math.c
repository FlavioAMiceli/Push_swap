/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/12 00:41:26 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/07/12 00:41:26 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ceil_log(int exp, int base)
{
	int res;

	if (base == 0)
		ft_putendl_fd("ERROR: ceil_log/2 doesn't take 0 as base!", 2);
	else if (base == 1)
		return (0);
	else if (base == exp)
		return (1);
	res = 1;
	if (base > exp)
	{
		while (base > 1)
		{
			base /= exp;
			res++;
		}
		return (res);
	}
	base *= exp;
	while (base < 1)
	{
		base *= exp;
		res--;
	}
	return (res);
}

int	get_n_parts(int n, int i)
{
	int n_parts;

	n_parts = 2;
	i_left = ceil_log(2, n) - i;
	while (n_parts < n && i_left > 1)
	{
		n_parts *= 2;
		i_left--;
	}
	return (n_parts);
}
