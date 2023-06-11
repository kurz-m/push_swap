/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:11:45 by makurz            #+#    #+#             */
/*   Updated: 2023/06/12 01:18:25 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "push_swap.h"

static const char	*g_cmd_lt[] = {
	"sa\n",
	"sb\n",
	"ss\n",
	"ra\n",
	"rb\n",
	"rr\n",
	"rra\n",
	"rrb\n",
	"rrr\n",
	"pa\n",
	"pb\n",
	"\n"
};

int	main(int argc, char **argv)
{
	t_box		box;

	if (argc < 2)
		return (EXIT_FAILURE);
	box.a = ft_calloc(1, sizeof(t_oop));
	box.b = ft_calloc(1, sizeof(t_oop));
	if (NULL == box.a || NULL == box.b)
		error_handling(&box, ALLOC_FAIL);
	construct_box(&box);
	parse_input(&box, argc - 1, argv);
	if (check_sorted(box.a) == TRUE)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	print_cmd("");
	box_cleanup(&box);
	return (EXIT_SUCCESS);
}
