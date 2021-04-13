#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"
#include "functions.h"
#include "merge_sort.h"

Dictionary *create_dictionary() {
  Dictionary *new = (Dictionary*)malloc(sizeof(Dictionary));
  new->size = 0;
  return new;
}

void destroy_dictionary(Dictionary *dictionary) {
  for(int i = 0; i < dictionary->size; i++) {
    free(dictionary->anagrams[i].original_word);
    free(dictionary->anagrams[i].sorted_word);
  }
  free(dictionary);
}

void insert_words(Dictionary *dictionary, char *new_word) {
  char *first = (char*)malloc(strlen(new_word) + 1);
  char *second = (char*)malloc(strlen(new_word) + 1);

  strncpy(first, new_word, strlen(new_word) + 1);
  strncpy(second, new_word, strlen(new_word) + 1);

  second = sort_word(second);
  
  dictionary->anagrams[dictionary->size].original_word = first;
  dictionary->anagrams[dictionary->size].sorted_word = second;
  dictionary->size++;
}

void print_dictionary(Dictionary *dictionary) {
  printf("[\n");
  for(int i = 0; i < NUMBER_OF_WORDS; i++) {
    printf("(%s, ", dictionary->anagrams[i].original_word);
    printf("%s)\n", dictionary->anagrams[i].sorted_word);
  }
  printf("]\n");
}

void sort_dictionary(Dictionary *dictionary){
  merge_sort(dictionary->anagrams, 0, dictionary->size - 1);
}
