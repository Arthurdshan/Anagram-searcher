#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "dictionary.h"
#include "binary_search.h"

#define SEARCH_SUCESS        1
#define EXPORT_SUCESS        0  
#define SEARCH_FAILED       -1
#define ARCHIVE_ERROR       -2  

/**
 * A useful function in case the user inputs a word containing
 * uppercase letters. It prevents the program from bugging 
*/
char *to_lower_case(char *s) {
    for (int i = 0; s[i] != '\0'; i++)
        if(s[i] >= 'A' && s[i] <= 'Z') 
            s[i] = s[i] + 32;
    return s;
}

/* function to sort a single word, used before pushing into the dictionary */
char *sort_word(char *s) {
    int n = strlen(s);
    for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] > s[j]) {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
			}
		}
    }
    return s;
}
 
/* function to search in the sorted dictionary the anagrams */
int get_anagrams(Dictionary *dictionary, char *input, char *user_input){
    int anagram_position;
    anagram_position = binary_search(dictionary->anagrams, 0, dictionary->size - 1, input);
    
    /* no anagrams found */
    if (anagram_position == -1) {
        printf("There's no anagrams for the chosen word.\n");
        return SEARCH_FAILED;
    }

    /* variables to control the while loop */
    Boolean has_anagrams = true;
    int i = anagram_position;

    printf("user input: %s\n", user_input);
    printf("anagrams:\n");
    
    /**
     * extra code to get the words around the key returned from
     * the binary search function. 
     * it compares the size and the string to print the 
     * extra anagrams 
     */ 
    while(has_anagrams) {
        if(strcmp(dictionary->anagrams[i].sorted_word, input) == 0  && strlen(dictionary->anagrams[i].sorted_word) == strlen(input))
            printf("%s\n", dictionary->anagrams[i].original_word);
        else has_anagrams = false;
        i++;
    }

    i = anagram_position - 1;
    has_anagrams = true;

    while(has_anagrams) {
        if(strcmp(dictionary->anagrams[i].sorted_word, input) == 0 && strlen(dictionary->anagrams[i].sorted_word) == strlen(input))
            printf("%s\n", dictionary->anagrams[i].original_word);
        else has_anagrams = false;
        i--;
    }
    return SEARCH_SUCESS;
}

/* Function that controls the flux of the searching */
int search_for_anagrams(char* input, char* dictionary) { 

    Dictionary *new_dictionary = create_dictionary();
    char *word;
    input = to_lower_case(input);

    FILE* arq = fopen(dictionary, "r");
    if (arq == NULL) return ARCHIVE_ERROR;
   

    // read the whole file and push the words into the dictionary struct
    while((fscanf(arq, "%s", word)) != EOF) {
        word = to_lower_case(word);
        insert_words(new_dictionary, word);
    }
    
    fclose(arq); // not needed anymore. Closing file
    
    // auxiliar string to help sorting the dictionary
    char *sorted_input = (char*)malloc(strlen(input) + 1);
    strcpy(sorted_input, input);
    sorted_input = sort_word(sorted_input);
    sort_dictionary(new_dictionary);
    export_dictionary(new_dictionary);

    int output = get_anagrams(new_dictionary, sorted_input, input);
    
    free(sorted_input);
    destroy_dictionary(new_dictionary);
    
    return output;
}

/* Exports the new sorted dictionary to the txt.file */
int export_dictionary(Dictionary *dictionary) {
    FILE *arq = fopen("new_dictionary.txt", "w+");
    if (arq == NULL) return ARCHIVE_ERROR;
    for(int i = 0; i < dictionary->size; i++) {
        fprintf(arq, "[%s, ", dictionary->anagrams[i].original_word);
        fprintf(arq, "%s]\n", dictionary->anagrams[i].sorted_word);
    }
    fclose(arq); //closing archive
    return EXPORT_SUCESS;
}