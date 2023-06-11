/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:54:32 by makurz            #+#    #+#             */
/*   Updated: 2023/06/12 01:40:09 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "push_swap.h"

#include "movements.h"

static void	push_main(t_box *box, int move)
{
	int			success;
	t_circle	*tmp;

	success = TRUE;
	if (move == PUSH_A)
	{
		tmp = box->b->pop(box->b);
		success = box->a->prepend(box->a, tmp);
		if (success == TRUE)
			update_elements(box, UPDATE_A);
		if (success == TRUE)
			print_cmd("pa\n");
	}
	else if (move == PUSH_B)
	{
		tmp = box->a->pop(box->a);
		success = box->b->prepend(box->b, tmp);
		if (success == TRUE)
			update_elements(box, UPDATE_B);
		if (success == TRUE)
			print_cmd("pb\n");
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
			print_cmd("sa\n");
	}
	else if (move == SWAP_B)
	{
		success = box->b->swap(box->b);
		if (success == TRUE)
			print_cmd("sb\n");
	}
	else if (move == SWAP_ALL)
	{
		success &= box->a->swap(box->a);
		success &= box->b->swap(box->b);
		if (success == TRUE)
			print_cmd("ss\n");
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
			print_cmd("ra\n");
	}
	else if (move == ROT_B)
	{
		success = box->b->rotate(box->b);
		if (success == TRUE)
			print_cmd("rb\n");
	}
	if (move == ROT_ALL)
	{
		success &= box->a->rotate(box->a);
		success &= box->b->rotate(box->b);
		if (success == TRUE)
			print_cmd("rr\n");
	}
	if (success == FALSE)
		error_handling(box, ROTATE);
}

static void	revrotate_main(t_box *box, int move)
{
	int		success;

	success = TRUE;
	if (move == RROT_A)
	{
		success = box->a->revrotate(box->a);
		if (success == TRUE)
			print_cmd("rra\n");
	}
	else if (move == RROT_B)
	{
		success = box->b->revrotate(box->b);
		if (success == TRUE)
			print_cmd("rrb\n");
	}
	if (move == RROT_ALL)
	{
		success &= box->a->revrotate(box->a);
		success &= box->b->revrotate(box->b);
		if (success == TRUE)
			print_cmd("rrr\n");
	}
	if (success == FALSE)
		error_handling(box, REVROTATE);
}

void	movements_main(t_box *box, int move)
{
	if (move == SWAP_A || move == SWAP_B || move == SWAP_ALL)
		swap_main(box, move);
	else if (move == PUSH_A || move == PUSH_B)
		push_main(box, move);
	else if (move == ROT_A || move == ROT_B || move == ROT_ALL)
		rotate_main(box, move);
	else if (move == RROT_A || move == RROT_B || move == RROT_ALL)
		revrotate_main(box, move);
}
