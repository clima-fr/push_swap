/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clima-fr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:48:06 by clima-fr          #+#    #+#             */
/*   Updated: 2023/05/17 22:48:12 by clima-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	swap(&(*a));
	swap(&(*b));
	write(1, "ss\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(&(*a));
	rotate(&(*b));
	write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(&(*a));
	reverse_rotate(&(*b));
	write(1, "rrr\n", 4);
}
