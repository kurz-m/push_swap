/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:55:53 by work              #+#    #+#             */
/*   Updated: 2023/06/09 00:11:59 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "push_swap.h"

t_cmd	*new_cmd(char *cmd)
{
	t_cmd	*new_cmd;

	new_cmd = NULL;
	new_cmd = (t_cmd *) ft_calloc(1, sizeof(t_cmd));
	if (new_cmd == NULL)
		return (NULL);
	new_cmd->move = ft_strdup(cmd);
	ft_printf("%s\n", new_cmd->move);
	// ft_memcpy(new_cmd->move, cmd, ft_strlen(cmd));
	new_cmd->next = NULL;
	return (new_cmd);
}

static t_cmd	*last_cmd(t_cmd *cmd)
{
	if (cmd == NULL)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

void	append_cmd(t_cmd **cmd, t_cmd *new_cmd)
{
	t_cmd	*last;

	last = NULL;
	if (*cmd == NULL)
		*cmd = new_cmd;
	else
	{
		last = last_cmd(*cmd);
		last->next = new_cmd;
	}
}
