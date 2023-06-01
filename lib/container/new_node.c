/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:52:21 by makurz            #+#    #+#             */
/*   Updated: 2023/05/30 16:32:46 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "stack.h"

t_circle	*new_node(int data)
{
	t_circle	*new_node;

	new_node = NULL;
	new_node = (t_circle *) malloc(sizeof(t_circle));
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}
