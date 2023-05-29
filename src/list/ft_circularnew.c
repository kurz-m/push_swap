/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circularnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:52:21 by makurz            #+#    #+#             */
/*   Updated: 2023/05/29 12:04:00 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_circle	*ft_circularnew(int	*content)
{
	t_circle	*new_node;

	new_node = NULL;
	new_node = (t_circle *) ft_calloc(1, sizeof(t_circle));
	if (new_node == NULL)
		return (NULL);
	new_node->number = *content;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}
