
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
typedef struct Address{                                                                         
    char streetAddress;                                                         
    char city;                                                                  
    char state;                                                                 
    int zipCode;                                                                
}Address;                                                                       
                                                                                
/**                                                                             
*Struct Name: Person                                                           
*Descritpion: Represents a person in the input/output file;                    
*Fields:                                                                       
*Fields:                                                                       
*  - firstName: a character representing the person's first name.              
*  - lastName: a character representing the person's last name.               
*  - Address: a struct representing the person's address information.          
*  - phoneNumber: an integer representing the person's phone number.           
*/                                                                             
typedef struct Person{                                                                         
    char firstName;                                                             
    char lastName;                                                              
    Address address;                                                            
    int phoneNumber;                                                            
}Person;

#define NUM_PEOPLE 100

/**
 *Function prototype for checkArgs()
*/
int checkArgs(int argc);


/**
 *Function prototype for trimLeadingWhitespace()
*/
void trimLeadingWhitespace(char *line);

#endif //End of include guard



