/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:28:45 by makurz            #+#    #+#             */
/*   Updated: 2023/06/04 16:21:39 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

// int	main(int argc, char **argv)
int	main(void)
{
	t_oop			*stack_a;
	t_oop			*stack_b;
	t_circle		*temp;

	stack_a = ft_calloc(1, sizeof(t_oop));
	if (NULL == stack_a)
		return(write(2, "Error\n", 6), EXIT_FAILURE);
	stack_b = ft_calloc(1, sizeof(t_oop));
	if (NULL == stack_b)
		return(free(stack_a), write(2, "Error\n", 6), EXIT_FAILURE);
	construct_stacks(&stack_a, &stack_b);
	stack_a->append(stack_a, new_node(4));
	stack_a->append(stack_a, new_node(10));
	stack_a->append(stack_a, new_node(-3));
	stack_a->append(stack_a, new_node(2));
	stack_a->append(stack_a, new_node(15));
	stack_a->print(stack_a);
	ft_printf("test\n");
	temp = stack_a->top;
	stack_a->pop(stack_a);
	stack_b->prepend(stack_b, temp);
	stack_a->print(stack_a);
	stack_a->rotate(stack_a);
	ft_printf("stack_B: ");
	stack_b->print(stack_b);
	ft_printf("test\n");
	stack_a->print(stack_a);
	free(stack_a);
	free(stack_b);
	return (EXIT_SUCCESS);
}
