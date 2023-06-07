/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:54:32 by makurz            #+#    #+#             */
/*   Updated: 2023/06/07 14:49:23 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "libft.h"
#include "push_swap.h"

static void	push_main(t_box *box, int move)
{
	int			success;
	t_circle	*tmp;

	success = TRUE;
	if (move == PUSH_A)
	{
		tmp = box->b->top;
		box->b->pop(box->b);
		success = box->a->prepend(box->a, tmp);
		if (success == TRUE)
			write(1, "pa\n", 3);
	}
	else if (move == PUSH_B)
	{
		tmp = box->a->top;
		box->a->pop(box->a);
		success = box->b->prepend(box->b, tmp);
		if (success == TRUE)
			write(1, "pb\n", 3);
	}
	if (success == FALSE)
		error_handling(box, PUSH);
}

static void	swap_main(t_box *box, int move)
{
	int		success;

	success = TRUE;
	if (move == SWAP_A)
	{
		success = box->a->swap(box->a);
		if (success == TRUE)
			write(1, "sa\n", 3);
	}
	else if (move == SWAP_B)
	{
		success = box->b->swap(box->b);
		if (success == TRUE)
			write(1, "sb\n", 3);
	}
	else if (move == SWAP_ALL)
	{
		success &= box->a->swap(box->a);
		success &= box->b->swap(box->b);
		if (success == TRUE)
			write(1, "ss\n", 3);
	}
	if (success == FALSE)
		error_handling(box, SWAP);
}

static void	rotate_main(t_box *box, int move)
{
	int		success;

	success = TRUE;
	if (move == ROT_A)
	{
		success = box->a->rotate(box->a);
		if (success == TRUE)
			write(1, "ra\n", 3);
	}
	else if (move == ROT_B)
	{
		success = box->b->rotate(box->b);
		if (success == TRUE)
			write(1, "rb\n", 3);
	}
	if (move == ROT_ALL)
	{
		success &= box->a->rotate(box->a);
		success &= box->b->rotate(box->b);
		if (success == TRUE)
			write(1, "rr\n", 3);
	}
	if (success == FALSE)
		error_handling(box, ROTATE);
}

static void	revrotate_main(t_box *box, int move)
{
	int		success;

	success = TRUE;
	if (move == ROT_A)
	{
		success = box->a->revrotate(box->a);
		if (success == TRUE)
			write(1, "rra\n", 3);
	}
	else if (move == ROT_B)
	{
		success = box->b->revrotate(box->b);
		if (success == TRUE)
			write(1, "rrb\n", 3);
	}
	if (move == ROT_ALL)
	{
		success &= box->a->revrotate(box->a);
		success &= box->b->revrotate(box->b);
		if (success == TRUE)
			write(1, "rrr\n", 3);
	}
	if (success == FALSE)
		error_handling(box, REVROTATE);
}

void	movements_main(t_box *box, int	move)
{
	if (move == SWAP_A || move == SWAP_B || move == SWAP_ALL)
		swap_main(box, move);
	else if (move == PUSH_A || move == PUSH_B)
		push_main(box, move);
	else if (move == ROT_A || move == ROT_B || move == ROT_ALL)
		rotate_main(box, move);
	else if (move == RROT_A || move == RROT_B || move == RROT_ALL)
		rotate_main(box, move);
}
