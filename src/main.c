#include <stdio.h>
#include "functions.h"

int main(int argc, char **argv) {
    
    char *input = argv[1];
    char *dictionary = argv[2];

    int output = search_for_anagrams(input, dictionary);
    printf("program exited with status %d\n", output);

    return 0;
}