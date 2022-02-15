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

#ifndef DYNAM_STR_H
#define DYNAM_STR_H

#include <stddef.h>

/**
 * A string object. It's recommended not to initalize this struct yourself and
 * instead use str_create.
 * 
 * Attributes
 * str:
 *  The internal string. Recommend to grab this with str_get or str_get_const.
 */
typedef struct
{
    char *str;
} String;

/**
 * Creates & allocates memory for a new String object.
 */
String* str_create();

/**
 * Destroys the allocated memory for a pre-existing String object.
 * 
 * Parameters
 * str: 
 *  The string that should be destroyed.
 */
void str_destroy(String *str);

/**
 * Sets the value stored in a string. If the string already has
 * a stored value, then the function terminates immedialty. TODO: Fix spelling
 * 
 * Parameters
 * str: 
 *  The target string
 * add: 
 *  The value to store in the string.
 */
void str_set(String *str, const char *add);

/**
 * Returns the value of a string.
 */
char* str_get(String *str);

/**
 * Returns the value of a string except it's const.
 */
const char* str_get_const(String *str);

/**
 * Adds a value to the end of a string. Similar to str_set except
 * it terminates immedialty if the string is empty.
 * 
 * Parameters
 * str: 
 *  The target string
 * add: 
 *  The value to add to the string.
 */
void str_add(String *str, const char *add);

/**
 * Removes a set amount of characters from the end of the string.
 * 
 * Parameters
 * str: 
 *  The target string
 * len: 
 *  The amount of characters to remove from the string.
 */
void str_remove(String *str, size_t len);

/**
 * Returns the length of the string. This does not include null
 * (\0) characters.
 * 
 * Parameters
 * str: 
 *  The string to get the length from
 */
size_t str_len(String *str);

/**
 * Compares two strings and returns a value based on how similar 
 * they are.
 * 
 * Parameters
 * one: 
 *  The first string to compare
 * two: 
 *  The second string to compare
 */
int str_cmp(String *one, String *two);

/**
 * Copies a certain amount of characters from one string to
 * another.
 * 
 * Parameters
 * src: 
 *  The source string to copy from.
 * dest: 
 *  The destination string to copy to.
 * size: 
 *  The amount of characters to copy.
 */
void str_cpy(String *src, String *dest, size_t size);

/**
 * Moves a certain amount of characters from one string to
 * another.
 * 
 * Parameters
 * src: 
 *  The source string to move from.
 * dest: 
 *  The destination string to move to.
 * size: 
 *  The amount of characters to move.
 */
void str_move(String *src, String *dest, size_t size);

/**
 * Copies all of the characters from one string to another.
 * 
 * Parameters
 * src: 
 *  The source string to copy from.
 * dest: 
 *  The destination string to copy to.
 * size: 
 *  The amount of characters to copy.
 */
void str_cpy_full(String *src, String *dest);

/**
 * Moves all of the characters from one string to another.
 * 
 * Parameters
 * src: 
 *  The source string to move from.
 * dest: 
 *  The destination string to move to.
 * size: 
 *  The amount of characters to move.
 */
void str_move_full(String *src, String *dest);

#endif