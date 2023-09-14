#include "stringslib.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * Get the size of the string.
 */
size_t str_length(const char *str) {
  if(str == NULL)
  {
    return 0; // If the string is NULL.
  }
  size_t count = 0;
  // We increment our count until the char is '\0' meaning it's the last char of the String.
  while(str[count] != '\0')
  {
    count ++;
  }
  return count;
}
/*
 * Compare two strings lexicographically.
 * Returns:
 *   - < 0 if str1 is before str2
 *   - = 0 if str1 is the same as str2
 *   - > 0 if str1 is after str2
 */
int str_compare(const char *str1, const char *str2) {
  int count = 0;
  int valueStr1, valueStr2;
  // We iterate through the while statement until str1 and str2 are different or one str ends
  while(str1[count] == str2[count] && str1[count] != '\0' && str2[count] != '\0')
  {
    count++;
  }
  valueStr1 = str1[count];
  valueStr2 = str2[count];
  /*
  * If the ascii value of str1 is lower than str2, then str1 comes before str2 in the alphabet
  * and valueStr1 - valueStr2 will be less than 0.
  * If the ascii str2 if greater than str1 then it would be the opposite and valueStr1 - valueStr2
  * will be greater than 0.
  * And if they are the same, then valueStr1 - valueStr2 will be equal to 0.
  */
  return valueStr1 - valueStr2;
}

/*
 * Search for a character in the string.
 * Returns a pointer to the first character,
 * or NULL if the character is not in the string.
 */
const char *str_search(const char *needle, const char *haystack) {

  while (*haystack != '\0')
  {
    const char *needleCopy = needle;
    const char *haystackCopy = haystack;
    while(*needleCopy == *haystackCopy && *needleCopy != '\0')
    {
      needleCopy ++;
      haystackCopy ++;
    }
    if (*needleCopy == '\0')
    {
      return haystack;
    }

    haystack ++;
  }
  
  return NULL;
}

/*
 * Search for a character in the string.
 * Returns a pointer to the first character,
 * or NULL if the character is not in the string.
 */
const char *str_search_first_char(char needle, const char *haystack) {
  // We iterate through our haystack until we reach the end or until we find the needle
  while(*haystack != '\0')
  {
    if(*haystack == needle)
    {
      return haystack;
    }
    haystack++;
  }
  
  return NULL;
}
/*
 * Search for a character in the string.
 * Returns a pointer to the last character,
 * or NULL if the character is not in the string.
 */ 
const char *str_search_last_char(char needle, const char *haystack) {
  const char *lastPos = NULL;
  // We iterate through our haystack until we reach the end or until we find the needle
  while(*haystack != '\0')
  {
    if(*haystack == needle)
    {
      lastPos = haystack;
    }
    haystack++;
  }
  
  return lastPos;
}

/*
 * Calculates the length of the initial segment of str which consists entirely of
 * bytes in chars.
 */
size_t str_prefix_accept(const char *str, const char *chars) {
  return 0;
}

size_t str_prefix_reject(const char *str, const char *chars) {
  return 0;
}
/*
 * Transform a string with a base-10 number into an integer.
 * Returns the number or 0 if the string does not start with a number.
 */
int str_to_integer(const char *str) {
  int count = 0;
  while(*str)
  {
    if(*str >= '0' && *str <= '9')
    {
      count = count * 10 + (*str - '0');
    }
    str++;
  }
  return count;
}


int str_to_integer_ex(const char *str, const char **endptr, int base) {
  return 0;
}

void str_from_integer(char *dest, size_t size, int n) {
}

void str_copy(char *dest, size_t size, const char *str) {
}

char *str_duplicate(const char *str) {
  return NULL;
}

void str_concat_string(char *dest, size_t size, const char *str) {
}

void str_concat_char(char *dest, size_t size, char c) {
}

void str_concat_integer(char *dest, size_t size, int n) {
}

void str_concat_array(char *dest, size_t size, const char *args[], char separator) {
}

char *str_join_string(const char *str1, const char *str2, char separator) {
  return NULL;
}

char *str_join_array(const char *args[], char separator) {
  return NULL;
}