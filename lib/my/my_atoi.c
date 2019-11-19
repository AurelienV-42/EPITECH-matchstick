/*
** EPITECH PROJECT, 2018
** Library : my_atoi
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

int my_atoi(char *str)
{
	int i = 0;
	int nb = 0;

	while (str && str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb);
}
