/*
** EPITECH PROJECT, 2017
** Library : my_strlen
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include <stddef.h>

int my_strlen(char const *str)
{
	int i = 0;

	while (str != NULL && str[i] != '\0')
		i++;
	return (i);
}
