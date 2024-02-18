#include "struct_sort.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {

    Person data[NUM_PEOPLE];// Holds array of structs that represent each person.
    FILE *filePointer; // A pointer to a file intended for the file input.
    char buffer[256];// buffer that holds a singe line at a time.

    //Check if the correct number of arguments passed is correct
    if(argc != 3){

        printf("Usage: %s <contacts.txt> <sorted_contacts.txt");
        return (EXIT_FAILURE);
    } 

    //Attempt to open the input file
    filePointer  = fopen(argv[1], "r");
    if (filePointer == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    /**
     * Function to trim leading whitespace
     */
    void trimTrailingWhitespace(char *line) {

        int i = 0;//index that allows to begin at the start of line.
        while ( isspace((unsigned char)line[i])){
            i++;
        }
        //Loop that checks if we are at a meaningful character
        line[i - 1] = '\0';//Once we found the first charcater,
        //remove the leading whitespace by the null \O char representation

     }

    //Buffer holds each line of multiple characters from input file 
    while(fgets(buffer, sizeof(buffer), filePointer != NULL){
        
        trimLeadingWhitespace(buffer);
        //Use this assuming we have no white leading spaces
        sscanf(buffer, "%s", "%s", "%d" "%s" "%s", "%s", 
        "%s", "%d", "%f", 

