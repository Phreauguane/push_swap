/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:36:40 by jde-meo           #+#    #+#             */
/*   Updated: 2023/12/19 16:24:08 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include "limits.h"

# define TRUE 1
# define FALSE 0

typedef unsigned char	t_bool;

typedef struct s_stack
{
	int				val;
	int				pos;
	int				rev_pos;
	int				push_price;
	t_bool			to_rev;
	struct s_stack	*fst_to_push;
	struct s_stack	*targ;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*  Utilities  */
void	exit_handler(char *msg);
int		max(int i, int j);
int		min(int i, int j);

/*  Stack related functions  */
t_stack	*init_stack(int ac, char **av);
t_stack	*create_node(long int value);
void	push_node(t_stack **a, t_stack *node);
void	print_stacks(t_stack *a, t_stack *b);
t_stack	*get_biggest(t_stack *stack);
t_stack	*get_top(t_stack *a);
t_stack	*get_smallest(t_stack *a);
t_stack	*get_top2(t_stack *a);
t_stack	*pop(t_stack **a);
int		get_stack_len(t_stack *s);
t_stack	*get_i(t_stack *s, int i);
t_bool	is_sorted(t_stack *a);
void	free_stack(t_stack **s);
t_bool	is_biggest(t_stack *e, t_stack *a);
t_bool	is_smallest(t_stack *e, t_stack *a);
t_stack	*get_smallest_bigger(t_stack *s, int val);
void	node_refresh(t_stack *a, t_stack *b);

/*  Operations  */
/* stack a      */
void	sa(t_stack **a, t_bool print);
void	pa(t_stack **a, t_stack **b, t_bool print);
void	ra(t_stack **a, t_bool print);
void	rra(t_stack **a, t_bool print);
/* stack b      */
void	sb(t_stack **b, t_bool print);
void	pb(t_stack **b, t_stack **a, t_bool print);
void	rb(t_stack **b, t_bool print);
void	rrb(t_stack **b, t_bool print);
/* both stacks  */
void	ss(t_stack **a, t_stack **b, t_bool print);
void	rr(t_stack **a, t_stack **b, t_bool print);
void	rrr(t_stack **a, t_stack **b, t_bool print);

/*  Sorting Algorithms  */
void	sort_shmol(t_stack **a);
void	calc_prices(t_stack *a, t_stack *b);
void	push_swap(t_stack **a, t_stack **b);
t_stack	*rev(t_stack *e);

#endif