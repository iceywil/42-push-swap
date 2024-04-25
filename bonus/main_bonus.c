/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:00:34 by wscherre          #+#    #+#             */
/*   Updated: 2024/03/11 19:50:53 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_stack		*tmp;

	if (argc > 1)
	{
		stacks.n_ok = 0;
		check_inputs(&stacks, argc, argv);
		stacks.head_a = create_list_a(argc, argv);
		stacks.head_b = NULL;
		check_for_doubles(&stacks, stacks.head_a);
		tmp = stacks.head_a;
		sort_it_bonus(&stacks);
		check_if_sorted(&stacks);
	}
	return (0);
}

void	sort_it_bonus(t_stacks *stacks)
{
	char	*str;
	int		instru_nbr;
	int		flag;

	flag = 0;
	instru_nbr = 0;
	str = get_next_line(0);
	while (str)
	{
		instru_nbr = 1;
		if (ft_strlen(str) >= 3 && ft_strlen(str) <= 4)
			flag += run_str(stacks, str);
		else
			flag += 1;
		free(str);
		str = get_next_line(0);
	}
	if (flag > 0 || stacks->n_ok == 1)
		(free_stacks(stacks), print_error_and_exit());
	if (instru_nbr == 0)
		(check_if_sorted(stacks), exit(0));
}

int	run_str(t_stacks *stacks, char *str)
{
	if (str[2] == '\n' && !str[3])
	{
		if (str[1] == 'a')
		{
			if (str[0] == 'p')
				return (pa(stacks));
			else if (str[0] == 's')
				return (sa(stacks));
			else if (str[0] == 'r')
				return (ra(stacks));
		}
		else if (str[1] == 'b')
		{
			if (str[0] == 'p')
				return (pb(stacks));
			else if (str[0] == 's')
				return (sb(stacks));
			else if (str[0] == 'r')
				return (rb(stacks));
		}
		else if (str[0] == 'r' && str[1] == 'r')
			return (rr(stacks));
	}
	return (run_str_two(stacks, str));
}

int	run_str_two(t_stacks *stacks, char *str)
{
	if (str[0] == 'r' && str[1] == 'r' && str[3] == '\n' && !str[4])
	{
		if (str[2] == 'a')
			return (rra(stacks));
		else if (str[2] == 'b')
			return (rrb(stacks));
		else if (str[2] == 'r')
			return (rrr(stacks));
	}
	return (1);
}

void	check_if_sorted(t_stacks *stacks)
{
	t_stack	*tmp;

	tmp = stacks->head_a;
	if (stacks->head_b)
	{
		free_stacks(stacks);
		write(1, "KO\n", 3);
		exit(0);
	}
	while (tmp)
	{
		if (tmp->next && tmp->value > tmp->next->value)
		{
			free_stacks(stacks);
			write(1, "KO\n", 3);
			exit(0);
		}
		tmp = tmp->next;
	}
	free_stacks(stacks);
	write(1, "OK\n", 3);
}
