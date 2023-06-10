/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:29:56 by makurz            #+#    #+#             */
/*   Updated: 2023/06/10 22:39:41 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "push_swap.h"

static void	presort_to_b(t_box *box, int pivot, int *rank)
{
	while (box->a->elements > 0)
	{
		if (box->a->top->rank <= pivot + (*rank))
		{
			movements_main(box, PUSH_B);
			if (box->b->top->rank <= (*rank)++)
				movements_main(box, ROT_B);
		}
		else
			movements_main(box, ROT_A);
	}
}

static void	final_sort(t_box *box, int *rank)
{
	while (box->b->elements > 0)
	{
		while (box->b->top->rank != *rank)
		{
			if (forward_cost(box->b, *rank, 1) < reverse_cost(box->b, *rank, 1))
				movements_main(box, ROT_B);
			else
				movements_main(box, RROT_B);
		}
		movements_main(box, PUSH_A);
		(*rank)--;
	}
}

void	sort(t_box *box)
{
	int		rank;
	int		pivot;

	rank = 1;
	pivot = 11 + 0.06 * (box->size - 100);
	presort_to_b(box, pivot, &rank);
	--rank;
	final_sort(box, &rank);
}
