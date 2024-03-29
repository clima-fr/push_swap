/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clima-fr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:48:20 by clima-fr          #+#    #+#             */
/*   Updated: 2023/05/17 22:48:24 by clima-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	sa(t_stack **a)
{
	swap(&(*a));
	write(1, "sa\n", 3);
}

void	ra(t_stack **a)
{
	rotate(&(*a));
	write(1, "ra\n", 3);
}

void	rra(t_stack **a)
{
	reverse_rotate(&(*a));
	write(1, "rra\n", 4);
}

void	pa(t_stack **a, t_stack **b)
{
	push(&(*a), &(*b));
	write(1, "pa\n", 3);
}
