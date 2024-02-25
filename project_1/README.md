# Contact Sorting Program README
Authors: Dagmawi Negatu and Nicholas Buchanan
Date of submission: 26 February, 2024
Project One: Structs and File I/O in C

## Overview

This program is built to process and sort contact information from a text file,
organizing contacts by their last names and first names. 
It includes operations such as trimming leading whitespaces, sorting contacts,
converting names to uppercase or lowercase,
and writing the sorted contacts back into a new file.
This project is a modification of exercises three
and four from the end of Chapter 5 of McDowell.

## Features

- **Trim Leading Whitespace**: Cleans up each line by removing leading whitespaces.
- **Sorting Contacts**: Implements bubble sort to order contacts by their last names.
- **Case Conversion**: Allows for the last names of contacts to be converted to 
  either uppercase or lowercase for consistency.
- **File Writing**: 
  Writes the processed and sorted list of contacts into the specified output file.

## File Descriptions

### Main Logic

The main operations are implemented here, including whitespace trimming,
argument checking, sorting logic, and more. It processes the contact information
and sorts the list based on last names.

#### Key Functions

- `trimLeadingWhitespace(char *line)`: Strips leading whitespaces from a given string.
- `checkArgs(int argc)`: 
  Validates the correct number of command-line arguments have been passed.
- `bubbleSort(Person data[], int size)`: 
  Orders an array of `Person` structs alphabetically by last name.
- `convertLastToUpper(Person data[], int size)`:
  Changes all last names in the contact list to uppercase.
- `convertLastToLower(Person data[], int size)`:
  Changes all last names in the contact list to lowercase.
- `writeToFile(Person item[], int size, FILE *file)`:
  Saves the sorted contact list to the output file.

### Header File (`struct_sort.h`)

Defines the data structures and function prototypes used in the program.

#### Structures

- `Address`: Contains fields for street address, city, state, and zip code.
- `Person`: 
  A contact with fields for first name, last name, address(struct), and phone number.

#### Constants

- `NUM_PEOPLE`: Specifies the maximum number of contacts that can be processed by the program.

#### Function Prototypes

Includes prototypes for all functions used with modularity.

## Usage Instructions

Compile the source file with the header file, 
then execute the program with two arguments:
the input file name (for unsorted contacts)
and the output file name (where sorted contacts will be saved).

```bash
gcc -o struct_sort struct_sort.c
./struct contacts.txt sorted_contacts.txt

