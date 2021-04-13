#include <string.h>
#include <stdlib.h>

#include "dictionary.h"
#include "merge_sort.h"

void merge_sort(Words *anagrams, int left, int right){
  int middle;
  
  if(left < right){
    middle = ((left + right) / 2);
    merge_sort(anagrams, left, middle);
    merge_sort(anagrams, middle+1, right);
    merge(anagrams, left, middle, right);
  }
};

void merge(Words *anagrams, int initial_position, int middle, int final_position){
  int i, j, k; 
  
  int quantityLeft = middle - initial_position + 1;
  int quantityRight = final_position - middle; 

  Words *left = (Words*)malloc(sizeof(Words) * (quantityLeft + 1)); 
  Words *right = (Words*)malloc(sizeof(Words) * (quantityRight + 1));

  for(i = 0; i < quantityLeft; i++) {
    left[i].original_word = anagrams[initial_position + i].original_word;
    left[i].sorted_word = anagrams[initial_position + i].sorted_word;
  }
  for(j = 0; j < quantityRight; j++) {
    right[j].original_word = anagrams[middle + j + 1].original_word; 
    right[j].sorted_word = anagrams[middle + j + 1].sorted_word;
  }

  /* improvised sentinel */
  char sentinel[] = "zzzzzzzzzz";

  left[i].sorted_word = sentinel;
  right[j].sorted_word = sentinel;

  i = j = 0;
    
  for(k = initial_position; k <= final_position; k++){
    if(strcmp(left[i].sorted_word, right[j].sorted_word) < 0){
      anagrams[k] = left[i];
      i++;
    }else{
      anagrams[k] = right[j];
      j++;
    }
  }
  free(left);
  free(right);
};