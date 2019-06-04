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

/*
**	Comb sort
**
**	Space: 	O(n) total, O(1) aux
**	Time:	O(n^2) worst, Ω(n^2/2^p) average, Θ(n log n) best
**
**	In-place.
**	Better at dealing with small values at the end of the list than bubblesort.
**
**	Performs bubble sort-like swaps, but at a distance instead of over adjacent
**	elements. This improves the rate at which small values move to the front.
**
**	Shell sort is a similar working algorithm that proves to be more efficient.
*/


int	*ft_comb_sort(int *arr, size_t len, int(*f)(int, int))
{
	int		gap;
	int		sorted;
	float	k;

	gap = len;
	sorted = FALSE;
	k = 13;
	while (!sorted)
	{
		gap = ((gap * k) / 10);
		if (gap <= 1)
		{
			gap = 1;
			sorted = TRUE;
		}
		i = 0;
		while (i + gap < len)
		{
			if (f(arr[i], arr[i + gap]) == FALSE)
			{
				ft_swap(arr[i], arr[i + gap]);
				sorted = FALSE;
			}
			i++;
		}
	}
	return (arr);
}
