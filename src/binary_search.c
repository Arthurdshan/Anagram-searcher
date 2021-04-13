#include <string.h>

#include "binary_search.h"

int binary_search(Words *anagrams, int left, int right, char *input) { 
    int middle;
    if(left <= right) {
        middle = (left + right) / 2;
        if(strcmp(anagrams[middle].sorted_word, input) == 0) return middle;
        else{
            if(strcmp(input, anagrams[middle].sorted_word) < 0)
                return binary_search(anagrams, left, middle - 1, input); 
            else
                return binary_search(anagrams, middle + 1, right, input);
        }
    }
    return -1;
}
