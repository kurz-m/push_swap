/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:28:45 by makurz            #+#    #+#             */
/*   Updated: 2023/06/05 23:02:16 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_container		container;
	// t_oop			*container.stack_a;
	// t_oop			*container.stack_b;

	if (argc < 2)
		return(write(2, "Error\n", 6), EXIT_FAILURE);
	container.stack_a = ft_calloc(1, sizeof(t_oop));
	if (NULL == container.stack_a)
		return(write(2, "Error\n", 6), EXIT_FAILURE);
	construct_stack(&container.stack_a);
	(void) argv;
	parse_input(&container.stack_a, argc - 1, argv);
	container.stack_b = ft_calloc(1, sizeof(t_oop));
	if (NULL == container.stack_b)
	{
		container.stack_a->deconstructor(&container.stack_a);
		return(write(2, "Error\n", 6), EXIT_FAILURE);
	}
	construct_stack(&container.stack_b);
	container.stack_a->deconstructor(&container.stack_a);
	container.stack_b->deconstructor(&container.stack_b);
	return (EXIT_SUCCESS);
}

// int	main(void)
// {
// 	t_container		container;
// 	t_circle		*temp;
// 
// 	container.stack_a = ft_calloc(1, sizeof(t_oop));
// 	if (NULL == container.stack_a)
// 		return(write(2, "Error\n", 6), EXIT_FAILURE);
// 	container.stack_b = ft_calloc(1, sizeof(t_oop));
// 	if (NULL == container.stack_b)
// 		return(free(container.stack_a), write(2, "Error\n", 6), EXIT_FAILURE);
// 	construct_stack(&container.stack_a);
// 	construct_stack(&container.stack_b);
// 	container.stack_a->append(container.stack_a, new_node(4));
// 	container.stack_a->append(container.stack_a, new_node(10));
// 	container.stack_a->append(container.stack_a, new_node(-3));
// 	container.stack_a->append(container.stack_a, new_node(2));
// 	container.stack_a->append(container.stack_a, new_node(15));
// 	container.stack_a->print(container.stack_a);
// 	ft_printf("test\n");
// 	temp = container.stack_a->top;
// 	container.stack_a->pop(container.stack_a);
// 	container.stack_b->prepend(container.stack_b, temp);
// 	container.stack_a->print(container.stack_a);
// 	container.stack_a->rotate(container.stack_a);
// 	ft_printf("stack_B: ");
// 	container.stack_b->print(container.stack_b);
// 	ft_printf("test\n");
// 	container.stack_a->print(container.stack_a);
// 	container.stack_a->deconstructor(&container.stack_a);
// 	container.stack_b->deconstructor(&container.stack_b);
// 	return (EXIT_SUCCESS);
// }
