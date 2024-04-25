/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:40:17 by wscherre          #+#    #+#             */
/*   Updated: 2024/03/11 17:37:17 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	check_inputs(int argc, char **argv)
{
	char	**splt;
	int		y;
	int		i;

	i = 0;
	y = 1;
	check_integers(argv);
	check_int_size(argv);
	if (argc > 2)
	{
		while (argv[y])
		{
			splt = ft_split(argv[y], ' ');
			if (!splt)
				print_error_and_exit();
			while (splt[i])
				i++;
			ft_free_double_tab(&splt);
			if (i > 1)
				print_error_and_exit();
			y++;
		}
	}
}

void	check_int_size(char **argv)
{
	char	**splt;
	int		y;
	int		i;

	y = 1;
	while (argv[y])
	{
		i = 0;
		splt = ft_split(argv[y++], ' ');
		if (!splt)
			print_error_and_exit();
		while (splt[i])
		{
			if (ft_strlen(splt[i]) > 11 || ft_atol(splt[i]) > INTMAX
				|| ft_atol(splt[i]) < INTMIN)
				(ft_free_double_tab(&splt), print_error_and_exit());
			i++;
		}
		ft_free_double_tab(&splt);
	}
}

void	check_integers(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '\0')
			print_error_and_exit();
		while (argv[i][j])
		{
			if ((argv[i][j] != ' ' && argv[i][j] != '-'
					&& !ft_isdigit(argv[i][j])))
				print_error_and_exit();
			if (argv[i][j] == '-' && (!ft_isdigit(argv[i][j + 1]) || argv[i][j
					+ 1] == '0'))
				print_error_and_exit();
			if (j != 0 && argv[i][j] == '-' && argv[i][j - 1] != ' ')
				print_error_and_exit();
			j++;
		}
		i++;
	}
}

void	check_for_doubles(t_stack *head_a)
{
	t_stack	*tmp;
	t_stack	*comp;

	tmp = head_a;
	while (tmp != NULL)
	{
		comp = head_a;
		while (comp != NULL)
		{
			if ((comp->value == tmp->value) && (tmp != comp))
			{
				free_node(&head_a);
				print_error_and_exit();
			}
			comp = comp->next;
		}
		tmp = tmp->next;
	}
}
