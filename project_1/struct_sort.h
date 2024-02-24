
//st8ruct_sort.h
#ifndef STRUCT_SORT_H
#define STRUCT_SORT_H

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
}Address;                                                                       
                                                                                
/**                                                                             
*Struct Name: Person                                                           
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
    Address address;                                                            
    char phoneNumber[50];                                                            
}Person;    

#define NUM_PEOPLE 100

/**
 *Function prototype for checkArgs()
*/
int checkArgs(int argc);


/**
 *Function prototype for trimLeadingWhitespace
*/
void trimLeadingWhitespace(char *line);

/**
 * Function prototype for readFields 
 */
void readFields(char line[], Person data[], int *);

/**
 * Function prototype for bubbleSort
 */
void bubbleSort(Person data[], int size);

/**
 * Function prototype for convertlastToUpper
 */
void convertLastToUpper(Person data[], int size);

/**
 * Function prototype for writeToFile
 */
void writeToFile(Person item);
#endif //End of include guard
