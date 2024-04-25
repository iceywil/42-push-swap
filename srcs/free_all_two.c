/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:08:22 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/17 16:06:31 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_tab(t_tab **tab)
{
	t_tab	*tmp;

	if (!tab)
		return ;
	while (*tab)
	{
		tmp = (*tab)->next;
		free(*tab);
		*tab = tmp;
	}
	tab = NULL;
}

void	free_tabs(t_stacks *stacks)
{
	free_tab(&stacks->tab_a);
	free_tab(&stacks->tab_b);
}

int	find_num_index(t_stack *head, int num)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head->value == num)
			return (i);
		i++;
		head = head->next;
	}
	return (-1);
}
