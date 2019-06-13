/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 08:08:04 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/10 08:08:06 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO: WRITE IS_VALID

static int		is_valid(t_list **alst, int n_inst, char **tab)
{
	t_list	*current;

	current = *alst;
	ft_putendl("Printing instructions:");
	while (current)
	{
		ft_putendl(current->content);
		current = current->next;
	}
	ft_putendl("Printing tab:");
	while (n_inst)
	{
		ft_putendl(*tab);
		ft_putchar('\n');
		tab++;
	}
	return (TRUE);
}

static t_list	**get_instructions(t_list **alst)
{
	t_list	*current;
	char	**line;

	line = (char **)malloc(sizeof(char*));
	get_next_line(0, line);
	if (*line)
	{
		ft_putendl(*line);
		current = ft_lstnew(*line, ft_strlen(*line));
		*alst = current;
		current = current->next;
		free(*line);
		get_next_line(0, line);
	}
	while (ft_strlen(*line))
	{
		ft_putendl(*line);
		ft_lstappend(&current, ft_lstnew(*line, ft_strlen(*line)));
		current = current->next;
		free(*line);
		get_next_line(0, line);
	}
	free(*line);
	free(line);
	is_valid(alst, 0, NULL);
	return (alst);
}

int			main(int argc, char **argv)
{
	t_list	**addr_instructions;
	int		arr[argc - 1];
	int		i;

	addr_instructions = get_instructions(addr_instructions);
	if (is_valid(addr_instructions, argc - 1, &argv[1]) == FALSE)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		arr[i] = ft_atoi(argv[i]);
		ft_putnbr(arr[i]);
		ft_putchar('\n');
		i++;
	}
	// if (checker(argc - 1, addr_instructions))
	// 	ft_putendl("OK");
	// else
	// 	ft_putendl("KO");
	return (0);
}
