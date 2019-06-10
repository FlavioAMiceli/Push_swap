/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_counting_sort.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 18:25:03 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/07 18:25:04 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Counting sort
**
**	Space: 	O(n + k), where k is the range of key values.
**	Time:	O(n + k), where k is the range of key values.
**
**	Stable (important when used as subroutine for radix sort)
**	Highly space efficient when k << n.
**	parallelization is possible when k << n.
**	Not in-place when stable.
**
**	This implementation loops over all integers twice, and over an array the
**	size of the max key value once. When the max key is known, the first loop
**	can be cut.
**	Counting sort counts the amount of keys in each category, and then creates
**	an array with each key in the correct section.
**
**	If each item to be sorted is itself an integer, and used as key as well,
**	then the second and third loops of counting sort can be combined;
**	in the second loop,
**	instead of computing where items with key i should be placed in the output,
**	simply append tab[i] copies of the number i to the output.
*/

static	int	*cs(int *arr, size_t len, int k)
{
	int	*tab[k];
	int	*output;
	int	i;

	ft_bzero(tab, k);
	output = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		tab[arr[i]] += 1;
		i++;
	}
	i = 1;
	while (i <= k)
	{
		tab[i] = tab[i] + tab[i - 1];
	}
	i = len;
	while (i >= 0)
	{
		output[tab[arr[i]] = arr[i];
		tab[arr[i]] = tab[arr[i]] - 1;
		i--;
	}
	free (arr);
	return (output);
}

int	*ft_counting_sort(int *arr, size_t len, int(*f)(int, int))
{
	int	max;
	int	i;

	max = arr[0];
	i = 1;
	while (i < len)
	{
		max = max > arr[i] ? max : arr[i];
		i++;
	}
	arr = cs(arr, len, max);
	return (arr);
}
