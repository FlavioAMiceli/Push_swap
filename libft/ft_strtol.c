/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtol.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 13:48:34 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/01/19 17:49:42 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_strtol(const char *str)
{
	long int	result;
	int			i;
	long int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]) == TRUE)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == FALSE)
			return (sign * result);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
