/**SEARCH IN TEXT USE STRING METHODS
 * 
 * @input text. first line: string and char 'a' or 'b'
 * @param string would be word_to_find
 * @param char dedcate function to run
 * second line is empty, and third-to-end is text to search in 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 256
#define WORD 30

int checkWord(char *word_to_find, int wtf_size, char *word, int word_size);
int containsString(char *line, char *substring);

/** function a: print all lines contains specific substring */
void printLinesWith(char *word_to_find) {
    char line[LINE];

    fgets(line, LINE, stdin);//empty line

    while (fgets(line, LINE, stdin) != NULL) {
        if (containsString(line, word_to_find))
            printf("%s", line);
    }
}

/** function b: find & print all words similar to string */
void printWordsWith(char *word_to_find) {
    char buf[WORD];

    while (scanf(" %s", buf) == 1) {
        int res2 = checkWord(word_to_find, (int) strlen(word_to_find), buf, (int) strlen(buf));
        if (res2 == 0) {
            printf("%s\n", buf);
        }
    }
}

/** save and allocate memory for substring to look for */
char *get_next_word() {
    char *word = (char *) malloc(WORD);
    scanf("%s", word);
    return word;
}

int main() {
    /**  READ COMMAND LINE */
    char *word_to_find, *task_type;
    word_to_find = get_next_word();
    task_type = get_next_word();


    /** RUN TASK */
    if (strcmp(task_type, "a") == 0)
        printLinesWith(word_to_find);
    else
        printWordsWith(word_to_find);


    /** FREE MEMORY */
    free(word_to_find);
    free(task_type);

    return 0;
}





/**help function: find all lines contains specific substring*/
int containsString(char *line, char *substring) {
    unsigned long line_length = strlen(line);
    unsigned long substring_length = strlen(substring);

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

/**help function: compare string's length and contance*/
int checkWord(char *word_to_find, int wtf_size, char *word, int word_size) {
    if (wtf_size != word_size && wtf_size + 1 != word_size) {
        return -1;
    }

    int one_error = 0;
    for (int word_index = 0; word_index < word_size; ++word_index) {
        if (*word_to_find != *word) {
            if (one_error == 1) {
                return -1;
            }
            one_error = 1;
        } else {
            word_to_find++;
        }
        word++;
    }

    return 0;
}