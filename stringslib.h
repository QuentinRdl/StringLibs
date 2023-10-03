#ifndef STRINGSLIB_H
#define STRINGSLIB_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Get the size of the string.
 */
size_t str_length(const char *str);

/*
 * Compare two strings lexicographically.
 * Returns:
 *   - < 0 if str1 is before str2
 *   - = 0 if str1 is the same as str2
 *   - > 0 if str1 is after str2
 */
int str_compare(const char *str1, const char *str2);

/*
 * Search for the needle in the haystack.
 * Returns a pointer to the beginning of haystack in needle,
 * or NULL if needle is not in haystack.
 */
const char *str_search(const char *needle, const char *haystack);

/*
 * Search for a character in the string.
 * Returns a pointer to the first character,
 * or NULL if the character is not in the string.
 */
const char *str_search_first_char(char needle, const char *haystack);

/*
 * Search for a character in the string.
 * Returns a pointer to the last character,
 * or NULL if the character is not in the string.
 */
const char *str_search_last_char(char needle, const char *haystack);

/*
 * Calculates the length of the initial segment of str which consists entirely of
 * bytes in chars.
 */
size_t str_prefix_accept(const char *str, const char *chars);

/*
 * Calculates the length of the initial segment of str which consists entirely of
 * bytes *not* in chars.
 */
size_t str_prefix_reject(const char *str, const char *chars);

/*
 * Transform a string with a base-10 number into an integer.
 * Returns the number or 0 if the string does not start with a number.
 */
int str_to_integer(const char *str);

/*
 * Transform a string with a number into an integer.
 * The base argument contains the base of the representation, from 2 to 36.
 * For a base greater than 10, latin letters (uppercase or lowercase) are used.
 * Returns the number or 0 if the string does not start with a number.
 * If endptr is not NULL, the function stores the address of the first invalid character.
 */
int str_to_integer_ex(const char *str, const char **endptr, int base);

/*
 * Transform an integer into a string.
 * The destination buffer has a length of size bytes. If there
 * is not enough space in the buffer, the result is truncated.
 */
void str_from_integer(char *dest, size_t size, int n);

/*
 * Make a copy of a string.
 * The destination buffer has a length of size bytes. If there
 * is not enough space in the buffer, the result is truncated.
 */
void str_copy(char *dest, size_t size, const char *str);

/*
 * Duplicate a string.
 * Returns a copy of the argument, allocated with malloc or calloc.
 */
char *str_duplicate(const char *str);

/*
 * Concatenate a string to an existing string.
 * The destination buffer has a length of size bytes. If there
 * is not enough space in the buffer, the result is truncated.
 */
void str_concat_string(char *dest, size_t size, const char *str);

/*
 * Concatenate a character to an existing string.
 * The destination buffer has a length of size bytes. If there
 * is not enough space in the buffer, the result is truncated.
 */
void str_concat_char(char *dest, size_t size, char c);

/*
 * Concatenate an integer to an existing string.
 * The destination buffer has a length of size bytes. If there
 * is not enough space in the buffer, the result is truncated.
 */
void str_concat_integer(char *dest, size_t size, int n);

/*
 * Concatenate an array of strings to an existing string.
 * A separator is added between the existing string and each string in the array.
 * The end of the array is identified by NULL.
 * The destination buffer has a length of size bytes. If there
 * is not enough space in the buffer, the result is truncated.
 */
void str_concat_array(char *dest, size_t size, const char *args[], char separator);

/*
 * Join two strings in a new string with a separator.
 * Returns a new string allocated with malloc or calloc.
 */
char *str_join_string(const char *str1, const char *str2, char separator);
char *str_join_array(const char *args[], char separator);

#ifdef __cplusplus
}
#endif

#endif // STRINGSLIB_H
