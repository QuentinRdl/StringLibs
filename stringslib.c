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
    size_t count = 0;
    int condition = 0;
    while(*str)
        {
            const char *copyChars = chars;
            while(*copyChars)
                {
                    if(*copyChars == *str)
                    {
                        condition = 1;
                    }
                    copyChars++;
                }
            if(!condition)
            {
                return count;
            }
            condition = 0;
            count++;
            str++;
        }
    return count;
}
/*
 * Calculates the length of the initial segment of str which consists entirely of
 * bytes *not* in chars.
 */
size_t str_prefix_reject(const char *str, const char *chars) {
    size_t count = 0;
    int condition = 0;
    while(*str)
    {
        const char *copyChars = chars;
        while(*copyChars)
            {
                if(*copyChars == *str)
                {
                    condition = 1;
                }
                copyChars++;
            }
        if(condition)
        {
            return count;
        }
        condition = 0;
        count++;
        str++;
    }
    return count;
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

/*
 * Transform a string with a number into an integer.
 * The base argument contains the base of the representation, from 2 to 36.
 * For a base greater than 10, latin letters (uppercase or lowercase) are used.
 * Returns the number or 0 if the string does not start with a number.
 * If endptr is not NULL, the function stores the address of the first invalid character.
 */
int str_to_integer_ex(const char *str, const char **endptr, int base) {
    int value = 0;
    int valueOfChar = 0;
    int i = 0;
    // We iterate through our str
    while(*str)
    {
        // We convert the value of the char to an int.
        if(*str >= '0' && *str <= '9') 
        {
            valueOfChar = *str - '0';
        }
        else if(*str >= 'a' && *str <= 'z')
        {
            valueOfChar = *str - 'a' + 10;
        }
        else if(*str >= 'A' && *str <= 'Z')
        {
            valueOfChar = *str - 'A' + 10;
        }
        else
        {
            break;
        }
        if(valueOfChar >= base)
        {
            break;
        }
        value = value * base + valueOfChar;
        str++;
         
    }
    if(endptr != NULL)
    {
        *endptr = str + i; 

    }
    return value;
}

/*
 * Transform an integer into a string.
 * The destination buffer has a length of size bytes. If there
 * is not enough space in the buffer, the result is truncated.
 */
void str_from_integer(char *dest, size_t size, int n) {
    if (size == 0 || n < 0) 
	{
        dest[0] = '\0';
        return;
    }

    // We calculate the number of digits
    int numberOfDigits = 1;
    int nCopy = n;
    while(nCopy > 9)
	{
    	nCopy = nCopy / 10;
        numberOfDigits++;
    };

    // We ensure that there is enough space in the buffer
    while(size <= (size_t)numberOfDigits)
	{
        numberOfDigits = numberOfDigits - 1;
        n = n / 10;
    }
    dest[numberOfDigits] = '\0';
    // We convert the digits into characters in reverse order
    int i = numberOfDigits;
    while(i > 0)
	{
        i--;
        dest[i] = n % 10 + '0';
        n = n / 10;
    }
}

/*
 * Make a copy of a string.
 * The destination buffer has a length of size bytes. If there
 * is not enough space in the buffer, the result is truncated.
 */
void str_copy(char *dest, size_t size, const char *str) {
    for(size_t i = 0; i < size - 1 && *str != '\0'; i++)
        {
            *dest = *str;
            dest++;
            str++;
        }
    *dest = '\0';
}

/*
 * Duplicate a string.
 * Returns a copy of the argument, allocated with malloc or calloc.
 */
char *str_duplicate(const char *str) {
	size_t lenOfStr = str_length(str); // We find the length of the initial str
	char *str_copy = (char *)malloc((lenOfStr + 1) * sizeof(char));
    if(str_copy == NULL)
    {
        printf("Memory not available");
        return 0; 
    }
	if (str_copy == NULL)
	{
		return NULL;
	}
	char *temp = str_copy;
	while(*str != '\0')
	{
		*temp= *str;
		temp++;
		str++;
	}
	*temp = '\0';
    return str_copy;
}

/*
 * Concatenate a string to an existing string.
 * The destination buffer has a length of size bytes. If there
 * is not enough space in the buffer, the result is truncated.
 */
void str_concat_string(char *dest, size_t size, const char *str) {
	size_t count = 0;
	while(*dest)
	{
		dest++;
		count++;
	}
	while(count < size - 1 && *str != '\0')
	{
		*dest = *str;
		dest++;
		str++;
		count++;
	}
	*dest = '\0';

}

/*
 * Concatenate a character to an existing string.
 * The destination buffer has a length of size bytes. If there
 * is not enough space in the buffer, the result is truncated.
 */
void str_concat_char(char *dest, size_t size, char c) {
	size_t count = 0;
	while(*dest)
	{
		dest++;
		count++;
	}
	
	if(count < size - 1)
	{
		*dest = c;
		dest++;
		*dest = '\0';
	}
}

/*
 * Concatenate an integer to an existing string.
 * The destination buffer has a length of size bytes. If there
 * is not enough space in the buffer, the result is truncated.
 */
void str_concat_integer(char *dest, size_t size, int n) {
    if (dest != NULL)
    {
        int length = 1;
        int nCopy = n;
        // We determine the length of the string that will hold our digits 
        while(nCopy > 9) 
        {
            nCopy /= 10;
            length++;
        }
        char *digitsStored = malloc((length + 1) * sizeof(char));
        if(digitsStored == NULL)
        {
            printf("Memory not available");
            return;
        }
        str_from_integer(digitsStored, length + 1, n); // We convert our digits to a string
        str_concat_string(dest, size, digitsStored); // We concat our dest str to the digits str
        free(digitsStored);
    } 


}

/*
 * Concatenate an array of strings to an existing string.
 * A separator is added between the existing string and each string in the array.
 * The end of the array is identified by NULL.
 * The destination buffer has a length of size bytes. If there
 * is not enough space in the buffer, the result is truncated.
 */
void str_concat_array(char *dest, size_t size, const char *args[], char separator) {

    size_t len = 0;
    size_t count = 0;
    while(count < size && args[count] != NULL)
    {
        str_concat_char(dest, size, separator);
        str_concat_string(dest, size, args[count]);
        count++;
        len++;
    } 
}


/*
 * Join two strings in a new string with a separator.
 * Returns a new string allocated with malloc or calloc.
 */
char *str_join_string(const char *str1, const char *str2, char separator) {
    // We determine the length of final string + 2 for the separator and null terminator.
    char *strFinal = (char *)malloc((str_length(str1) + str_length(str2) + 2)* sizeof(char));
    if(strFinal == NULL)
    {
        printf("Memory not available");
        return 0;
    }
    char *tempPointer = strFinal;
    while(*str1)
    {
        *strFinal = *str1;
        str1++;
        strFinal++;
    }
    *strFinal = separator; // We add the separator.
    strFinal++;
    while(*str2)
    {
        *strFinal = *str2;
        str2++;
        strFinal++;
    }
    *strFinal = '\0'; // We add the null terminator.

    return tempPointer;
}

char *str_join_array(const char *args[], char separator) {

    // We will figure out how many strings, and chars are stored in the array.
    int numStrings = 0;
    int numChar = 0;
    while(args[numStrings] != NULL)
    {
        const char *currentString = args[numStrings];
        numChar = numChar + str_length(currentString);
        numStrings++;
    }
    char *result = (char *)malloc((numChar + 1) * sizeof(char)); // We create the string we will return.
    if(result == NULL)
    {
        printf("Memory not available");
        return 0;
    }
    char *resultStart = result;
    int numStrings2 = 0;
    while(args[numStrings2] != NULL)
    {
        const char *currentString2 = args[numStrings2];
        int index = 0;
        while(currentString2[index] != '\0')
        {
            *result = currentString2[index];
            index++;
            result++;
        }
        if (args[numStrings2 + 1] != NULL)
        {
            *result = separator;
            result++;
        }
        numStrings2++;
    }
    *result = '\0';
    return resultStart;
}