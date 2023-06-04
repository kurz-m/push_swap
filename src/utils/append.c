/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:02:40 by work              #+#    #+#             */
/*   Updated: 2023/06/03 21:34:06 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "push_swap.h"

// void	append(t_circle **head, t_circle *new_node)
// {
// 	t_circle	*tmp;
// 
// 	if (head == NULL)
// 	{
// 		*head = new_node;
// 		(*head)->next = new_node;
// 		(*head)->previous = new_node;
// 		return ;
// 	}
// 	tmp = (*head)->previous;
// 	(*head)->previous = new_node;
// 	tmp->next = new_node;
// 	new_node->previous = tmp;
// 	new_node->next = *head;
// }

void	append(t_oop *self, t_circle *new_node)
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
}
