/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:54:49 by makurz            #+#    #+#             */
/*   Updated: 2023/06/09 16:55:50 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "push_swap.h"

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

static void	sort_three(t_box *box)
{
	if (box->a->top->rank > box->a->top->next->rank
		&& box->a->top->rank > box->a->top->previous->rank)
		movements_main(box, ROT_A);
	else if (box->a->top->previous->rank < box->a->top->next->rank)
		movements_main(box, RROT_A);
	if (box->a->top->rank > box->a->top->next->rank)
		movements_main(box, SWAP_A);
}

#include <stdio.h>

static void	sort_five(t_box *box)
{
	int		rank;

	rank = 1;
	while (box->a->elements > 3)
	{
		// printf("elements a: %i\n", box->a->elements);
		// printf("elements b: %i\n", box->b->elements);
		while (box->a->top->rank != rank)
		{
			// printf("forward: %i\nreverse: %i\n", forward_cost(box->a, rank), reverse_cost(box->a, rank));
			if (forward_cost(box->a, rank) < reverse_cost(box->a, rank))
				movements_main(box, ROT_A);
			else
				movements_main(box, RROT_A);
		}
		movements_main(box, PUSH_B);
		// box->a->print(box->a);
		rank++;
	}
	sort_three(box);
	while (box->b->elements > 0)
		movements_main(box, PUSH_A);
}

void	sort_main(t_box *box)
{
	if (box->size == 3)
		sort_three(box);
	else if (box->size <= 5)
		sort_five(box);
}
