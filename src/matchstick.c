/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"
#include <stdio.h>

static int array_is_finished(char **array)
{
	for (int i = 0; array[i] != NULL; i++)
		for (int nb = 0; array[i][nb] != '\0'; nb++)
			if (array[i][nb] == '|')
				return (0);
	return (1);
}

static void change_array(struct_t *ptr)
{
	int nb = 0;

	for (nb = 0; ptr->array[ptr->l_change - 1][nb] != '|'; nb++);
	for (nb = nb; ptr->array[ptr->l_change - 1][nb] == '|'; nb++);
	nb--;
	while (ptr->m_change != 0) {
		ptr->array[ptr->l_change - 1][nb] = ' ';
		ptr->m_change--;
		nb--;
	}
}

int the_game(struct_t *ptr)
{
	int i = 0;

	while (array_is_finished(ptr->array) != 1) {
		if (i % 2 == 0) {
			if (fill_c_line_matches(ptr) == 1)
				return (1);
		} else
			ai(ptr);
		change_array(ptr);
		print(ptr);
		i++;
	}
	if (print_victory_defeat(i) == 1)
		return (3);
	return (2);
}

int matchstick(struct_t *ptr)
{
	int ret_game = 0;

	if (fill_array(ptr) == 84)
		return (84);
	print(ptr);
	ret_game = the_game(ptr);
	if (ret_game == 1)
		return (1);
	if (ret_game == 2)
		return (2);
	if (ret_game == 3)
		return (3);
	for (int i = 0; ptr->array[i]; i++) {
		free(ptr->array[i]);
	}
	free(ptr->array);
	return (0);
}
