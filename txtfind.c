//
// Created by sagit on 1/7/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 256
#define WORD 30

int containsString(char *line, char *substring){
    int line_length = strlen(line);
    int substring_length = strlen(substring);

    for (int i = 0; i < line_length; i++) {
        int match = 1;
        for (int j = 0; j < substring_length; j++) {
            if (line[i + j] != substring[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            return 1;
        }
    }
 return 0;
}




int main(){
    FILE *pfile;
    char *line = NULL;
    size_t length = 0;


    //open txt file for reading
    pfile = fopen("inputs/find_inputa.txt", "r");
    if(pfile == NULL)
        exit(EXIT_FAILURE);

    if(getline(&line, &length, pfile) == -1){
        printf("faild to read");
        return -1;
    }

    char* temp, *word_to_find, *type;
    //save and allocate memory for substring to look for
    temp = strtok(line, " ");
    word_to_find = (char*) malloc(sizeof(temp));
    strcpy(word_to_find, temp);

    //save and allocate memory for function type
    temp = strtok(NULL, "\n");
    type = (char*) malloc(sizeof(temp));
    strcpy(type, temp);

    //function a: print all lines contains specific substring
    if(strcmp(type, "a") == 0){
        if(getline(&line, &length, pfile) == -1){
            printf("faild to read");
            return -1;
        }
        while (getline(&line, &length, pfile) != -1){
            if(containsString(line, word_to_find))
                printf("%s", line);
        }
    }

    //function b: find & print all words similar to string
    void print_similar_words(char *string){

    }
    int similar(char *s, char *t, int n){

    }




    fclose(pfile);

}