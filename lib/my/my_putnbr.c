/*
** EPITECH PROJECT, 2017
** Library : my_putnbr
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

void my_putnbr(int nb)
{
	int start;
	int end;

	if (nb < 0) {
		my_putchar('-');
		my_putnbr(-nb);
	} else {
		end = nb % 10;
		start = nb / 10;
		if (start != 0)
			my_putnbr(start);
		my_putchar(end + '0');
	}
}
