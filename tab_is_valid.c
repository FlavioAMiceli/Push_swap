/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tab_is_valid.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 18:36:05 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/14 18:36:05 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_larger_than_max_int(char *str)
{
	long int n;

	if (ft_strlen(str) > 11 ||
		(ft_strlen(str) == 11 && str[0] != '+' && str[0] != '-'))
		return (TRUE);
	n = ft_strtol(str);
	if (n > FT_INT_MAX || n < FT_INT_MIN)
		return (TRUE);
	return (FALSE);
}

int			has_duplicates(int *tab, int n)
{
	int i;

	i = 0;
	while (i < n - 1)
	{
		if (tab[i] == tab[i + 1])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int	has_duplicate_str(char **tab, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (ft_strcmp(tab[i], tab[j]) == 0)
			return (TRUE);
		j++;
	}
	return (FALSE);
}

/*
** checks if each character in tab is an ascii digit
*/

int			tab_is_valid(char **tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		if (has_duplicate_str(tab, i))
			return (FALSE);
		j = 0;
		if (is_larger_than_max_int(tab[i]))
			return (FALSE);
		while (tab[i][j] != '\0')
		{
			if (ft_isdigit(tab[i][j]) == FALSE)
				if (j != 0 || (tab[i][0] != '+' && tab[i][0] != '-'))
					return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
