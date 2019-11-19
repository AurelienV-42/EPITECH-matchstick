/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

char *fill_c_line(struct_t *ptr)
{
	char *c_line = NULL;

	my_putstr("Line: ");
	c_line = get_next_line(0);
	if (c_line == NULL) {
		return (NULL);
	}
	while (condition_c_line(c_line, ptr) == 1) {
		free(c_line);
		my_putstr("Line: ");
		c_line = get_next_line(0);
		if (c_line == NULL) {
			return (NULL);
		}
	}
	return (c_line);
}

static int condition_loop(struct_t *ptr, char *c_matches, int ret)
{
	if (c_matches == NULL) {
		return (84);
	}
	ret = condition_c_matches(c_matches, ptr);
	if (ret == 84) {
		return (84);
	}
	return (ret);
}

static char *fill_c_matches(struct_t *ptr)
{
	char *c_matches = NULL;
	int ret = 0;

	my_putstr("Matches: ");
	c_matches = get_next_line(0);
	ret = condition_loop(ptr, c_matches, ret);
	if (ret == 84)
		return (NULL);
	while (ret == 1) {
		free(c_matches);
		my_putstr("Matches: ");
		c_matches = get_next_line(0);
		ret = condition_loop(ptr, c_matches, ret);
		if (ret == 84)
			return (NULL);
	}
	return (c_matches);
}

static void disp(struct_t *ptr)
{
	my_putstr("Player removed ");
	my_putnbr(ptr->m_change);
	my_putstr(" match(es) from line ");
	my_putnbr(ptr->l_change);
	my_putchar('\n');
}

int fill_c_line_matches(struct_t *ptr)
{
	char *c_line = NULL;
	char *c_matches = NULL;

	my_putstr("\nYour turn:\n");
	c_line = fill_c_line(ptr);
	if (c_line == NULL)
		return (1);
	ptr->l_change = my_atoi(c_line);
	c_matches = fill_c_matches(ptr);
	if (c_matches == NULL)
		return (1);
	ptr->m_change = my_atoi(c_matches);
	disp(ptr);
	free(c_matches);
	free(c_line);
	return (0);
}
