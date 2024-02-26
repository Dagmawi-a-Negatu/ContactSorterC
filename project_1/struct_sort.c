/**
 * Dagmawi Negatu, Nicholas Buchannan
 * February 26/2024
 * struct_sort.c source file
 * This implemenation reads in the contact information from a file, sort the contact information records, 
 * and then write/re-write the sorted information to an ouput file that's named by the user.
 * In main, declare an array of person_t and buffer to hold each line from input file.
 * Then, read in the file and load each line until the end of lines is reached. With the 
 * TrimLeadingWhitespace function, strip all leading white spaces of the input file line by line.
 * The trimmed buffer is thus passed into the readFields function that process each fields into the 
 * array of person_t structs using scanset. This file includes a modified implmentation of bubble sort that
 * sorts based on the first name and last name of each person_t struct. Finally, the sorted fields 
 * in an array of person_t structs are written to an output file named by the user.
 */


#include "struct_sort.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


/**
 * Driver function of the program. Instantiates Person struct array and buffer to hold each
 * line of input. Each line is read into the buffer and trimmed of leading whitespace.
 * Data in the buffer is then assigned to respective fields in the struct array for each line
 * given by the input file. Once the struct array has been
 * filled the program sorts it using a bubble sort and writes the contents to a file
 * @param int argc: Number of arguments provided to the program
 * @param char *argv[]: List of arguments provided to the program
 * @return 0: Indicates successful termination of program
*/

int main(int argc, char *argv[]) {

    person_t data[NUM_PEOPLE]; // Holds array of structs that represent each person.
    char buffer[256]; // Buffer that holds a single line at a time.
    int size = 0;// Size of populated persons in data array
 
    // Check if the number of arguments passed is correct
    checkArgs(argc);        
    
    // Attempt to open the input file
    FILE *filePointer = openFile(argv);     
 
    // While the file has a line, load line by line to buffer
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
 * Opens a file based off of the first parameter supplied to the program and returns a pointer
 * to the contents of the file. If the contents are null it returns an error and ends the program
 * @param char *argv[]: List of arguments supplied to the program
 * @return File *filePointer: A pointer to the contents of the read file
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


/**
 * Reads individual fields from a single line and stores them in a person_t struct.
 * 
 * This function parses a single line of text expected to contain comma-separated values
 * corresponding to the fields of a person_t struct. The size variable is incremented
 * to reflect the addition of a new person record.
 * @param char line[]: A character array containing the comma-separated values to be parsed.
 * @param person_t data: An array of person_t structs where the parsed data will be stored.
 * @param int *size: A pointer to an integer that keeps track of the number of populated entries
 * in the data array.
 */
void readFields(char line[], person_t data[], int *size){
    // Parsing the line and loading each field into a new Person struct
    sscanf(line, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %s",//Read until scansets reached
    data[*size].firstName, data[*size].lastName,
    data[*size].address.streetAddress, data[*size].address.city,
    data[*size].address.state, data[*size].address.zipCode, 
    data[*size].phoneNumber);
    //update size for populated persons in data of structs
    (*size)++;
}


/**
 * Writes data from a person_T struct array to a file provided by the second argument
 * given to the program. A file pointer is created using the write mode before
 * a loop starts over the person_t struct array until a contact is reached for
 * which no fields have been initialized. Each iteration assigns values
 * from the input to the Person objects relevant fields.
 * @param person_t item[]: person_t struct array to be written to the file
 * @param int size: Size representing each Person for which fields have been initialized
 * @param char *argv[]: List of arguments supplied to the program
*/
void writeToFile(person_t item[], int size, char *argv[]) {
    FILE *file = fopen(argv[2], "w"); // Open the file for writing
    if (!file) {
        perror("Failed to open file");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        
        //Load each fields into a new person struct                                 
        fprintf(file, "%s, %s, %s, %s, %s, %s, %s", //Write until each scanset reached               
        item[i].firstName, item[i].lastName,                                
        item[i].address.streetAddress, item[i].address.city,                
        item[i].address.state, item[i].address.zipCode,                     
        item[i].phoneNumber);                                                   
        fprintf(file, "\n");
    }                                                                     
                                                                                
    fclose(file); 
}

/**
* Helper function to swap two variables. The function takes two
* pointers and creates a temp variable for the dereferenced value
* of the first pointer. The function then swaps the same type of value
* for person1 and person2 using the temp variable to prevent loss of
* the value
* @param person_t *person1: Pointer to the first Person object
* @param person_T *person2: Pointer to the second Person object
*/
void swap(person_t *person1, person_t *person2) {
    person_t temp = *person1;
    *person1 = *person2;
    *person2 = temp;
}

/**
 * Completes a bubble sort of the person_t struct array for every contact for
 * which fields have been initialized for. Sorting is completed by looping through
 * every item except the last in the person_t struct array then again looping for every item
 * up until a completed sort has been reached. strcasecmp is used to indicate regardless of case
 * whether the last name of one person precedes another. If the lastName of the current item
 * in the iteration comes after the last name of the next item in the iteration it will
 * swap the data using the swap() function. If the names are equal it will do the sort for that
 * item based on the first name instead.
 * @param person_t data[]: A person_t struct array to be sorted
 * @param: int size: Number of persons in the data array for which fields have been initialized
 **/
void bubbleSort(person_t data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < (size - i - 1); j++) {
        // > 0 indicates the lastName field from the person object in data[0]
        //  comes after the lastName of the same type object in data[1]
        // < 0 indicates the lastName field from the person object
        //in data[0] comes before the lastName of the same type object in data[1]
            if (strcasecmp(data[j].lastName, data[j+1].lastName) > 0) {
                swap(&data[j], &data[j + 1]);//if lastnames out of order
            }

            else if (strcasecmp(data[j].lastName, data[j+1].lastName) == 0) {     
                if (strcasecmp(data[j].firstName, data[j+1].firstName) > 0) {       
                    swap(&data[j], &data[j + 1]);//if last name the same or out of order
                }
            }
        }
    }
}



/**
 * Removes leading whitespace characters from the given string.
 *
 * This function shifts all characters in the string to the left to overwrite
 * leading whitespace characters, then null-terminates the string after the
 * last non-whitespace character. It operates directly on the input string.
 *
 * @param char *line: A pointer to the character array (string) to be trimmed. This
 * string is modified in place.
 *
 * @note This function does not remove trailing whitespace characters.
 * @note The function assumes that the input string is properly null-terminated.
 */
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

/**
 * Checks whether arguments are correctly supplied to the program
 * @param argc: Number of arguments supplied to the program
*/
void checkArgs(int argc) {
    if(argc != 3){
        printf("Usage: <contacts.txt> <sorted_contacts.txt>");
        exit(1);
    } 
}





