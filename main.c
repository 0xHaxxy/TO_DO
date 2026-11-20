#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// argv is a char pointer because it doesn't store the char[] directly but only there addresses.
// so doing this char *b[]={"haha", "hoho", "hihi"} ==> the array b[] stores the addresses of each char[] which are : haha, hoho, hihi
// if we do b[1] ===> it returns ==> hoho;

int main(int argc, char *argv[])
{
    if (strcmp(argv[1], "add") == 0) {printf("You entered add command.\n");}
    else if (strcmp(argv[1], "list") == 0) {printf("You entered list command.\n");} 
    else if (strcmp(argv[1], "done") == 0) {printf("You entered done command.\n");}
    else if (strcmp(argv[1], "del") == 0) {printf("You entered del command.\n");} 
    else {printf("INVALID COMMAND\n");}
    
    return 0;
}