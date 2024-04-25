/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:21:38 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/16 18:06:16 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_len(t_stack *head_a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = head_a;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	tab_len(t_tab *tab)
{
	t_tab	*tmp;
	int		i;

	i = 0;
	tmp = tab;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	tab_contains_x(t_stacks *stacks)
{
	t_tab	*tmp;
	char	*str;

	tmp = stacks->tab_a;
	while (tmp)
	{
		str = tmp->text;
		if (str[0] == 'x')
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	check_costs_b_to_a(t_stacks *stacks, t_stack *head)
{
	while (head)
	{
		if (stacks->cheap->cost == 0)
			cost_b_to_a(stacks, stacks->cheap, head);
		else
			cost_b_to_a(stacks, stacks->cheap_two, head);
		if ((stacks->cheap->cost > stacks->cheap_two->cost
				&& stacks->cheap_two->cost != 0))
			copy_cheap(stacks->cheap, stacks->cheap_two);
		reset_cheap(stacks->cheap_two);
		head = head->next;
	}
}

void	check_mirror_moves(t_stacks *stacks)
{
	while ((stacks->cheap->ra && stacks->cheap->rb) || (stacks->cheap->rra
			&& stacks->cheap->rrb))
	{
		if (stacks->cheap->ra && stacks->cheap->rb)
		{
			stacks->cheap->ra--;
			stacks->cheap->rb--;
			stacks->cheap->rr++;
		}
		if (stacks->cheap->rra && stacks->cheap->rrb)
		{
			stacks->cheap->rra--;
			stacks->cheap->rrb--;
			stacks->cheap->rrr++;
		}
	}
}
