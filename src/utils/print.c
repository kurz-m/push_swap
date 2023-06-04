/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:15:17 by work              #+#    #+#             */
/*   Updated: 2023/06/04 15:16:47 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdio.h>

void	print(t_oop *self)
{
	t_circle	*current;

	current = self->top;
	while (1)
	{
		printf("Number: %i\n", current->data);
		current = current->next;
		if (current == self->top)
			break ;
	}
}
