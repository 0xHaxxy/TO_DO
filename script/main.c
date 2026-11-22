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

void showTasks(int numTasks, TASKMANAGER tasks[])
{
     if (numTasks == 0){printf("No task avalaible.\n");}
                        else
                        { 
                            for (int i = 0; i < numTasks; i++)
                            {
                                printf("TASK %d :  \t", i + 1);
                                printf("Name : %s\t", tasks[i].name);
                                printf("Description :  %s\t", tasks[i].description);
                                printf("date :  %s\t", tasks[i].date);
                                printf("status :  %s\n",tasks[i].status == 0 ? "pending" : "done");
                            }
                        }  puts(" \n");
}

void deleteTask(TASKMANAGER tasks[], char key[], int *n)
{
    int index = 0;

    while(strcmp(key, tasks[index].name) != 0 && index < 20) index++ ;// to get the index of the target

    //starting from the target index
    for (int i = index; i < *n-1; i++){tasks[i]=tasks[i+1];}

    //reducing the size of the array
    (*n)--;
}

int main(void)
{
    // numTasks tracks the current number of tasks
    // maxTasks is the maximum number of tasks allowed
    // choice stores the user's menu selection
    // Index is used when modifying or deleting a task
    // found is a flag used for checking if any matching tasks exist

    int numTasks=0, choice, maxTasks = 20, Index, found=0;
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
        while(scanf("%d", &choice) != 1)
        {
            int c = 0;
            while ((c = getchar()) != '\n' && c != EOF)
            ;printf("wrong format, try again : ");
        };
        getchar(); 
        puts(" \n");

        switch (choice) 
        {
            case 1 :    //show all task
                    showTasks(numTasks, &tasks[0]); break;

            case 2 : //show pending tasks
                        int counter = 0;
                        for (int i = 0; i< numTasks ; i++)
                        {
                            if(tasks[i].status == 0)
                                {
                                    printf("Task %d :  \t", i + 1);
                                    printf("Name : %s\t", tasks[i].name);
                                    printf("Description :  %s\t", tasks[i].description);
                                    printf("date :  %s\n", tasks[i].date);
                                    counter ++;
                                }
                        } 
                        if (counter == 0)
                          {
                             puts("No pending task\n");
                             break;
                          }
                        puts(" \n");
                        break;
            
            case 3 : // show completed task
                        int found = 0;
                        for (int i = 0; i< numTasks ; i++)
                        {
                            if(tasks[i].status == 1)
                                {
                                    printf("Tsk %d :  \t", i + 1);
                                    printf("Name : %s\t", tasks[i].name);
                                    printf("Description :  %s\t", tasks[i].description);
                                    printf("date :  %s\n", tasks[i].date);
                                    found ++;
                                }
                        } 
                        if (found == 0)
                          {
                             puts("No task done yet \n");
                             break;
                          } puts(" \n");
                        break;  

            case 4:  // Add a new task to the list
                    if (numTasks>=maxTasks) {
                        printf("Task list is full!\n");
                        break;
                    } else {

                        // [ ] stores all the user input
                        // %[ ] tells  scanf to read only the typed character inside the square brackets
                        //  ^ inside squarre brackets means "except"
                        // \n refers to new line.

                        printf("Enter task name: ");      
                        scanf(" %[^\n]", tasks[numTasks].name);
                        getchar(); // Clear newline character left in the input buffer
                        printf("Enter task description: ");
                        scanf(" %[^\n]", tasks[numTasks].description);
                        getchar(); 
                        printf("Enter task date (YYYY-MM-DD): ");
                        scanf(" %[^\n]", tasks[numTasks].date);
                        getchar(); // 
                        tasks[numTasks].status = 0; // When adding a task, it's marked as pending by default
                        numTasks++;
                        puts(" .... \n");
                        printf("Task added successfully!\n");
                    }
                    break;      
                    
            case 5 :
                    char key[100];
                    int count=0;
                    showTasks(numTasks, &tasks[0]); 
                    printf("insert the name of the task you want to delete :  ");
                    scanf("%99[^\n]", &key[0]);

                    for(int i=0; i < maxTasks; i++)
                    {
                        if (strcmp(key, tasks[i].name) == 0)
                        {
                            deleteTask(tasks, &key[0], &numTasks);
                            break;
                        }
                        else
                            count++;
                            continue;
                    } 
                    if(count == numTasks)
                    { 
                        puts("No task matches your choice\n");
                    }
                    break;         
            
             default :
                puts("... \n");
                puts("WARNING, INVALID CHOICE\n");
                break;
        }
    }

    return 0;
}