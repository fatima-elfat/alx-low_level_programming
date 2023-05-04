# 0x06. C - More pointers, arrays and strings
## Requirements
+ All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
+ All your files should end with a new line
+ Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
+ You are not allowed to use global variables
+ No more than 5 functions per file
+ You are not allowed to use the standard library. Any use of functions like printf, puts, etc… is forbidden
+ You are allowed to use _putchar
+ You don’t have to push _putchar.c, we will use our file. If you do it won’t be taken into account
+ In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
+ The prototypes of all your functions and the prototype of the function _putchar should be included in your header file called main.h
## Tasks
### 0. strcat
Write a function that concatenates two strings.

+ Prototype: char *_strcat(char *dest, char *src);
+ This function appends the src string to the dest string, overwriting the terminating null byte (\0) at the end of dest, and then adds a terminating null byte
+ Returns a pointer to the resulting string dest
## 1. strncat
Write a function that concatenates two strings.

+ Prototype: char *_strncat(char *dest, char *src, int n);
+ The _strncat function is similar to the _strcat function, except that
* it will use at most n bytes from src; and
* src does not need to be null-terminated if it contains n or more bytes
+ Return a pointer to the resulting string dest
## 2. strncpy
Write a function that copies a string.

+ Prototype: char *_strncpy(char *dest, char *src, int n);
+ Your function should work exactly like strncpy
## 3.strcmp
Write a function that compares two strings.

+ Prototype: int _strcmp(char *s1, char *s2);
+ Your function should work exactly like strcmp

