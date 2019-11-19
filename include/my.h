/*
** EPITECH PROJECT, 2018
** Library my.h
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "struct.h"

int matchstick(struct_t *ptr);
void print(struct_t *ptr);
int fill_array(struct_t *ptr);
int fill_c_line_matches(struct_t *ptr);
int condition_c_line(char *c_line, struct_t *ptr);
int condition_c_matches(char *c_matches, struct_t *ptr);
char *fill_c_line(struct_t *ptr);
void ai(struct_t *ptr);
int print_victory_defeat(int i);

/* Library */

void my_putchar(char c);
void my_putstr(char const *str);
void my_putstr_error(char const *str);
int my_strlen(char const *str);
int my_atoi(char *str);
int my_strcmp(char const *str1, char const *str2);

#endif
