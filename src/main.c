/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"
#include <stdio.h>

static int leaflet(int ac, char **av)
{
	if (ac == 2 && (my_strcmp(av[1], "-h") == 1)) {
		my_putstr("This is a matchstick game ! I hope you will win\n\n");
		my_putstr("USAGE : You should enter 2 arguments\n");
		my_putstr("        First argument is the number of columns ");
		my_putstr("it must be superior to 1 and inferior to 99\n");
		my_putstr("        Second argument is the ");
		my_putstr("maximum number of stick ");
		my_putstr("that you can pull and it should be superior to 0\n");
		my_putstr("        Arguments should also be integer !\n");
		return (1);
	}
	return (0);
}

static int condition_main(struct_t *ptr, char **av, int ac)
{
	if (ac != 3) {
		my_putstr_error("You must look the -h !\n");
		return (84);
	}
	ptr->n_lines = my_atoi(av[1]);
	ptr->n_max = my_atoi(av[2]);
	if (ptr->n_lines < 1 || ptr->n_lines > 99 || ptr->n_max <= 0) {
		my_putstr_error("You must look the -h !\n");
		return (84);
	}
	return (0);
}

int main(int ac, char **av)
{
        struct_t *ptr = malloc(sizeof(struct_t));
	int return_match = 0;

	if (ptr == NULL)
		return (84);
	if (leaflet(ac, av) == 1)
		return (0);
	if (condition_main(ptr, av, ac) == 84)
		return (84);
	return_match = matchstick(ptr);
	if (return_match == 3)
		return (1);
	if (return_match == 2)
		return (2);
	if (return_match == 84)
		return (84);
	if (return_match == 1)
		return (0);
	return (0);
}
