/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:54:49 by makurz            #+#    #+#             */
/*   Updated: 2023/06/08 23:46:16 by work             ###   ########.fr       */
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

static void	sort_five(t_box *box)
{
}

void	sort_main(t_box *box)
{
	if (box->size == 3)
		sort_three(box);
}
