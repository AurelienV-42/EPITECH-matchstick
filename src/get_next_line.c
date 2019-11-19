/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "get_next_line.h"

static char *my_strcat_realloc(char *str, char *buffer)
{
	char *result = NULL;
	int nb = 0;
	int i = 0;
	int n = 0;

	for (nb = 0; str && str[nb]; nb++);
	for (i = 0; buffer[i] && buffer; i++);
	result = malloc(sizeof(char) * nb + i + 1);
	if (result == NULL)
		return (NULL);
	for (n = 0; str && str[n]; n++)
		result[n] = str[n];
	for (int len_buffer = 0; buffer != NULL && buffer[len_buffer] != '\0'
		&& buffer[len_buffer] != '\n'; len_buffer++)
		result[n++] = buffer[len_buffer];
	result[n] = '\0';
	return (result);
}

char *cut_before_end(char *str)
{
	char *str_value = NULL;
	int i = 0;

	for (i = 0; str != NULL && str[i] != '\0'
		&& str[i] != '\n'; i++);
	str_value = malloc(sizeof(char) * i + 1);
	if (str_value == NULL)
		return (NULL);
	for (int j = 0; j < i + 1; j++)
		str_value[j] = '\0';
	for (int n = 0; str != NULL && str[n] != '\0'
		&& str[n] != '\n'; n++)
		str_value[n] = str[n];
	free(str);
	return (str_value);
}

char *cut_buffer(char *buffer)
{
	char *buffer_value = NULL;
	int i = 0;
	int number = 0;

	for (i = 0; buffer != NULL && buffer[i] != '\0'
		&& buffer[i] != '\n'; i++);
	buffer_value = malloc(sizeof(char) * READ_SIZE + 1);
	if (buffer_value == NULL)
		return (NULL);
	for (int i = 0; i < READ_SIZE + 1; i++)
		buffer_value[i] = '\0';
	for (int n = i + 1; buffer[n] != '\0'; n++)
		buffer_value[number++] = buffer[n];
	free(buffer);
	return (buffer_value);
}

int init(int fd, char **buffer)
{
	if ((*buffer) == NULL) {
		(*buffer) = malloc(sizeof(char) * READ_SIZE + 1);
		if ((*buffer) == NULL)
			return (84);
		for (int i = 0; i < READ_SIZE + 1; i++)
			(*buffer)[i] = '\0';
	}
	if (fd == -1)
		return (84);
	return (0);
}

char *get_next_line(int fd)
{
	char *str = NULL;
	static char *buffer = NULL;
	int len = 1;

	if (init(fd, &buffer) == 84 || buffer == NULL)
		return (NULL);
	for (int i = 0; len != 0 && buffer[i] != '\n'; i++) {
		if (i - 1 == READ_SIZE) {
			str = my_strcat_realloc(str, buffer);
			len = read(fd, buffer, READ_SIZE);
			buffer[len] = '\0';
			i = - 1;
		}
	}
	str = my_strcat_realloc(str, buffer);
	str = cut_before_end(str);
	buffer = cut_buffer(buffer);
	if (len == 0 || str == NULL)
		return (NULL);
	return (str);
}
