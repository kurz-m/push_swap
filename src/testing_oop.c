#include "libft.h"
#include "push_swap.h"
#include "utils.h"
#include <stdio.h>

static void	append(t_oop *self, t_circle *new_node)
{
	t_circle	*tmp;

	if (self->top == NULL)
	{
		self->top = new_node;
		self->top->next = new_node;
		self->top->previous = new_node;
		return ;
	}
	tmp = self->top->previous;
	self->top->previous = new_node;
	tmp->next = new_node;
	new_node->previous = tmp;
	new_node->next = self->top;
}

static t_circle	*new_node(int data)
{
	t_circle	*new_node;

	new_node = NULL;
	new_node = (t_circle *) ft_calloc(1, sizeof(t_circle));
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

static void	prepend(t_oop *self, t_circle *new_node)
{
	t_circle	*tmp;

	if (self->top == NULL)
	{
		self->top = new_node;
		self->top->next = new_node;
		self->top->previous = new_node;
		return ;
	}
	tmp = self->top->previous;
	self->top->previous = new_node;
	tmp->next = new_node;
	new_node->previous = tmp;
	new_node->next = self->top;
	self->top = new_node;
}

static void	print_stack(t_oop *self)
{
	t_circle	*run;

	run = self->top;
	while (1)
	{
		printf("Number: %i\n", run->data);
		run = run->next;
		if (run == self->top)
			break ;
	}
}

static void	construct(t_oop *self)
{
	self->print = print_stack;
	self->append = append;
	self->prepend = prepend;
}

void	testing(t_oop **oop)
{
	(*oop)->constructor = construct;
	(*oop)->constructor(*oop);
	(*oop)->append(*oop, new_node(4));
	(*oop)->append(*oop, new_node(10));
	(*oop)->prepend(*oop, new_node(-3));
}

int	main(void)
{
	t_oop	*oop;

	oop = ft_calloc(1, sizeof(t_oop));
	testing(&oop);
	oop->print(oop);
	return (EXIT_SUCCESS);
}
