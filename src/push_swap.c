/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:28:45 by makurz            #+#    #+#             */
/*   Updated: 2023/06/03 21:33:07 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	// t_container		*stack;
	t_oop			stack;

	stack.append = append;
	(void) argv;

	if (argc < 2)
		return (1);
	// stack->stack_a = parse_input(argc, argv);
	return (EXIT_SUCCESS);
}
