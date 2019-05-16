/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_comb_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 16:05:34 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/16 16:05:35 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_comb_sort(int *arr, size_t len, int(*f)(int, int))
{
	int		gap;
	int		sorted;
	float	k;

	gap = len;
	sorted = false;
	k = 13;
	while (!sorted)
	{
		gap = ((gap * k) / 10);
		if (gap <= 1)
		{
			gap = 1;
			sorted = true;
		}
		i = 0;
		while (i + gap < len)
		{
			if (f(arr[i], arr[i + gap]) == false)
			{
				ft_swap(arr[i], arr[i + gap]);
				sorted = false;
			}
			i++;
		}
	}
	return (arr);
}
