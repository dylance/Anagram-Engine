# C++ Anagram Engine

This C++ project uses a custom hash table to search a text file with the 10,000 most popular words in english
for all known anagrams.

## Requirements

Any modern C++ compiler

## Instructions

* clone the project
* compile with gcc or preferred compiler and run the program

### Detailed Running Instructions

These Instructions require a g++ compiler which is included with mac and all linux distributions

`g++ -Wl,-stack_size -Wl,1000000 Source.cpp hw4_aux.cpp -o <NAME_Of_FILE_TO_EXECUTE>`

Above line compiles the code and creates an executable file to run the code as well as increasing the stack size so the project can run with the large file used.

execute the program - `./<NAME_Of_FILE_TO_EXECUTE>`

Type `words.txt` in terminal to use default word list

note: file path must be a relative file path. absolute file paths will not work

Program should will keep running until you press `control + c` to stop process.

Enter a word to search for.

All anagrams will be returned as well as the search term if it is in the dictionary.

Enjoy :)


## Creator

Dylan Ellison
