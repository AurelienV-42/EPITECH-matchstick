/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

static int choose_line(struct_t *ptr)
{
	int rand = random() % (ptr->n_lines);

	for (int i = 1; ptr->array[rand][i] != '|'; i++) {
		if (ptr->array[rand][i] == '*')
			return (-1);
	}
	return (rand + 1);
}

static int number_matchs(struct_t *ptr, int rand)
{
	int nb = 0;

	for (int i = 0; ptr->array[rand][i] != '\0'; i++) {
		if (ptr->array[rand][i] == '|')
			nb++;
	}
	if (nb <= ptr->n_max && nb != 1)
		return (--nb);
	else
		return (1);
}

void ai(struct_t *ptr)
{
	int rand = choose_line(ptr);

	my_putstr("\nAI's turn...\n");
	while (rand == -1)
		rand = choose_line(ptr);
	ptr->l_change = rand;
	ptr->m_change = number_matchs(ptr, ptr->l_change - 1);
	my_putstr("AI removed ");
	my_putnbr(ptr->m_change);
	my_putstr(" match(es) from line ");
	my_putnbr(ptr->l_change);
	my_putchar('\n');
}
