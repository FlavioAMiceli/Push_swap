/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_selection_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 10:56:26 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/10 10:56:28 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Selection sort
**
**	Space: 	O(n) total, O(1) aux
**	Time:	O(n^2) constant
**	Swaps:	O(n) constant
**
**	In-place
**	Inefficient on large lists.
**	Time efficiency is linear with respect to swaps, both worst and best case
**	need n-1 swaps.
**
**	Finds current min in part of array to still be sorted, and places it at
**	correct location. Once placed, that element can be excluded in rest of sort.
**
**	An alternative to slection sort is insertion sort.
**	Insertion sort usually performs better, which is usually prefered.
**	In certain real-time applications howerver, selection sorts constant time
**	usage can be seen as an advantage.
*/

int	*ft_selection_sort(int *arr, size_t len, int(*f)(int, int))
{
	int	i;
	int	j;
	int	n;
	int min;

	n = len;
	i = 0;
	while (i < n - 1)
	{
		min = i;
		j = i + 1;
		while (j < n)
		{
			if (f(arr[j], arr[min]) == TRUE)
				min = j;
			j++;
		}
		if (min != i)
			ft_swap(a[i], a[min]);
		i++;
	}
	return (arr);
}
