/*
** EPITECH PROJECT, 2018
** Library : my_strcmp
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

int my_strcmp(char const *str1, char const *str2)
{
	int i;

	for (i = 0; str1[i] != '\0' && str1[i] == str2[i]; i++);
	if (i == my_strlen(str1) && my_strlen(str1) == my_strlen(str2))
		return (1);
	return (0);
}
