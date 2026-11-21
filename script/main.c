#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{    
   char name[100];
    char description[300];
    char date[20];
    int status; // 0 = pending, 1 = completed
}TASKMANAGER;

int main(void)
{
    // numTasks tracks the current number of tasks
    // maxTasks is the maximum number of tasks allowed
    // choice stores the user's menu selection
    // Index is used when modifying or deleting a task
    // found is a flag used for checking if any matching tasks exist

    int numTasks=0, maxTasks=30, choice, Index, found=0;
    TASKMANAGER tasks[maxTasks]; // Array of taskManager structs to store the tasks

    while(1) {

        // Display the main menu and get user input
        printf("=========================== Task Manager Menu ==================================\n");
        printf("1. Show all Tasks\n");
        printf("2. Show Pending Tasks\n");
        printf("3. Show Completed Tasks\n");
        printf("4. Add Task\n");
        printf("5. Delete Task\n");
        printf("6. Complete Task\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice); 
        getchar(); // Clear newline character left in the input buffer

        switch (choice) 
        {
            case 1 :    //show all task
                        if (numTasks == 0){printf("No task avalaible.\n");}
                        else
                        { 
                            for (int i = 0; i < numTasks; i++)
                            {
                                printf("ask %d :  \t", i + 1);
                                printf("Name : %s\t", tasks[i].name);
                                printf("Description :  %s\t", tasks[i].description);
                                printf("date :  %s\t", tasks[i].date);
                                printf("status :  %s\n",tasks[i].status == 0 ? "pending" : "done");
                            }
                        } break;

            case 2 : //show pending tasks
                        int counter = 0;
                        for (int i = 0; i< numTasks ; i++)
                        {
                            if(tasks[i].status == 0)
                                {
                                    printf("ask %d :  \t", i + 1);
                                    printf("Name : %s\t", tasks[i].name);
                                    printf("Description :  %s\t", tasks[i].description);
                                    printf("date :  %s\t", tasks[i].date);
                                    counter ++;
                                }
                        } 
                        if (counter == 0)
                          {
                             puts("No pending task\n");
                             break;
                          }
                        break;
            
            default :
                puts("WARNING, INVALID CHOICE\n");
                break;
        }
    }

    return 0;
}