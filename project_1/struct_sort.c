#include "struct_sort.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


/**
 * Driver function of the program. Instantiates Person struct array and buffer to hold each
 * line of input. Each line is read into the buffer and trimmed of leading whitespace. Data in the buffer is then
 * assigned to respective fields in the struct array for each line given by the input file. Once the struct array has been
 * filled the program sorts it using a bubble sort and writes the contents to a file
 * @param int argc: Number of arguments provided to the program
 * @param char *argv[]: List of arguments provided to the program
 * @return 0: Indicates successful termination of program
*/
int main(int argc, char *argv[]) {

    Person data[NUM_PEOPLE];        // Holds array of structs that represent each person.
    char buffer[256];       // Buffer that holds a single line at a time.
    int size = 0;       // Size of populated persons in data array
 
    // Check if the number of arguments passed is correct
    checkArgs(argc);        
    
    // Attempt to open the input file
    FILE *filePointer = openFile(argv);     
 
    // While the buffer has a line from the file in it
    while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
        // Clear all whitespace at the beginning of each line
        trimLeadingWhitespace(buffer);
        //Write the contents of the buffer to each Person record
        readFields(buffer, data, &size);
    }

    // Use bubble sort to organize data based on last name/first name if last names are equal
    bubbleSort(data, size);     

    // Write sorted data to file specified by program arguments
    writeToFile(data, size, argv);
    // return 0 indicating successful termination of program
    return 0;
}

/**
 * Returns a pointer to the contents of a file
*/
FILE* openFile(char* argv[]) {
    FILE *filePointer;      // A pointer to a file for the file input.
    filePointer  = fopen(argv[1], "r");
    if (filePointer == NULL) {
        perror("Error opening input file");
        exit(1);
    }
    return filePointer;
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



void writeToFile(Person item[], int size, char *argv[]) {
    FILE *file = fopen(argv[2], "w"); // Open the file for writing
    if (!file) {
        perror("Failed to open file");
        exit(1);
    }

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





