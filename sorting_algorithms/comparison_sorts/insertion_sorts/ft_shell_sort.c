/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shell_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 18:32:20 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/05 18:32:21 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Shell sort
**
**	Space: 	O(n) total, O(1) aux
**	Time:	O(n^2) worst, O(n log n) best
**
**	In place, unstable.
**
**	Starts sorting pairs of elements that are far from eachother,
**	decreasing distance over time.
**	Determening time complexity depends on gap sequence, and is an open problem.
*/

static	int	*sh_sort(int *arr, size_t len, int(*f)(int, int), int *gaps)
{
	int	i;
	int	j;
	int	temp;

	while (*gaps != 1)
	{
		i = *gaps;
		while (i < len)
		{
			temp = arr[i];
			j = i;
			while (j >= *gaps && a[j - *gaps] > temp)
			{
				a[j] = a[j - gap];
				j -= *gaps;
			}
			i++;
		}
		gaps++;
	}
	return (arr);
}

int	*ft_shell_sort(int *arr, size_t len, int(*f)(int, int))
{
	int	*gap_seq[8] = {701, 301, 132, 57, 23, 10, 4, 1};

	return(sh_sort(arr, len, f, gap_seq));
}
