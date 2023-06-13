/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:53:33 by makurz            #+#    #+#             */
/*   Updated: 2023/06/13 13:45:27 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "libft.h"

#include "bonus.h"

static int	push_main(t_box *box, int move)
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
	}
	else if (move == PUSH_B)
	{
		tmp = box->a->pop(box->a);
		success = box->b->prepend(box->b, tmp);
		if (success == TRUE)
			update_elements(box, UPDATE_B);
	}
	if (success == FALSE)
		error_handling(box, PUSH);
	return (TRUE);
}

static int	swap_main(t_box *box, int move)
{
	int		success;

	success = TRUE;
	if (move == SWAP_A)
		success = box->a->swap(box->a);
	else if (move == SWAP_B)
		success = box->b->swap(box->b);
	else if (move == SWAP_ALL)
	{
		success &= box->a->swap(box->a);
		success &= box->b->swap(box->b);
	}
	if (success == FALSE)
		error_handling(box, SWAP);
	return (TRUE);
}

static int	rotate_main(t_box *box, int move)
{
	int		success;

	success = TRUE;
	if (move == ROT_A)
		success = box->a->rotate(box->a);
	else if (move == ROT_B)
		success = box->b->rotate(box->b);
	if (move == ROT_ALL)
	{
		success &= box->a->rotate(box->a);
		success &= box->b->rotate(box->b);
	}
	if (success == FALSE)
		error_handling(box, ROTATE);
	return (TRUE);
}

static int	revrotate_main(t_box *box, int move)
{
	int		success;

	success = TRUE;
	if (move == RROT_A)
		success = box->a->revrotate(box->a);
	else if (move == RROT_B)
		success = box->b->revrotate(box->b);
	if (move == RROT_ALL)
	{
		success &= box->a->revrotate(box->a);
		success &= box->b->revrotate(box->b);
	}
	if (success == FALSE)
		error_handling(box, REVROTATE);
	return (TRUE);
}

int	movements_bonus(t_box *box, int move)
{
	int		success;

	success = FALSE;
	if (move == SWAP_A || move == SWAP_B || move == SWAP_ALL)
		success = swap_main(box, move);
	else if (move == PUSH_A || move == PUSH_B)
		success = push_main(box, move);
	else if (move == ROT_A || move == ROT_B || move == ROT_ALL)
		success = rotate_main(box, move);
	else if (move == RROT_A || move == RROT_B || move == RROT_ALL)
		success = revrotate_main(box, move);
	else if (move == EOF)
		return (EOF);
	return (success);
}
