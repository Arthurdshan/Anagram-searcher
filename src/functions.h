#pragma once
#include "dictionary.h"

char *to_lower_case(char *s);
int search_for_anagrams(char *input, char *dictionary);
char *sort_word(char *s);
int get_anagrams(Dictionary *dictionary, char *input, char *user_input);
int export_dictionary(Dictionary *dictionary);