/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:30:53 by work              #+#    #+#             */
/*   Updated: 2023/06/02 08:50:20 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "push_swap.h"

void	prepend(t_circle **head, t_circle *new_node)
{
	t_circle	*tmp;

	if (head == NULL)
	{
		*head = new_node;
		(*head)->next = new_node;
		(*head)->previous = new_node;
		return ;
	}
	tmp = (*head)->previous;
	(*head)->previous = new_node;
	tmp->next = new_node;
	new_node->previous = tmp;
	new_node->next = *head;
	*head = new_node;
}
