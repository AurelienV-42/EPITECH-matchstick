/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"
#include <stdio.h>

static char *fill_mid_array(char *str, int n_lines)
{
	static int nb_stick = 1;
	static int n = 0;

	for (int i = 0; i < (n_lines * 2); i++)
		str[i] = ' ';
	str[0] = '*';
	str[n_lines * 2] = '*';
	str[n_lines * 2 + 1] = '\0';
	for (int i = 0; i != nb_stick; i++)
		str[(n_lines - n) + i] = '|';
	nb_stick += 2;
	n++;
	return (str);
}

int fill_array(struct_t *ptr)
{
	int i = 0;

	ptr->array = malloc(sizeof(char *) * (ptr->n_lines + 1));
	if (ptr->array == NULL)
		return (84);
	ptr->array[ptr->n_lines] = NULL;
	for (i = 0; i < ptr->n_lines; i++) {
		ptr->array[i] = malloc(sizeof(char) *
				((ptr->n_lines * 2) + 2));
		if (ptr->array[i] == NULL)
			return (84);
		ptr->array[i] = fill_mid_array(ptr->array[i], ptr->n_lines);
	}
	return (0);
}
