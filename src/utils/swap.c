/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:00:20 by work              #+#    #+#             */
/*   Updated: 2023/06/02 09:09:06 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

t_circle	*swap(t_circle *stack)
{
	t_circle	*tmp;

	if (stack == NULL)
		// TODO: empty struct error handling
		exit(1);
	if (stack->next == NULL)
		// TODO: empty struct error handling
		exit(1);
	tmp = stack->next;
	tmp->next->previous = stack;
	stack->next = tmp->next;
	tmp->next = stack;
	tmp->previous = stack->previous;
	tmp->previous->next = tmp;
	stack->previous = tmp;
	return (tmp);
}
