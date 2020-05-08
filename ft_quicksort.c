/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_quicksort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 09:36:02 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/10 09:36:02 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Quick sort
**
**	Space: 	O(log n) worst case
**	Time:	O(n^2) worst, O(n log n) average, O(n) best
**
**	Quick.
**	Divide and conquer.
**	Unstable, relative order of equal value keys is not preserved.
**	Amenable to parallelization.
**
**	Picks a pivot from the array, reorders the array so all elements fall
**	on the correct side of the pivot. Recursively sorts these partitions.
**
**	If the relative order of keys is important, a quicksort variant that uses
**	more memory to store relative order could be used.
**	Merge sort is another stable alternative.
**	Heapsort could be better than quicksort in certain cases,
**	Introsort is a quicksort variant that switches to heapsort when a bad case
**	is detected.
**	Several other quicksort variants exist.
*/

/*
**	Move from edges of subarray towards eachother, until two elements are found
**	that should be swapped.
**	swap those elements and continue until indeces meet eachother.
**	return the position of the new pivot.
*/

static void	ft_swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

static int	*ft_insertion_sort(int *arr, size_t len)
{
	size_t	i;
	int		j;
	int		tmp;

	i = 1;
	while (i < len)
	{
		tmp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > tmp)
		{
			ft_swap(&arr[j + 1], &arr[j]);
			j--;
		}
		arr[j + 1] = tmp;
		i++;
	}
	return (arr);
}

static int	*hoare_partition(int *arr, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	pivot = arr[(low + ((high - low) / 2))];
	i = low;
	j = high;
	while (TRUE)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i >= j)
			return (&arr[j]);
		ft_swap(&arr[i], &arr[j]);
	}
}

/*
**	Switch to insertion sort when the list becomes small.
**	Sort smallest partition first to minimise memory usage.
*/

static int	*qs(int *arr, int low, int high)
{
	int	pivot_index;

	if (high - low < 10)
		ft_insertion_sort(&arr[low], (high - low) + 1);
	else if (low < high)
	{
		pivot_index = hoare_partition(arr, low, high) - arr;
		if ((pivot_index - low) < (high - pivot_index))
		{
			qs(arr, low, pivot_index);
			qs(arr, (pivot_index + 1), high);
		}
		else
		{
			qs(arr, (pivot_index + 1), high);
			qs(arr, low, pivot_index);
		}
	}
	return (arr);
}

int			*ft_quicksort(int *arr, size_t len)
{
	return (qs(arr, 0, len - 1));
}
