/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:08:22 by wscherre          #+#    #+#             */
/*   Updated: 2024/03/11 19:41:32 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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

void	free_stacks(t_stacks *stacks)
{
	free_node(&stacks->head_a);
	free_node(&stacks->head_b);
}

void	free_all(t_stacks *stacks)
{
	free_node(&(stacks->head_a));
	free_node(&(stacks->head_b));
}
