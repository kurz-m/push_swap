/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:11:45 by makurz            #+#    #+#             */
/*   Updated: 2023/06/13 14:47:54 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "push_swap.h"

#include "bonus.h"

static const char	*g_cmd_lookup[] = {
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
	"\n",
};

static void	get_eof_signal(ssize_t *byte, char *stash)
{
	if (*byte == 0)
	{
		ft_memcpy(stash, "\n", 1);
		*byte = 1;
	}
}

static int	get_input(t_box *box)
{
	char		stash[4];
	int			cmd;
	ssize_t		byte;

	while (1)
	{
		byte = read(STDIN_FILENO, stash, 4);
		if (byte == -1)
			error_handling(box, READ_ERROR);
		get_eof_signal(&byte, stash);
		cmd = 0;
		while (cmd < 12 && ft_strncmp(g_cmd_lookup[cmd], stash, byte))
			++cmd;
		if (cmd == NO_COMMAND)
			error_handling(box, WRONG_COMMAND);
		if (movements_bonus(box, cmd) == EOF)
			return (FINISH_COMMANDS);
	}
}

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
	get_input(&box);
	if (check_sorted(box.a) == TRUE && box.b->elements == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	box_cleanup(&box);
	return (EXIT_SUCCESS);
}
