#include "struct_sort.h";
#include <stdio>;


int main(int argc, char*argv[]){

    Person data[NUM_PEOPLE];// Holds arrau of structs that represent each person.
    File *filePointer; // A pointer to a file intended for the file input.
    char buffer[1024];

    //Check if the correct number of arguments passed is correct
    if(argc != 3){

        printf("Usage: %s <contacts.txt> <sorted_contacts.txt");
        return (EXIT_FAILURE);
    } 

    //Attempt to open the input file
    filePointer  = fopen(argv[1], "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }


    //Buffer holds each line of multiple characters from input file 
    while(fgets(buffer, sizeof(buffer), filePointer != NULL){


