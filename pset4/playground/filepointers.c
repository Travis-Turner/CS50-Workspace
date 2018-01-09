#include <cs50.h>
#include <stdio.h>

int main () {
    //fopen() -- opens a file and returns a pointer to it.
    //fopen(<filename>, <operation> -- 'read - r', 'write - w', 'append - a')
    FILE* ptr = fopen("text.txt", "w");
    //fclose(<file pointer>)
    // once the file is closed, no more operations can be performed on that file
    fclose(ptr);
    //Before using fgetc, the file pointer that is created with fopen must have the operation
    //of type 'r' or else an error will be thrown
    FILE* ptrG = fopen("testGetC.txt", "r");
    //Following code will get the first character from the file
    // char ch = fgetc(ptrG);
    // printf("%c", ch);
    char ch;
    //REMINDER - EOF significes the end of the file
    // The following code will print all of the contents of the file.
    // while((ch = fgetc(ptrG)) != EOF) {
    //     printf("%c", ch);
    // }
    // printf("\n");
    // fclose(ptrG);
    //Using fputc is much the same, except the file must be opened for
    //either writing - w, or appending, - a.
    //NOTE - if the file does not exist, it will be created by the following
    FILE* ptrW = fopen("testWrite.txt", "w");
    while((ch = fgetc(ptrG)) != EOF){
        fputc(ch, ptrW);
    }
    fclose(ptrW);
    return 0;
}