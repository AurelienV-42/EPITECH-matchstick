/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

static void print_top_bot(int n_lines)
{
	int n_col = 0;

	for (n_col = (n_lines * 2) + 1; n_col != 0; n_col--)
		my_putchar('*');
	my_putchar('\n');
}

void print(struct_t *ptr)
{
	print_top_bot(ptr->n_lines);
	for (int i = 0; ptr->array[i]; i++) {
		my_putstr(ptr->array[i]);
		my_putchar('\n');
	}
	print_top_bot(ptr->n_lines);
}

int print_victory_defeat(int i)
{
	if (i % 2 == 0) {
		my_putstr("I lost... snif... but I'll get you next time!!\n");
		return (1);
	}
	my_putstr("You lost, too bad...\n");
	return (0);
}
