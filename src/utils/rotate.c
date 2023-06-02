/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:57:47 by work              #+#    #+#             */
/*   Updated: 2023/06/02 08:57:31 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	rotate(t_circle **head)
{
	if (*head == NULL)
		// TODO: error handling
		exit(1);
	if ((*head)->next == NULL)
		// TODO: error handling
		exit(1);
	*head = (*head)->next;
}
