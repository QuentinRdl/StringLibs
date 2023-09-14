#include "stringslib.h"

#include "gtest/gtest.h"

/*
 * str_length
 */

TEST(LengthTest, Null) {
  EXPECT_TRUE(str_length(NULL) == 0);
}

TEST(LengthTest, Empty) {
  EXPECT_TRUE(str_length("") == 0);
}

TEST(LengthTest, OneCharacter) {
  EXPECT_TRUE(str_length("a") == 1);
}

TEST(LengthTest, LongString) {
  EXPECT_TRUE(str_length("azertyuiopqsdfghjklmwxcvbn ") == 27);
}

/*
 * str_compare
 */

TEST(CompareTest, Less) {
  EXPECT_TRUE(str_compare("", "a") < 0);
  EXPECT_TRUE(str_compare("a", "b") < 0);
  EXPECT_TRUE(str_compare("A", "a") < 0);
  EXPECT_TRUE(str_compare("0", "A") < 0);
  EXPECT_TRUE(str_compare("abcdef", "abcdeg") < 0);
  EXPECT_TRUE(str_compare("ab", "ba") < 0);
  EXPECT_TRUE(str_compare("abc", "abcdeg") < 0);
  EXPECT_TRUE(str_compare("abcdef", "abd") < 0);
}

TEST(CompareTest, Equal) {
  EXPECT_TRUE(str_compare("", "") == 0);
  EXPECT_TRUE(str_compare("a", "a") == 0);
  EXPECT_TRUE(str_compare("abcdef", "abcdef") == 0);
}

TEST(CompareTest, Greater) {
  EXPECT_TRUE(str_compare("a", "") > 0);
  EXPECT_TRUE(str_compare("b", "a") > 0);
  EXPECT_TRUE(str_compare("a", "A") > 0);
  EXPECT_TRUE(str_compare("A", "0") > 0);
  EXPECT_TRUE(str_compare("abcdeg", "abcdef") > 0);
  EXPECT_TRUE(str_compare("ba", "ab") > 0);
  EXPECT_TRUE(str_compare("abcdef", "abc") > 0);
  EXPECT_TRUE(str_compare("abd", "abcdef") > 0);
}

/*
 * str_search
 */

TEST(SearchTest, Present) {
  const char *haystack = "azertyuio";

  EXPECT_TRUE(str_search("az", haystack) == haystack);
  EXPECT_TRUE(str_search("t", haystack) == haystack + 4);
  EXPECT_TRUE(str_search("tyuio", haystack) == haystack + 4);
}

TEST(SearchTest, NotPresent) {
  const char *haystack = "azertyuio";

  EXPECT_TRUE(str_search("tyuiop", haystack) == NULL);
  EXPECT_TRUE(str_search("tyuip", haystack) == NULL);
  EXPECT_TRUE(str_search("azertyuiop^$", haystack) == NULL);
  EXPECT_TRUE(str_search("qsd", haystack) == NULL);
}

TEST(SearchTest, WorstCase) {
  const char *haystack = "aaaaaaaaaaaaaaaaab";
  EXPECT_TRUE(str_search("aaaaab", haystack) == haystack + 12);
}

TEST(SearchTest, Empty) {
  const char *haystack = "azertyuio";
  EXPECT_TRUE(str_search("", haystack) == haystack);
}

TEST(SearchTest, Multiple) {
  const char *haystack = "aaabaaa";
  EXPECT_TRUE(str_search("aaa", haystack) == haystack);
}

TEST(SearchTest, LongNeedle) {
  const char *haystack = "aa";
  EXPECT_TRUE(str_search("aaaaaaaaaaaaaaaaab", haystack) == NULL);
}

/*
 * str_search_first_char
 */

TEST(SearchFirstCharTest, Present) {
  const char *haystack = "azertayuiopa";
  EXPECT_TRUE(str_search_first_char('a', haystack) == haystack);
  EXPECT_TRUE(str_search_first_char('r', haystack) == haystack + 3);
}

TEST(SearchFirstCharTest, NotPresent) {
  const char *haystack = "azertayuiopa";
  EXPECT_TRUE(str_search_first_char('b', haystack) == NULL);
}

/*
 * str_search_last_char
 */

TEST(SearchLastCharTest, Present) {
  const char *haystack = "azertayuiopa";
  EXPECT_TRUE(str_search_last_char('a', haystack) == haystack + 11);
  EXPECT_TRUE(str_search_last_char('r', haystack) == haystack + 3);
}

TEST(SearchLastCharTest, NotPresent) {
  const char *haystack = "azertayuiopa";
  EXPECT_TRUE(str_search_last_char('b', haystack) == NULL);
}

/*
 * str_prefix_accept
 */

TEST(PrefixAcceptTest, Zero) {
  EXPECT_EQ(str_prefix_accept("azertyuiop", "qsd"), 0u);
  EXPECT_EQ(str_prefix_accept("azertyuiop", "zer"), 0u);
  EXPECT_EQ(str_prefix_accept("azertyuiop", "qsdfghjklmwxc"), 0u);
  EXPECT_EQ(str_prefix_accept("", "aze"), 0u);
}

TEST(PrefixAcceptTest, Some) {
  EXPECT_EQ(str_prefix_accept("azertyuiop", "reza"), 4u);
  EXPECT_EQ(str_prefix_accept("azertyuiop", "aaaa"), 1u);
  EXPECT_EQ(str_prefix_accept("azertyuiop", "azertyuiopqsd"), 10u);
}

/*
 * str_prefix_reject
 */

TEST(PrefixRejectTest, Zero) {
  EXPECT_EQ(str_prefix_reject("azertyuiop", "reza"), 0u);
  EXPECT_EQ(str_prefix_reject("azertyuiop", "aaaa"), 0u);
  EXPECT_EQ(str_prefix_reject("azertyuiop", "azertyuiopqsd"), 0u);
  EXPECT_EQ(str_prefix_reject("", "aze"), 0u);
}

TEST(PrefixRejectTest, Some) {
  EXPECT_EQ(str_prefix_reject("azertyuiop", "qsd"), 10u);
  EXPECT_EQ(str_prefix_reject("azertyuiop", "zer"), 1u);
  EXPECT_EQ(str_prefix_reject("azertyuiop", "qsdfghjklmwxc"), 10u);
}


/*
 * str_to_integer
 */

TEST(ToIntegerTest, Digit) {
  EXPECT_EQ(str_to_integer("0"), 0);
  EXPECT_EQ(str_to_integer("1"), 1);
  EXPECT_EQ(str_to_integer("2"), 2);
  EXPECT_EQ(str_to_integer("3"), 3);
  EXPECT_EQ(str_to_integer("4"), 4);
  EXPECT_EQ(str_to_integer("5"), 5);
  EXPECT_EQ(str_to_integer("6"), 6);
  EXPECT_EQ(str_to_integer("7"), 7);
  EXPECT_EQ(str_to_integer("8"), 8);
  EXPECT_EQ(str_to_integer("9"), 9);
}

TEST(ToIntegerTest, Large) {
  EXPECT_EQ(str_to_integer("10"), 10);
  EXPECT_EQ(str_to_integer("100"), 100);
  EXPECT_EQ(str_to_integer("0001"), 1);
}

TEST(ToIntegerTest, Garbage) {
  EXPECT_EQ(str_to_integer("a"), 0);
  EXPECT_EQ(str_to_integer("X"), 0);
  EXPECT_EQ(str_to_integer("?"), 0);
}

TEST(ToIntegerTest, Start) {
  EXPECT_EQ(str_to_integer("10a"), 10);
  EXPECT_EQ(str_to_integer("100X"), 100);
  EXPECT_EQ(str_to_integer("0001?"), 1);
}

/*
 * str_to_integer_ex
 */

TEST(ToIntegerExTest, DigitNum) {
  EXPECT_EQ(str_to_integer_ex("0", NULL, 36), 0);
  EXPECT_EQ(str_to_integer_ex("1", NULL, 36), 1);
  EXPECT_EQ(str_to_integer_ex("2", NULL, 36), 2);
  EXPECT_EQ(str_to_integer_ex("3", NULL, 36), 3);
  EXPECT_EQ(str_to_integer_ex("4", NULL, 36), 4);
  EXPECT_EQ(str_to_integer_ex("5", NULL, 36), 5);
  EXPECT_EQ(str_to_integer_ex("6", NULL, 36), 6);
  EXPECT_EQ(str_to_integer_ex("7", NULL, 36), 7);
  EXPECT_EQ(str_to_integer_ex("8", NULL, 36), 8);
  EXPECT_EQ(str_to_integer_ex("9", NULL, 36), 9);
}

TEST(ToIntegerExTest, DigitUppercase) {
  EXPECT_EQ(str_to_integer_ex("A", NULL, 36), 10);
  EXPECT_EQ(str_to_integer_ex("B", NULL, 36), 11);
  EXPECT_EQ(str_to_integer_ex("C", NULL, 36), 12);
  EXPECT_EQ(str_to_integer_ex("D", NULL, 36), 13);
  EXPECT_EQ(str_to_integer_ex("E", NULL, 36), 14);
  EXPECT_EQ(str_to_integer_ex("F", NULL, 36), 15);
  EXPECT_EQ(str_to_integer_ex("G", NULL, 36), 16);
  EXPECT_EQ(str_to_integer_ex("H", NULL, 36), 17);
  EXPECT_EQ(str_to_integer_ex("I", NULL, 36), 18);
  EXPECT_EQ(str_to_integer_ex("J", NULL, 36), 19);
  EXPECT_EQ(str_to_integer_ex("K", NULL, 36), 20);
  EXPECT_EQ(str_to_integer_ex("L", NULL, 36), 21);
  EXPECT_EQ(str_to_integer_ex("M", NULL, 36), 22);
  EXPECT_EQ(str_to_integer_ex("N", NULL, 36), 23);
  EXPECT_EQ(str_to_integer_ex("O", NULL, 36), 24);
  EXPECT_EQ(str_to_integer_ex("P", NULL, 36), 25);
  EXPECT_EQ(str_to_integer_ex("Q", NULL, 36), 26);
  EXPECT_EQ(str_to_integer_ex("R", NULL, 36), 27);
  EXPECT_EQ(str_to_integer_ex("S", NULL, 36), 28);
  EXPECT_EQ(str_to_integer_ex("T", NULL, 36), 29);
  EXPECT_EQ(str_to_integer_ex("U", NULL, 36), 30);
  EXPECT_EQ(str_to_integer_ex("V", NULL, 36), 31);
  EXPECT_EQ(str_to_integer_ex("W", NULL, 36), 32);
  EXPECT_EQ(str_to_integer_ex("X", NULL, 36), 33);
  EXPECT_EQ(str_to_integer_ex("Y", NULL, 36), 34);
  EXPECT_EQ(str_to_integer_ex("Z", NULL, 36), 35);
}

TEST(ToIntegerExTest, DigitLowercase) {
  EXPECT_EQ(str_to_integer_ex("a", NULL, 36), 10);
  EXPECT_EQ(str_to_integer_ex("b", NULL, 36), 11);
  EXPECT_EQ(str_to_integer_ex("c", NULL, 36), 12);
  EXPECT_EQ(str_to_integer_ex("d", NULL, 36), 13);
  EXPECT_EQ(str_to_integer_ex("e", NULL, 36), 14);
  EXPECT_EQ(str_to_integer_ex("f", NULL, 36), 15);
  EXPECT_EQ(str_to_integer_ex("g", NULL, 36), 16);
  EXPECT_EQ(str_to_integer_ex("h", NULL, 36), 17);
  EXPECT_EQ(str_to_integer_ex("i", NULL, 36), 18);
  EXPECT_EQ(str_to_integer_ex("j", NULL, 36), 19);
  EXPECT_EQ(str_to_integer_ex("k", NULL, 36), 20);
  EXPECT_EQ(str_to_integer_ex("l", NULL, 36), 21);
  EXPECT_EQ(str_to_integer_ex("m", NULL, 36), 22);
  EXPECT_EQ(str_to_integer_ex("n", NULL, 36), 23);
  EXPECT_EQ(str_to_integer_ex("o", NULL, 36), 24);
  EXPECT_EQ(str_to_integer_ex("p", NULL, 36), 25);
  EXPECT_EQ(str_to_integer_ex("q", NULL, 36), 26);
  EXPECT_EQ(str_to_integer_ex("r", NULL, 36), 27);
  EXPECT_EQ(str_to_integer_ex("s", NULL, 36), 28);
  EXPECT_EQ(str_to_integer_ex("t", NULL, 36), 29);
  EXPECT_EQ(str_to_integer_ex("u", NULL, 36), 30);
  EXPECT_EQ(str_to_integer_ex("v", NULL, 36), 31);
  EXPECT_EQ(str_to_integer_ex("w", NULL, 36), 32);
  EXPECT_EQ(str_to_integer_ex("x", NULL, 36), 33);
  EXPECT_EQ(str_to_integer_ex("y", NULL, 36), 34);
  EXPECT_EQ(str_to_integer_ex("z", NULL, 36), 35);
}

TEST(ToIntegerExTest, Binary) {
  const char *binary = "1010011010";
  EXPECT_EQ(str_to_integer_ex(binary, NULL, 2), 666);
}

TEST(ToIntegerExTest, BinaryWithEndPtr) {
  const char *binary = "1010011010";
  const char *endptr = NULL;
  EXPECT_EQ(str_to_integer_ex(binary, &endptr, 2), 666);
  EXPECT_EQ(endptr, binary + 10);
}

TEST(ToIntegerExTest, Hexadecimal) {
  const char *hexadecimal = "29A";
  EXPECT_EQ(str_to_integer_ex(hexadecimal, NULL, 16), 666);
}

TEST(ToIntegerExTest, HexadecimalWithEndPtr) {
  const char *hexadecimal = "29A";
  const char *endptr = NULL;
  EXPECT_EQ(str_to_integer_ex(hexadecimal, &endptr, 16), 666);
  EXPECT_EQ(endptr, hexadecimal + 3);
}

TEST(ToIntegerExTest, Garbage) {
  EXPECT_EQ(str_to_integer_ex("a", NULL, 10), 0);
  EXPECT_EQ(str_to_integer_ex("X", NULL, 10), 0);
  EXPECT_EQ(str_to_integer_ex("?", NULL, 10), 0);
  EXPECT_EQ(str_to_integer_ex("2", NULL, 2), 0);
}

TEST(ToIntegerExTest, GarbageWithEndPtr) {
  const char *garbage = "_45";
  const char *endptr = NULL;

  EXPECT_EQ(str_to_integer_ex(garbage, &endptr, 12), 0);
  EXPECT_EQ(endptr, garbage);
}

TEST(ToIntegerExTest, Start) {
  EXPECT_EQ(str_to_integer_ex("10a", NULL, 10), 10);
  EXPECT_EQ(str_to_integer_ex("100X", NULL, 10), 100);
  EXPECT_EQ(str_to_integer_ex("0001?", NULL, 10), 1);
}

TEST(ToIntegerExTest, StartWithEndPtr) {
  const char *start = "23_45";
  const char *endptr = NULL;

  EXPECT_EQ(str_to_integer_ex(start, &endptr, 10), 23);
  EXPECT_EQ(endptr, start + 2);
}

/*
 * str_from_integer
 */

TEST(FromIntegerTest, Zero) {
  char buf[20] = "XXXXXXXXXXXXXXXXXXX";
  str_from_integer(buf, 10, 0);
  EXPECT_EQ(buf[0], '0');
  EXPECT_EQ(buf[1], '\0');
  EXPECT_EQ(buf[2], 'X');
}

TEST(FromIntegerTest, Digit) {
  char buf[20] = "XXXXXXXXXXXXXXXXXXX";
  str_from_integer(buf, 10, 7);
  EXPECT_EQ(buf[0], '7');
  EXPECT_EQ(buf[1], '\0');
  EXPECT_EQ(buf[2], 'X');
}

TEST(FromIntegerTest, Simple) {
  char buf[20] = "XXXXXXXXXXXXXXXXXXX";
  str_from_integer(buf, 10, 10);
  EXPECT_EQ(buf[0], '1');
  EXPECT_EQ(buf[1], '0');
  EXPECT_EQ(buf[2], '\0');
  EXPECT_EQ(buf[3], 'X');
}

TEST(FromIntegerTest, Long) {
  char buf[20] = "XXXXXXXXXXXXXXXXXXX";
  str_from_integer(buf, 15, 1234567890);
  EXPECT_EQ(buf[0], '1');
  EXPECT_EQ(buf[1], '2');
  EXPECT_EQ(buf[2], '3');
  EXPECT_EQ(buf[3], '4');
  EXPECT_EQ(buf[4], '5');
  EXPECT_EQ(buf[5], '6');
  EXPECT_EQ(buf[6], '7');
  EXPECT_EQ(buf[7], '8');
  EXPECT_EQ(buf[8], '9');
  EXPECT_EQ(buf[9], '0');
  EXPECT_EQ(buf[10], '\0');
  EXPECT_EQ(buf[11], 'X');
}

TEST(FromIntegerTest, ExactLength) {
  char buf[20] = "XXXXXXXXXXXXXXXXXXX";
  str_from_integer(buf, 11, 1234567890);
  EXPECT_EQ(buf[0], '1');
  EXPECT_EQ(buf[1], '2');
  EXPECT_EQ(buf[2], '3');
  EXPECT_EQ(buf[3], '4');
  EXPECT_EQ(buf[4], '5');
  EXPECT_EQ(buf[5], '6');
  EXPECT_EQ(buf[6], '7');
  EXPECT_EQ(buf[7], '8');
  EXPECT_EQ(buf[8], '9');
  EXPECT_EQ(buf[9], '0');
  EXPECT_EQ(buf[10], '\0');
  EXPECT_EQ(buf[11], 'X');
}

TEST(FromIntegerTest, NotEnoughMemory) {
  char buf[20] = "XXXXXXXXXXXXXXXXXXX";
  str_from_integer(buf, 4, 1234567890);
  EXPECT_EQ(buf[0], '1');
  EXPECT_EQ(buf[1], '2');
  EXPECT_EQ(buf[2], '3');
  EXPECT_EQ(buf[3], '\0');
  EXPECT_EQ(buf[4], 'X');
}

TEST(FromIntegerTest, SingleCharBuffer) {
  char buf[20] = "XXXXXXXXXXXXXXXXXXX";
  str_from_integer(buf, 1, 42);
  EXPECT_EQ(buf[0], '\0');
  EXPECT_EQ(buf[1], 'X');
}

TEST(FromIntegerTest, ZeroAndSingleCharBuffer) {
  char buf[20] = "XXXXXXXXXXXXXXXXXXX";
  str_from_integer(buf, 1, 0);
  EXPECT_EQ(buf[0], '\0');
  EXPECT_EQ(buf[1], 'X');
}

/*
 * str_copy
 */

TEST(CopyTest, Simple) {
  char buf[20] = "XXXXXXXXXXXXXXXXXXX";
  str_copy(buf, 10, "ABC");
  EXPECT_EQ(buf[0], 'A');
  EXPECT_EQ(buf[1], 'B');
  EXPECT_EQ(buf[2], 'C');
  EXPECT_EQ(buf[3], '\0');
  EXPECT_EQ(buf[4], 'X');
}

TEST(CopyTest, ExactLength) {
  char buf[20] = "XXXXXXXXXXXXXXXXXXX";
  str_copy(buf, 4, "ABC");
  EXPECT_EQ(buf[0], 'A');
  EXPECT_EQ(buf[1], 'B');
  EXPECT_EQ(buf[2], 'C');
  EXPECT_EQ(buf[3], '\0');
  EXPECT_EQ(buf[4], 'X');
}

TEST(CopyTest, NotEnoughMemory) {
  char buf[20] = "XXXXXXXXXXXXXXXXXXX";
  str_copy(buf, 4, "ABCDEF");
  EXPECT_EQ(buf[0], 'A');
  EXPECT_EQ(buf[1], 'B');
  EXPECT_EQ(buf[2], 'C');
  EXPECT_EQ(buf[3], '\0');
  EXPECT_EQ(buf[4], 'X');
}

TEST(CopyTest, SingleCharBuffer) {
  char buf[20] = "XXXXXXXXXXXXXXXXXXX";
  str_copy(buf, 1, "ABCDEF");
  EXPECT_EQ(buf[0], '\0');
  EXPECT_EQ(buf[1], 'X');
}

/*
 * str_duplicate
 */

TEST(DuplicateTest, Simple) {
  const char *origin = "ABC";
  char *buf = str_duplicate(origin);
  ASSERT_TRUE(buf != NULL);
  EXPECT_NE(buf, origin);
  EXPECT_EQ(buf[0], 'A');
  EXPECT_EQ(buf[1], 'B');
  EXPECT_EQ(buf[2], 'C');
  EXPECT_EQ(buf[3], '\0');
  free(buf);
}

TEST(DuplicateTest, Empty) {
  const char *origin = "";
  char *buf = str_duplicate(origin);
  ASSERT_TRUE(buf != NULL);
  EXPECT_NE(buf, origin);
  EXPECT_EQ(buf[0], '\0');
  free(buf);
}

/*
 * str_concat_string
 */

TEST(ConcatStringTest, Simple) {
  char buf[20] = "XXX\0XXXXXXXXXXXXXXX";
  str_concat_string(buf, 10, "YYY");
  EXPECT_EQ(buf[0], 'X');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'X');
  EXPECT_EQ(buf[3], 'Y');
  EXPECT_EQ(buf[4], 'Y');
  EXPECT_EQ(buf[5], 'Y');
  EXPECT_EQ(buf[6], '\0');
  EXPECT_EQ(buf[7], 'X');
}

TEST(ConcatStringTest, NotEnoughMemory) {
  char buf[20] = "XXX\0XXXXXXXXXXXXXXX";
  str_concat_string(buf, 6, "YYY");
  EXPECT_EQ(buf[0], 'X');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'X');
  EXPECT_EQ(buf[3], 'Y');
  EXPECT_EQ(buf[4], 'Y');
  EXPECT_EQ(buf[5], '\0');
  EXPECT_EQ(buf[6], 'X');
}

TEST(ConcatStringTest, EmptyDest) {
  char buf[20] = "\0XXXXXXXXXXXXXXXXXX";
  str_concat_string(buf, 10, "YYY");
  EXPECT_EQ(buf[0], 'Y');
  EXPECT_EQ(buf[1], 'Y');
  EXPECT_EQ(buf[2], 'Y');
  EXPECT_EQ(buf[3], '\0');
  EXPECT_EQ(buf[4], 'X');
}

TEST(ConcatStringTest, FullDest) {
  char buf[20] = "XXX\0XXXXXXXXXXXXXXX";
  str_concat_string(buf, 4, "YYY");
  EXPECT_EQ(buf[0], 'X');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'X');
  EXPECT_EQ(buf[3], '\0');
  EXPECT_EQ(buf[4], 'X');
}

/*
 * str_concat_char
 */

TEST(ConcatCharTest, Simple) {
  char buf[20] = "XXX\0XXXXXXXXXXXXXXX";
  str_concat_char(buf, 10, 'Y');
  EXPECT_EQ(buf[0], 'X');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'X');
  EXPECT_EQ(buf[3], 'Y');
  EXPECT_EQ(buf[4], '\0');
}

TEST(ConcatCharTest, EmptyDest) {
  char buf[20] = "\0XXXXXXXXXXXXXXXXXX";
  str_concat_char(buf, 10, 'Y');
  EXPECT_EQ(buf[0], 'Y');
  EXPECT_EQ(buf[1], '\0');
}

TEST(ConcatCharTest, FullDest) {
  char buf[20] = "XXX\0XXXXXXXXXXXXXXX";
  str_concat_char(buf, 4, 'Y');
  EXPECT_EQ(buf[0], 'X');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'X');
  EXPECT_EQ(buf[3], '\0');
  EXPECT_EQ(buf[4], 'X');
}

/*
 * str_concat_integer
 */

TEST(ConcatIntegerTest, Zero) {
  char buf[20] = "XXX\0XXXXXXXXXXXXXXX";
  str_concat_integer(buf, 10, 0);
  EXPECT_EQ(buf[0], 'X');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'X');
  EXPECT_EQ(buf[3], '0');
  EXPECT_EQ(buf[4], '\0');
  EXPECT_EQ(buf[5], 'X');
}

TEST(ConcatIntegerTest, Digit) {
  char buf[20] = "XXX\0XXXXXXXXXXXXXXX";
  str_concat_integer(buf, 10, 1);
  EXPECT_EQ(buf[0], 'X');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'X');
  EXPECT_EQ(buf[3], '1');
  EXPECT_EQ(buf[4], '\0');
  EXPECT_EQ(buf[5], 'X');
}

TEST(ConcatIntegerTest, Simple) {
  char buf[20] = "XXX\0XXXXXXXXXXXXXXX";
  str_concat_integer(buf, 10, 10);
  EXPECT_EQ(buf[0], 'X');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'X');
  EXPECT_EQ(buf[3], '1');
  EXPECT_EQ(buf[4], '0');
  EXPECT_EQ(buf[5], '\0');
  EXPECT_EQ(buf[6], 'X');
}

TEST(ConcatIntegerTest, Long) {
  char buf[20] = "XXX\0XXXXXXXXXXXXXXX";
  str_concat_integer(buf, 17, 1234567890);
  EXPECT_EQ(buf[0], 'X');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'X');
  EXPECT_EQ(buf[3], '1');
  EXPECT_EQ(buf[4], '2');
  EXPECT_EQ(buf[5], '3');
  EXPECT_EQ(buf[6], '4');
  EXPECT_EQ(buf[7], '5');
  EXPECT_EQ(buf[8], '6');
  EXPECT_EQ(buf[9], '7');
  EXPECT_EQ(buf[10], '8');
  EXPECT_EQ(buf[11], '9');
  EXPECT_EQ(buf[12], '0');
  EXPECT_EQ(buf[13], '\0');
  EXPECT_EQ(buf[14], 'X');
}

/*
 * str_concat_array
 */

TEST(ConcatArrayTest, Zero) {
  char buf[20] = "XXX\0XXXXXXXXXXXXXXX";
  const char *args[] = { NULL };
  str_concat_array(buf, 18, args, 'S');
  EXPECT_EQ(buf[0], 'X');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'X');
  EXPECT_EQ(buf[3], '\0');
  EXPECT_EQ(buf[4], 'X');
}

TEST(ConcatArrayTest, Simple1) {
  char buf[20] = "XXX\0XXXXXXXXXXXXXXX";
  const char *args[] = { "YYY", NULL };
  str_concat_array(buf, 18, args, 'S');
  EXPECT_EQ(buf[0], 'X');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'X');
  EXPECT_EQ(buf[3], 'S');
  EXPECT_EQ(buf[4], 'Y');
  EXPECT_EQ(buf[5], 'Y');
  EXPECT_EQ(buf[6], 'Y');
  EXPECT_EQ(buf[7], '\0');
  EXPECT_EQ(buf[8], 'X');
}

TEST(ConcatArrayTest, Simple2) {
  char buf[20] = "XXX\0XXXXXXXXXXXXXXX";
  const char *args[] = { "YYY", "ZZZ", NULL };
  str_concat_array(buf, 18, args, 'S');
  EXPECT_EQ(buf[0], 'X');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'X');
  EXPECT_EQ(buf[3], 'S');
  EXPECT_EQ(buf[4], 'Y');
  EXPECT_EQ(buf[5], 'Y');
  EXPECT_EQ(buf[6], 'Y');
  EXPECT_EQ(buf[7], 'S');
  EXPECT_EQ(buf[8], 'Z');
  EXPECT_EQ(buf[9], 'Z');
  EXPECT_EQ(buf[10], 'Z');
  EXPECT_EQ(buf[11], '\0');
  EXPECT_EQ(buf[12], 'X');
}

TEST(ConcatArrayTest, Simple3) {
  char buf[20] = "XXX\0XXXXXXXXXXXXXXX";
  const char *args[] = { "YYY", "ZZZ", "AAA", NULL };
  str_concat_array(buf, 18, args, 'S');
  EXPECT_EQ(buf[0], 'X');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'X');
  EXPECT_EQ(buf[3], 'S');
  EXPECT_EQ(buf[4], 'Y');
  EXPECT_EQ(buf[5], 'Y');
  EXPECT_EQ(buf[6], 'Y');
  EXPECT_EQ(buf[7], 'S');
  EXPECT_EQ(buf[8], 'Z');
  EXPECT_EQ(buf[9], 'Z');
  EXPECT_EQ(buf[10], 'Z');
  EXPECT_EQ(buf[11], 'S');
  EXPECT_EQ(buf[12], 'A');
  EXPECT_EQ(buf[13], 'A');
  EXPECT_EQ(buf[14], 'A');
  EXPECT_EQ(buf[15], '\0');
  EXPECT_EQ(buf[16], 'X');
}

TEST(ConcatArrayTest, NotEnoughMemory) {
  char buf[20] = "XXX\0XXXXXXXXXXXXXXX";
  const char *args[] = { "YYY", "ZZZ", "AAA", NULL };
  str_concat_array(buf, 11, args, 'S');
  EXPECT_EQ(buf[0], 'X');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'X');
  EXPECT_EQ(buf[3], 'S');
  EXPECT_EQ(buf[4], 'Y');
  EXPECT_EQ(buf[5], 'Y');
  EXPECT_EQ(buf[6], 'Y');
  EXPECT_EQ(buf[7], 'S');
  EXPECT_EQ(buf[8], 'Z');
  EXPECT_EQ(buf[9], 'Z');
  EXPECT_EQ(buf[10], '\0');
  EXPECT_EQ(buf[11], 'X');
}


/*
 * str_join_string
 */

TEST(JoinStringTest, Simple) {
  char *buf = str_join_string("ABC", "XYZ", '|');
  ASSERT_TRUE(buf != NULL);
  EXPECT_EQ(buf[0], 'A');
  EXPECT_EQ(buf[1], 'B');
  EXPECT_EQ(buf[2], 'C');
  EXPECT_EQ(buf[3], '|');
  EXPECT_EQ(buf[4], 'X');
  EXPECT_EQ(buf[5], 'Y');
  EXPECT_EQ(buf[6], 'Z');
  EXPECT_EQ(buf[7], '\0');
  free(buf);
}

TEST(JoinStringTest, SecondEmpty) {
  char *buf = str_join_string("ABC", "", '|');
  ASSERT_TRUE(buf != NULL);
  EXPECT_EQ(buf[0], 'A');
  EXPECT_EQ(buf[1], 'B');
  EXPECT_EQ(buf[2], 'C');
  EXPECT_EQ(buf[3], '|');
  EXPECT_EQ(buf[4], '\0');
  free(buf);
}

TEST(JoinStringTest, FirstEmpty) {
  char *buf = str_join_string("", "XYZ", '|');
  ASSERT_TRUE(buf != NULL);
  EXPECT_EQ(buf[0], '|');
  EXPECT_EQ(buf[1], 'X');
  EXPECT_EQ(buf[2], 'Y');
  EXPECT_EQ(buf[3], 'Z');
  EXPECT_EQ(buf[4], '\0');
  free(buf);
}

TEST(JoinStringTest, BothEmpty) {
  char *buf = str_join_string("", "", '|');
  ASSERT_TRUE(buf != NULL);
  EXPECT_EQ(buf[0], '|');
  EXPECT_EQ(buf[1], '\0');
  free(buf);
}


/*
 * str_join_array
 */

TEST(JoinArrayTest, Zero) {
  const char *args[] = { NULL };
  char *buf = str_join_array(args, '|');
  ASSERT_TRUE(buf != NULL);
  EXPECT_EQ(buf[0], '\0');
  free(buf);
}

TEST(JoinArrayTest, One) {
  const char *args[] = { "ABC", NULL };
  char *buf = str_join_array(args, '|');
  ASSERT_TRUE(buf != NULL);
  EXPECT_EQ(buf[0], 'A');
  EXPECT_EQ(buf[1], 'B');
  EXPECT_EQ(buf[2], 'C');
  EXPECT_EQ(buf[3], '\0');
  free(buf);
}

TEST(JoinArrayTest, Simple) {
  const char *args[] = { "ABC", "XYZ", NULL };
  char *buf = str_join_array(args, '|');
  ASSERT_TRUE(buf != NULL);
  EXPECT_EQ(buf[0], 'A');
  EXPECT_EQ(buf[1], 'B');
  EXPECT_EQ(buf[2], 'C');
  EXPECT_EQ(buf[3], '|');
  EXPECT_EQ(buf[4], 'X');
  EXPECT_EQ(buf[5], 'Y');
  EXPECT_EQ(buf[6], 'Z');
  EXPECT_EQ(buf[7], '\0');
  free(buf);
}

TEST(JoinArrayTest, OneEmpty) {
  const char *args[] = { "ABC", "", "XYZ", NULL };
  char *buf = str_join_array(args, '|');
  ASSERT_TRUE(buf != NULL);
  EXPECT_EQ(buf[0], 'A');
  EXPECT_EQ(buf[1], 'B');
  EXPECT_EQ(buf[2], 'C');
  EXPECT_EQ(buf[3], '|');
  EXPECT_EQ(buf[4], '|');
  EXPECT_EQ(buf[5], 'X');
  EXPECT_EQ(buf[6], 'Y');
  EXPECT_EQ(buf[7], 'Z');
  EXPECT_EQ(buf[8], '\0');
  free(buf);
}

/*
 * main
 */

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
