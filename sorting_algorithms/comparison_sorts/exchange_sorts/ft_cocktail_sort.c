/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cocktail_sort.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 10:47:30 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/10 10:47:31 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Cocktail sort
**
**	Space: 	O(n) total, O(1) aux
**	Time:	O(n^2) worst/average, O(n) best
**	Swaps:	O(n^2) worst/average, O(1) best
**
**	In-place.
**	Practical only if input is already nearly sorted, also terminates earlier
**	then quick-sort (but not insertion sort!) if list is already sorted.
**
**	Iterates over array and swaps adjacent elements if they are order wrongly,
**	than moves backwards and does the same.
**
**	Insertion sort does everything better. Don't use cocktail sort.
*/

int *ft_cocktail_sort(int *arr, size_t len, int(*f)(int, int))
{
	int	i;
	int	pass;
	int	swapped;

	swapped = TRUE;
	pass = 0;
	while (swapped)
	{
		i = pass;
		swapped = FALSE;
		while (i < len - pass - 1)
		{
			if (f(arr[i], arr[i + 1]) == FALSE)
			{
				ft_swap(&arr[i], &arr[i + 1]);
				swapped = TRUE;
			}
			i++;
		}
		while (i > pass + 1)
		{
			if (f(arr[i - 1], arr[i]) == FALSE)
			{
				ft_swap(&arr[i - 1], &arr[i]);
				swapped = TRUE;
			}
			i--;
		}
		pass++;
	}
	return (arr);
}
