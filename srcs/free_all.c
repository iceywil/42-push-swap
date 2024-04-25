/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:08:22 by wscherre          #+#    #+#             */
/*   Updated: 2024/01/17 17:57:10 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_node(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	lst = NULL;
}

void	free_values(t_stacks *stacks)
{
	if (stacks->values)
		free(stacks->values);
	stacks->values = NULL;
}

void	free_cheaps(t_stacks *stacks)
{
	if (stacks->cheap)
		free(stacks->cheap);
	if (stacks->cheap_two)
		free(stacks->cheap_two);
	stacks->cheap = NULL;
	stacks->cheap_two = NULL;
}

void	free_stacks(t_stacks *stacks)
{
	free_node(&stacks->head_a);
	free_node(&stacks->head_b);
}

void	free_all(t_stacks *stacks)
{
	free_node(&(stacks->head_a));
	free_node(&(stacks->head_b));
	free_cheaps(stacks);
	free_values(stacks);
}
