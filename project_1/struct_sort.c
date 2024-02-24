#include "struct_sort.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {

    Person data[NUM_PEOPLE];// Holds array of structs that represent each person.
    char buffer[256];// buffer that holds a singe line at a time.
    int size = 0;//size of populated persons in data array

    //Check if the number of arguments passed is correct
    checkArgs(argc);
    
    //Attempt to open the input file
    FILE *filePointer;      // A pointer to a file for the file input.
    filePointer  = fopen(argv[1], "r");
    if (filePointer == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    
    while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
        
        
        //Clearling all clear spaces with null terminating character
        trimLeadingWhitespace(buffer);

        //Write the contents of buffer to each person record
        readFields(buffer, data, &size);
    }
    
    bubbleSort(data, size);

    FILE *file = fopen(argv[2], "w"); // Open the file for writing
    if (!file) {
        perror("Failed to open file");
        exit(1);
    }


    writeToFile(data, size, file);
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

void convertLastToLower(Person data[], int size) {
    for (int i = 0; i < size; i++) {        // For every struct in the Person struct array
        for (int j = 0; data[i].lastName[j] != '\0'; j++) {     // For every character in each Person structs lastname
            if (isupper(data[i].lastName[j])) {
                data[i].lastName[j] = tolower(data[i].lastName[j]);     // Convert all lowercase characters to uppercase
            }
        }
    }
    //strcasecmp
}

void writeToFile(Person item[], int size, FILE  *file) {
    for (int i = 0; i < size; i++) {
        
        //Load each fields into a new person struct                                 
        fprintf(file, "%s, %s, %s, %s, %s, %s, %s",                
        item[i].firstName, item[i].lastName,                                
        item[i].address.streetAddress, item[i].address.city,                
        item[i].address.state, item[i].address.zipCode,                     
        item[i].phoneNumber);                                                   
        fprintf(file, "\n");
    }
   
    char buffer[1024];                                                          
    while (fgets(buffer, sizeof(buffer), file) != NULL) {                   
        printf("%s", buffer);                                                   
        printf("%s", "I am not writing to the file");                           
    }                                                                           
                                                                                
    fclose(file); 
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
            if (strcasecmp(data[j].lastName, data[j+1].lastName) > 0) {     // if lastNames out of order
                swap(&data[j], &data[j + 1]);  
            }

            else if (strcasecmp(data[j].lastName, data[j+1].lastName) == 0) {        // if last name is the same
                if (strcasecmp(data[j].firstName, data[j+1].firstName) > 0) {       // if first name is out of order
                    swap(&data[j], &data[j + 1]);  
                }
            }
        }
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

void checkArgs(int argc) {
    if(argc != 3){
        printf("Usage: <contacts.txt> <sorted_contacts.txt>");
        exit(1);
    } 
}





