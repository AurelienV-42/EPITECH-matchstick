/*
** EPITECH PROJECT, 2018
** Library : my_putstr_error
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

void my_putstr_error(char const *str)
{
	write(2, str, my_strlen(str));
}
