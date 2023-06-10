/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:54:49 by makurz            #+#    #+#             */
/*   Updated: 2023/06/10 22:31:22 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "push_swap.h"

static void	sort_three(t_box *box)
{
	if (check_sorted(box->a))
		return ;
	if (box->a->top->rank > box->a->top->next->rank
		&& box->a->top->rank > box->a->top->previous->rank)
		movements_main(box, ROT_A);
	else if (box->a->top->previous->rank < box->a->top->next->rank)
		movements_main(box, RROT_A);
	if (box->a->top->rank > box->a->top->next->rank)
		movements_main(box, SWAP_A);
}

static void	sort_five(t_box *box)
{
	int		rank;

	rank = 1;
	while (box->a->elements > 3)
	{
		while (box->a->top->rank != rank)
		{
			if (forward_cost(box->a, rank, 1) < reverse_cost(box->a, rank, 1))
				movements_main(box, ROT_A);
			else
				movements_main(box, RROT_A);
		}
		if (check_sorted(box->a) == TRUE)
			break ;
		movements_main(box, PUSH_B);
		rank++;
	}
	if (check_sorted(box->a) == TRUE)
	{
		while (box->b->elements > 0)
			movements_main(box, PUSH_A);
	}
	sort_three(box);
	while (box->b->elements > 0)
		movements_main(box, PUSH_A);
}

void	sort_main(t_box *box)
{
	if (box->size == 2)
		movements_main(box, SWAP_A);
	else if (box->size == 3)
		sort_three(box);
	else if (box->size <= 5)
		sort_five(box);
	else
		sort(box);
}
