/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_shmol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:48:04 by jde-meo           #+#    #+#             */
/*   Updated: 2023/12/19 16:21:00 by jde-meo          ###   ########.fr       */
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
		return (sa(a, TRUE));
	if (len != 3)
		return ;
	if (get_top(*a)->val == get_biggest(*a)->val)
		ra(a, TRUE);
	else if ((*a)->next->val == get_biggest(*a)->val)
		rra(a, TRUE);
	if (!is_sorted(*a))
		sa(a, TRUE);
}
