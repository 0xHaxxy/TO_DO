#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{    
   char name[100];
    char description[300];
    char date[20];
    int priority;
    int status; // 0 = pending, 1 = completed
}TASKMANAGER;

int main(void)
{
    while(1) {
        // Display the main menu and get user input
        printf("----- Task Manager Menu -----\n");
        printf("1. Show all Tasks\n");
        printf("2. Show Pending Tasks\n");
        printf("3. Show Completed Tasks\n");
        printf("4. Add Task\n");
        printf("5. Delete Task\n");
        printf("6. Complete Task\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%i", &choice);
        getchar(); // Clear newline character left in the input buffer
    

    return 0;
}