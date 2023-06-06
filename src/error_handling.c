/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:25:31 by makurz            #+#    #+#             */
/*   Updated: 2023/06/06 11:22:48 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	error_handling(t_oop **stack, int error_code)
{
	if (error_code == PARSE)
	{
		(*stack)->deconstructor(stack);
		free((*stack));
		*stack = NULL;
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

void	parse_error(t_oop **stack, char **nbs)
{
	ft_arrfree(nbs);
	error_handling(stack, PARSE);
}
