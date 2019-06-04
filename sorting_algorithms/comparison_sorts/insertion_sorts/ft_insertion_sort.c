/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_insertion_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 15:21:20 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/10 15:21:21 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Insertion sort
**
**	Space: 	O(n) total, O(1) aux
**	Time:	O(n^2) worst/average, O(n) best
**	Swaps:	O(n^2) worst/average, O(1) sbest
**
**	In-place
**	Inefficient on large lists.
**	Time efficiency is better than most other quadratic algorithms.
**	Adaptive, efficient for nearly sorted arrays.
**
**	Places the k'th unsorted element at the correct position in a already
**	sorted list.
**
**	An alternative so insertion sort is selection sort, which is generaly slower
**	but requires less writes. On devices where writing is expensive, selection
**	sort might perform better. Selection sort also has constant time, which
**	might make it atractive for use in real-time applications.
*/

int	*ft_insertion_sort(int *arr, size_t len, int(*f)(int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i - 1;
		while (j >= 0 && f(arr[j - 1], arr[j]) == FALSE)
		{
			ft_swap(&arr[j - 1], &arr[j]);
			j--;
		}
		i++;
	}
	return (arr);
}
