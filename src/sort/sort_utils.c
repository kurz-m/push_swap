/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:10:53 by work              #+#    #+#             */
/*   Updated: 2023/06/10 00:36:05 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

int	forward_cost(t_oop *self, int rank)
{
	int			cost;
	t_circle	*run;

	cost = 0;
	run = self->top;
	if (run->rank == rank)
		return (cost);
	while (run->next != self->top)
	{
		run = run->next;
		cost++;
		if (run->rank == rank)
			break ;
	}
	return (cost);
}

int	reverse_cost(t_oop *self, int rank)
{
	int			cost;
	t_circle	*run;

	cost = 0;
	run = self->top;
	if (run->rank == rank)
		return (cost);
	while (run->previous != self->top)
	{
		run = run->previous;
		cost++;
		if (run->rank == rank)
			break ;
	}
	return (cost);
}
