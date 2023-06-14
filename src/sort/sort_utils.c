/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:01:36 by makurz            #+#    #+#             */
/*   Updated: 2023/06/14 11:01:38 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

int	check_sorted(t_oop *stack)
{
	t_circle	*current;

	current = stack->top;
	while (1)
	{
		if (current->data > current->next->data)
			return (FALSE);
		current = current->next;
		if (current == stack->top->previous)
			break ;
	}
	return (TRUE);
}

int	forward_cost(t_oop *self, int rank, int sort)
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
		if (run->rank == rank && sort == SORT_SMALL)
			break ;
		if (run->rank <= rank && sort == SORT_BIG)
			break ;
	}
	return (cost);
}

int	reverse_cost(t_oop *self, int rank, int sort)
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
		if (run->rank == rank && sort == SORT_SMALL)
			break ;
		if (run->rank <= rank && sort == SORT_BIG)
			break ;
	}
	return (cost);
}
