/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_shmol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:48:04 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/01 02:36:05 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_shmol(t_stack **a)
{
	int	len;
	
	if (is_sorted(*a))
		return ;
	len = get_stack_len(*a);
	if (len == 2)
		return sa(a, true);
	if (len != 3)
		return ;
	//ft_printf("top : %d; biggest : %d", get_top(*a)->val, get_biggest(*a)->val);
	if (get_top(*a)->val == get_biggest(*a)->val)
		ra(a, true);
	else if ((*a)->next->val == get_biggest(*a)->val)
		rra(a, true);
	if (!is_sorted(*a))
		sa(a, true);
}
