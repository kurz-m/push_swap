/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:54:49 by makurz            #+#    #+#             */
/*   Updated: 2023/06/07 18:02:57 by makurz           ###   ########.fr       */
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
	if (box->a->top->index > box->a->top->next->index
			&& box->a->top->index > box->a->top->previous->index)
		movements_main(box, ROT_A);
	else if (box->a->top->previous->index < box->a->top->next->index)
		movements_main(box, RROT_A);
	if (box->a->top->index > box->a->top->next->index)
		movements_main(box, SWAP_A);
}

void	sort_main(t_box *box)
{
	if (box->max == 3)
		sort_three(box);
}
