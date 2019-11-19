/*
** EPITECH PROJECT, 2017
** Library : my_putchar
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}
