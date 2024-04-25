/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:48:59 by wscherre          #+#    #+#             */
/*   Updated: 2024/03/11 19:50:38 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*head_a;
	t_stack			*head_b;
	int				n_ok;
}					t_stacks;

// BONUS
void				sort_it_bonus(t_stacks *stacks);
void				check_if_sorted(t_stacks *stacks);
int					run_str(t_stacks *stacks, char *str);
int					run_str_two(t_stacks *stacks, char *str);

// ERROR CHECKS
void				check_integers(t_stacks *stacks, char **argv);
void				check_int_size(t_stacks *stacks, char **argv);
void				check_for_doubles(t_stacks *stacks, t_stack *head_a);
void				print_error_and_exit(void);
void				check_inputs(t_stacks *stacks, int argc, char **argv);

// FREE
void				free_stacks(t_stacks *stacks);
void				free_node(t_stack **lst);

// LIST A
t_stack				*create_list_a(int argc, char **argv);
t_stack				*list_a_add_args(char **argv);
t_stack				*list_a_add_str(char **splt);
t_stack				*create_new_node(char **splt, t_stack *new_node,
						t_stack *head_a);

// MOVES
int					pa(t_stacks *stacks);
int					pb(t_stacks *stacks);
int					sa(t_stacks *stacks);
int					sb(t_stacks *stacks);
int					ss(t_stacks *stacks);
int					ra(t_stacks *stacks);
int					rb(t_stacks *stacks);
void				rr_of_a(t_stacks *stacks);
void				rr_of_b(t_stacks *stacks);
int					rr(t_stacks *stacks);
int					rra(t_stacks *stacks);
int					rrb(t_stacks *stacks);
void				rrr_of_a(t_stacks *stacks);
void				rrr_of_b(t_stacks *stacks);
int					rrr(t_stacks *stacks);

#endif