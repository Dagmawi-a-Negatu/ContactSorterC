/**
 * Dagmawi Negatu, Nicholas Buchannan
 * struct_sort.h header file
 * Declare the typedef of the person information, prototypes for all
 * prototypes in dog.c, #defines for named constants and stdio library. 
 */

#ifndef STRUCT_SORT_H
#define STRUCT_SORT_H
#include <stdio.h>
/**                                                                             
 * Struct Name: Address                                                         
 * Description: Represents an address for person struct.                        
 *                                                                              
 * Fields:                                                                      
 *   - streetAddress: a character represeting street address                    
 *   of a person.                                                               
 *   - city: a character representing the person's city.                        
 *   - state: a character representing the person's state.                      
 *   - zipCode: an integer representing the person's zip code.                  
 */                                                                             
typedef struct{                                                                         
    char streetAddress[50];                                                         
    char city[50];                                                                  
    char state[50];                                                                 
    char zipCode[50];                                                                
}address;                                                                       
                                                                                
/**                                                                             
*Struct Name: person_t                                                     
*Description: Represents a person in the input/output file;                    
*Fields:                                                                       
*Fields:                                                                       
*  - firstName: a character representing the person's first name.              
*  - lastName: a character representing the person's last name.               
*  - Address: a struct representing the person's address information.          
*  - phoneNumber: an integer representing the person's phone number.           
*/                                                                             
typedef struct {                                                                         
    char firstName[50];                                                             
    char lastName[50];                                                              
    address address;                                                            
    char phoneNumber[50];                                                            
}person_t;   

#define NUM_PEOPLE 100

/**
 *Function prototype for checkArgs()
*/
void checkArgs(int argc);


/**
 *Function prototype for trimLeadingWhitespace
*/
void trimLeadingWhitespace(char *line);

/**
 * Function prototype for readFields 
 */
void readFields(char line[], person_t data[], int *);

/**
 * Function prototype for bubbleSort
 */
void bubbleSort(person_t data[], int size);

/**
 * Function prototype for writeToFile
 */
void writeToFile(person_t item[], int size, char *argv[]);

/**
 * Function prototype for openFile
*/
FILE* openFile(char* argv[]);


#endif //End of include guard
