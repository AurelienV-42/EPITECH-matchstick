/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

int condition_c_line(char *c_line, struct_t *ptr)
{
	if (my_atoi(c_line) < 0) {
		my_putstr("Error: invalid input ");
		my_putstr("(positive number expected)\n");
		return (1);
	}
	if (my_atoi(c_line) > ptr->n_lines || my_atoi(c_line) == 0) {
		my_putstr("Error: this line is out of range\n");
		return (1);
	}
	return (0);
}

static int condition_more_matches(struct_t *ptr)
{
	char *str = NULL;

	str = fill_c_line(ptr);
	if (str == NULL)
		return (84);
	ptr->l_change = my_atoi(str);
	free(str);
	return (1);
}

static int count_sticks(struct_t *ptr, char *c_matches)
{
	int nb = 0;

	for (int i = 0; ptr->array[ptr->l_change - 1][i] != '\0'; i++)
		if (ptr->array[ptr->l_change - 1][i] == '|')
			nb++;
	if (my_atoi(c_matches) > nb) {
		my_putstr("Error: not enough matches on this line\n");
		if (condition_more_matches(ptr) == 84)
			return (84);
		return (1);
	}
	return (0);
}

static int ret_condition(char *c_matches, struct_t *ptr)
{
	int ret = 0;

	if (my_atoi(c_matches) < 0) {
		my_putstr("Error: invalid input (positive number expected)\n");
		ret = condition_more_matches(ptr);
		if (ret == 1)
			return (1);
		if (ret == 84)
			return (84);
	}
	if (my_atoi(c_matches) > ptr->n_max) {
		my_putstr("Error: you cannot remove more than ");
		my_putnbr(ptr->n_max);
		my_putstr(" matches per turn\n");
		ret = condition_more_matches(ptr);
		if (ret == 1)
			return (1);
		if (ret == 84)
			return (84);
	}
	return (0);
}

int condition_c_matches(char *c_matches, struct_t *ptr)
{
	int ret = 0;

	ret = ret_condition(c_matches, ptr);
	if (my_atoi(c_matches) == 0) {
		my_putstr("Error: you have to remove at least one match\n");
		ret = condition_more_matches(ptr);
		return (1);
	}
	if (ret == 1)
		return (1);
	if (ret == 84)
		return (84);
	if (count_sticks(ptr, c_matches) == 1)
		return (1);
	return (0);
}
