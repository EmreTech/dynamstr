/*
dynamstr: Dynamic String library
Copyright (C) 2022 EmreTech

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <dynamstr.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

String* str_create()
{
    String *str = malloc(sizeof(String));
    str->str = malloc(sizeof(char));
}

void str_destroy(String *str)
{
    free(str->str);
    free(str);
}

void str_set(String *str, const char *add)
{
    if (strlen(str->str) != 0)
        return;

    for (int i = 0; i < strlen(add); i++)
    {
        str->str[strlen(str->str)] = add[i];
        str->str = realloc(str->str, strlen(str->str) * sizeof(char));
    }
}

char* str_get(String *str)
{
    return str->str;
}

const char* str_get_const(String *str)
{
    return str->str;
}

void str_add(String *str, const char *add)
{
    if (strlen(str->str) == 0)
        return;

    for (size_t i = 0; i < strlen(add); i++)
    {
        str->str[strlen(str->str)] = add[i];
        str->str = realloc(str->str, strlen(str->str) * sizeof(char));
    }
}

void str_remove(String *str, size_t len)
{
    if (strlen(str->str) == 0)
        return;

    len = strlen(str->str) - len;
    for (size_t i = strlen(str->str); i > len; i--)
    {
        str->str[strlen(str->str) - 1] = 0;
        str->str = realloc(str->str, strlen(str->str) * sizeof(char));
    }
}

size_t str_len(String *str)
{
    return strlen(str->str);
}

void str_cpy(String *src, String *dest, size_t size)
{
    if (size > strlen(src->str))
        return;

    for (size_t i = 0; i < size; i++)
    {
        dest->str[strlen(dest->str)] = src->str[i];
        dest->str = realloc(dest->str, strlen(dest->str) * sizeof(char));
    }
}

void str_move(String *src, String *dest, size_t size)
{
    str_cpy(src, dest, size);
    str_remove(src, size);
}

void str_cpy_full(String *src, String *dest)
{
    str_cpy(src, dest, str_len(src));
}

void str_move_full(String *src, String *dest)
{
    str_move(src, dest, str_len(src));
}

int str_cmp(String *one, String *two)
{
    return strcmp(one->str, two->str);
}