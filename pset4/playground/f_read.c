#include <cs50.h>
#include <stdio.h>

int main () {
    //fread()
    //the operation of the file pointer
    //passed in must be read - r, or there
    //will be an error

    //fread(<buffer>,<size>,<qty>,<file pointer>)
    //Reads <qty> units of size <size> from file pointed to
    //by <file pointer> and store them in a memory in memory
    // points to by <buffer>
    // the first argument is a reference to a location in memory
    // where the information is to be stored.  this means if
    // the information is to be stored in a variable, the
    // address of that variable must be passed in - &c, for example
    // the name of an array - is a pointer but for a character
    // you must provide the ampersand in C
    // fread(&c, sizeof(char), 1, ptr);

    //fwrite is like fread except it will write to a file instead
    //of reading from one

    //fwrite(<buffer>,<size>,<qty>,<file pointer>)
    // reads from buffer location, writes or appends to file pointed to
    char c;
    c = 'H';
    FILE* ptr = fopen("read2.txt", "r");
    fread(&c, sizeof(char), 1, ptr);
    fclose(ptr);

    return 0;
}