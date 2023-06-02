/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:52:18 by work              #+#    #+#             */
/*   Updated: 2023/06/02 08:58:05 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	revrotate(t_circle **head)
{
	if (*head == NULL)
		// TODO: error handling
		exit(1);
	if ((*head)->previous == NULL)
		// TODO: error handling
		exit(1);
	*head = (*head)->previous;
}

