/*
** EPITECH PROJECT, 2017
** Library : my_putstr
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "unistd.h"
#include "my.h"

void my_putstr(char const *str)
{
	write (1, str, my_strlen(str));
}
