#pragma once

/**
 * Header file for the dictionary abstract data type and its functions.
 * 
 * How this structure works?
 * Structure Dictionary:
 * [int size | Words anagrams[Number os words]]
 * Comes down to this:
 * Dictionary[
 *     size
 *     anagrams[
 *              [original word, sorted word],
 *              [original word, sorted word],
 *              [original word, sorted word],
 *              ... 
 *              [original word, sorted word]
 *     ]
 * ]
 * 
*/

//if you want to test with your own dictionary change the number of words in here.
#define NUMBER_OF_WORDS 261797

typedef struct words {
    char *original_word;
    char *sorted_word; 
} Words;

typedef struct dictionary {
    Words anagrams[NUMBER_OF_WORDS];
    int size;
} Dictionary;

typedef enum boolean {false, true} Boolean;

Dictionary *create_dictionary();
void destroy_dictionary(Dictionary *dictionary);
void insert_words(Dictionary *dictionary, char *word);
void print_dictionary(Dictionary *dictionary);
void sort_dictionary(Dictionary *dictionary);
void search_dictionary(Dictionary *dictionary);