/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:28:45 by makurz            #+#    #+#             */
/*   Updated: 2023/06/10 00:37:15 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

// TODO:
// add sorting for bigger stack sizes
// restructure the functions and which file they are
// check header files again
int	main(int argc, char **argv)
{
	t_box		box;

	if (argc < 2)
		return (write(2, "Error\n", 6), EXIT_FAILURE);
	box.a = ft_calloc(1, sizeof(t_oop));
	box.b = ft_calloc(1, sizeof(t_oop));
	if (NULL == box.a || NULL == box.b)
		error_handling(&box, ALLOC_FAIL);
	construct_box(&box);
	parse_input(&box, argc - 1, argv);
	// box.a->print(box.a);
	if (check_sorted(box.a) == FALSE)
		sort_main(&box);
	print_cmd("");
	// box.a->print(box.a);
	box_cleanup(&box);
	return (EXIT_SUCCESS);
}
// #include <stdio.h>
// int	main(void)
// {
// 	t_box		box;
// 	t_circle	*temp;
// // 	t_circle	*temp1;
// 
// 	box.a = ft_calloc(1, sizeof(t_oop));
// 	if (NULL == box.a)
// 		return(write(2, "Error\n", 6), EXIT_FAILURE);
// 	box.b = ft_calloc(1, sizeof(t_oop));
// 	if (NULL == box.b)
// 		return(free(box.a), write(2, "Error\n", 6), EXIT_FAILURE);
// 	construct_box(&box);
// 	box.a->append(box.a, new_node(4));
// 	box.a->append(box.a, new_node(10));
// 	box.a->append(box.a, new_node(-3));
// 	box.a->append(box.a, new_node(2));
// 	box.a->append(box.a, new_node(15));
// 	box.a->print(box.a);
// 	temp = box.a->pop(box.a);
// 	// box.a->swap(box.a);
// 	// box.a->revrotate(box.a);
// 	ft_printf("pop:\n");
// 	box.a->print(box.a);
// 	ft_printf("prepend\n");
// 	box.a->append(box.a, temp);
// 	// temp = box.a->top;
// 	// box.a->pop(box.a);
// 	// box.a->append(box.a, temp);
// 	box.a->print(box.a);
// 	box.a->swap(box.a);
// 	ft_printf("swap: \n");
// 	// box.b->print(box.b);
// 	// ft_printf("test\n");
// 	box.a->print(box.a);
// 	box.a->deconstructor(&box.a);
// 	box.b->deconstructor(&box.b);
// 	print_cmd("sb\n");
// 	print_cmd("sa\n");
// 	print_cmd("ra\n");
// 	print_cmd("");
// 	return (EXIT_SUCCESS);
// }
