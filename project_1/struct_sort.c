#include "struct_sort.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char*argv[]) {

    Person data[NUM_PEOPLE];// Holds array of structs that represent each person.
    char buffer[256];// buffer that holds a singe line at a time.
    

    //Check if the number of arguments passed is correct
    checkArgs(argc);
    
    //Attempt to open the input file
    FILE *filePointer;      // A pointer to a file for the file input.
    filePointer  = fopen(argv[1], "r");
    if (filePointer == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    int size = 0;
    while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
        
        
        //Clearling all clear spaces with null terminating character
        trimLeadingWhitespace(buffer);

        //Write the contents of buffer to each person record
        readFields(buffer, data, &size);
    }

    //printf("%s", data);
}


void readFields(char line[], Person data[], int *size){
    //Load each fields into a new person struct
    sscanf(line, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %s",
    data[*size].firstName, data[*size].lastName,
    data[*size].address.streetAddress, data[*size].address.city,
    data[*size].address.state, data[*size].address.zipCode, 
    data[*size].phoneNumber);

    //update size for populated persons in data of structs
    (*size)++;
}



void bubbleSort(Person data[]) {
    int size = 0;
    //printf("%s", data[size]);

}




void trimLeadingWhitespace(char *line) {
        //No leading whitesapces
        if(!(isspace((unsigned char)line[0]))) {
            return;
        }

        int originalLength = strlen(line);//Original length of array
        int i = 0;//Intended for the first non whitespace character
        while ( isspace((unsigned char)line[i])) {
            i++;
        }//Loop that checks if at non white space  character
        
        
        int j = 0;// J used to iterate over each index in line
        int num_shifts = i;//number of shifts to take to the left
        int j_bound = (originalLength - 1) - num_shifts;//Index of last character
        //Shift elements to the left removing leading white spaces
        while(j < (j_bound)) {
            
            //Shift every character by number of leading whitespaces
            line[j] = line[j + num_shifts];
            j++;

        
        }//Left with trailing white spaces equivalent to number of 
        //leading white spaces with no terminating null character
        
        //Remove trailing white spaces with terminating null character
        line[j] = '\0';
    }

int checkArgs(int argc) {
    if(argc != 3){
        printf("Usage: <contacts.txt> <sorted_contacts.txt>");
        exit(1);
    } 
}





