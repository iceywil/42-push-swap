/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:40:17 by wscherre          #+#    #+#             */
/*   Updated: 2024/03/12 18:12:24 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	check_inputs(t_stacks *stacks, int argc, char **argv)
{
	char	**splt;
	int		y;
	int		i;

	i = 0;
	y = 1;
	check_integers(stacks, argv);
	check_int_size(stacks, argv);
	if (argc > 2)
	{
		while (argv[y])
		{
			splt = ft_split(argv[y], ' ');
			if (!splt)
				stacks->n_ok = 1;
			while (splt[i])
				i++;
			ft_free_double_tab(&splt);
			if (i > 1)
				stacks->n_ok = 1;
			y++;
		}
	}
}

void	check_int_size(t_stacks *stacks, char **argv)
{
	char	**splt;
	int		y;
	int		i;

	y = 1;
	while (argv[y])
	{
		i = -1;
		splt = ft_split(argv[y++], ' ');
		if (!splt)
		{
			stacks->n_ok = 1;
			return ;
		}
		while (splt[++i])
		{
			if (ft_strlen(splt[i]) > 11 || ft_atol(splt[i]) > INTMAX
				|| ft_atol(splt[i]) < INTMIN)
			{
				(ft_free_double_tab(&splt), stacks->n_ok = 1);
				return ;
			}
		}
		ft_free_double_tab(&splt);
	}
}

void	check_integers(t_stacks *stacks, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '\0')
			stacks->n_ok = 1;
		while (argv[i][j])
		{
			if ((argv[i][j] != ' ' && argv[i][j] != '-'
					&& !ft_isdigit(argv[i][j])))
				stacks->n_ok = 1;
			if (argv[i][j] == '-' && (!ft_isdigit(argv[i][j + 1]) || argv[i][j
					+ 1] == '0'))
				stacks->n_ok = 1;
			if (j != 0 && argv[i][j] == '-' && argv[i][j - 1] != ' ')
				stacks->n_ok = 1;
			j++;
		}
		i++;
	}
}

void	check_for_doubles(t_stacks *stacks, t_stack *head_a)
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
				stacks->n_ok = 1;
			comp = comp->next;
		}
		tmp = tmp->next;
	}
}
