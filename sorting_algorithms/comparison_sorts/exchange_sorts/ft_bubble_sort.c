/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bubble_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 09:41:02 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/10 09:41:03 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Bubble sort
**
**	Space: 	O(n) total, O(1) aux
**	Time:	O(n^2) worst/average, O(n) best
**	Swaps:	O(n^2) worst/average, O(1) best
**
**	In-place.
**	Practical only if input is already nearly sorted, also terminates earlier
**	then quick-sort (but not insertion sort!) if list is already sorted.
**
**	Iterates over array and swaps adjacent elements if they are order wrongly.
**
**	An alternative to bubble sort is insertion sort, since it also works well
**	for nearly sorted lists, and is better in general.
**	Cocktail sort is a bi-directional bubble sort.
**	Comb sort compares elements separated by large gaps,
**	making it more efficient on very wrongly placed element than bubble sort.
*/

int *ft_bubble_sort(int *arr, size_t len, int(*f)(int, int))
{
	int	i;
	int	pass;
	int	swapped;

	swapped = TRUE;
	pass = 0;
	while (swapped)
	{
		i = 1;
		swapped = FALSE;
		while (i < len - pass)
		{
			if (f(arr[i - 1], arr[i]) == FALSE)
			{
				ft_swap(&arr[i - 1], &arr[i]);
				swapped = TRUE;
			}
			i++;
		}
		pass++;
	}
	return (arr);
}
