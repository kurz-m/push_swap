/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:51:52 by work              #+#    #+#             */
/*   Updated: 2023/06/06 18:27:25 by work             ###   ########.fr       */
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

// void	sort_main(t_container *container)
// {
// }
