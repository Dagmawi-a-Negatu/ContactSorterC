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
    convertLastToUpper(data, size);
    //printf("%s", data[0].lastName);     // converted to upper
    printf("%s, %s\n%d", data[0].lastName, data[1].lastName, strcmp(data[0].lastName, data[1].lastName));
    printf("\n=======================================");
    bubbleSort(data, size);
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




void convertLastToUpper(Person data[], int size) {
    for (int i = 0; i < size; i++) {        // For every struct in the Person struct array
        for (int j = 0; data[i].lastName[j] != '\0'; j++) {     // For every character in each Person structs lastname
            if (islower(data[i].lastName[j])) {
                data[i].lastName[j] = toupper(data[i].lastName[j]);     // Convert all lowercase characters to uppercase
            }
        }
    }
    //strcasecmp
}

void writeToFile(Person item) {
    printf("%s", item.firstName);
}

void swap(Person *person1, Person *person2) {
    Person temp = *person1;
    *person1 = *person2;
    *person2 = temp;

}
void bubbleSort(Person data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < (size - i - 1); j++) {
        // > 0 indicates the lastName field from the person object in data[0] comes after the lastName of the same type object in data[1]
        // < 0 indicates the lastName field from the person object in data[0] comes before the lastName of the same type object in data[1]
        if (strcmp(data[j].lastName, data[j+1].lastName) > 0) {     // if lastNames out of order
            Person temp = data[j];
            swap(&data[j], &data[j + 1]);
        }
        }
    }
    for (int i = 0; i < size; i++) {
        printf("\n%s, %s, %s, %s\n", data[i].firstName, data[i].lastName, data[i].address.streetAddress, data[i].address.city, data[i].address.state, data[i].address.zipCode, data[i].phoneNumber);
    }
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





