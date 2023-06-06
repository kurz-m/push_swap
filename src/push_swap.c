/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:28:45 by makurz            #+#    #+#             */
/*   Updated: 2023/06/06 19:14:37 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

void	container_cleanup(t_container *container)
{
	container->a->deconstructor(&container->a);
	free(container->a);
	container->a = NULL;
	container->b->deconstructor(&container->b);
	free(container->b);
	container->b = NULL;
}

int	main(int argc, char **argv)
{
	t_container		container;

	if (argc < 2)
		return (write(2, "Error\n", 6), EXIT_FAILURE);
	container.a = ft_calloc(1, sizeof(t_oop));
	container.b = ft_calloc(1, sizeof(t_oop));
	if (NULL == container.a || NULL == container.b)
		error_handling(&container, ALLOC_FAIL);
	construct_container(&container);
	parse_input(&container, argc - 1, argv);
	if (check_sorted(container.a) == FALSE)
		ft_printf("sorted\n");
	container_cleanup(&container);
	return (EXIT_SUCCESS);
}
// int	main(void)
// {
// 	t_container		container;
// 	t_circle		*temp;
// 
// 	container.a = ft_calloc(1, sizeof(t_oop));
// 	if (NULL == container.a)
// 		return(write(2, "Error\n", 6), EXIT_FAILURE);
// 	container.b = ft_calloc(1, sizeof(t_oop));
// 	if (NULL == container.b)
// 		return(free(container.a), write(2, "Error\n", 6), EXIT_FAILURE);
// 	construct_stack(&container.a);
// 	construct_stack(&container.b);
// 	container.a->append(container.a, new_node(4));
// 	container.a->append(container.a, new_node(10));
// 	container.a->append(container.a, new_node(-3));
// 	container.a->append(container.a, new_node(2));
// 	container.a->append(container.a, new_node(15));
// 	container.a->print(container.a);
// 	ft_printf("test\n");
// 	temp = container.a->top;
// 	container.a->pop(container.a);
// 	container.b->prepend(container.b, temp);
// 	container.a->print(container.a);
// 	container.a->rotate(container.a);
// 	ft_printf("stack_B: ");
// 	container.b->print(container.b);
// 	ft_printf("test\n");
// 	container.a->print(container.a);
// 	container.a->deconstructor(&container.a);
// 	container.b->deconstructor(&container.b);
// 	return (EXIT_SUCCESS);
// }
