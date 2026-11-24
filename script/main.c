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
} TASKMANAGER;

void showTasks(int numTasks, TASKMANAGER tasks[])
{
    if (numTasks == 0)
    {
        printf("No task available.\n");
    }
    else
    {
        for (int i = 0; i < numTasks; i++)
        {
            printf("TASK %d :  \t", i + 1);
            printf("Name : %s\t", tasks[i].name);
            printf("Description :  %s\t", tasks[i].description);
            printf("date :  %s\t", tasks[i].date);
            printf("status :  %s\n", tasks[i].status == 0 ? "pending" : "done");
        }
    }
    puts(" \n");
}

void showPendingTask(TASKMANAGER tasks[], int numTasks)
{
    int counter = 0;

    for (int i = 0; i < numTasks; i++)
    {
        if (tasks[i].status == 0)
        {
            printf("Task %d :  \t", i + 1);
            printf("Name : %s\t", tasks[i].name);
            printf("Description :  %s\t", tasks[i].description);
            printf("date :  %s\n", tasks[i].date);
            counter++;
        }
    }
    if (counter == 0)
    {
        puts("No pending task\n");
        return;
    }
    puts(" \n");
}

void showCompleteTask(TASKMANAGER tasks[], int numTasks)
{
    for (int i = 0; i < numTasks; i++)
    {
        if (tasks[i].status == 1)
        {
            printf("Task %d :  \t", i + 1);
            printf("Name : %s\t", tasks[i].name);
            printf("Description :  %s\t", tasks[i].description);
            printf("date :  %s\n", tasks[i].date);
        }
    }
}

void addTask(TASKMANAGER tasks[], int *numTasks, int maxTasks)
{
    if (*numTasks >= maxTasks)
    {
        printf("Task list is full!\n");
        return;
    }

    // [ ] stores all the user input
    // %[ ] tells  scanf to read only the typed character inside the square brackets
    //  ^ inside squarre brackets means "except"
    // \n refers to new line.

    printf("Enter task name: ");
    scanf(" %99[^\n]", tasks[*numTasks].name);
    getchar(); // Clear newline character left in the input buffer
    printf("Enter task description: ");
    scanf(" %299[^\n]", tasks[*numTasks].description);
    getchar();
    printf("Enter task date (YYYY-MM-DD): ");
    scanf(" %19[^\n]", tasks[*numTasks].date);
    getchar();
    tasks[*numTasks].status = 0; // When adding a task, it's marked as pending by default
    (*numTasks)++;
    puts(" .... \n");
    printf("Task added successfully!\n");
}

void deleteTask(TASKMANAGER tasks[], int *n)
{
    char key[100];
    int found = 0;

    showTasks(*n, tasks);
    printf("insert the name of the task you want to delete :  ");
    scanf(" %99[^\n]", key);

    for (int i = 0; i < *n; i++)
    {
        if (strcmp(key, tasks[i].name) == 0)
        {
            //starting from the target index
            for (int j = i; j < *n - 1; j++) tasks[j] = tasks[j + 1];

            //reducing the size of the array
            (*n)--;
            found = 1;
            printf("Task deleted successfully\n");
            break;
        }
    }
    if (!found)
    {
        puts("No task matches your choice\n");
    }
}

void completeTask(TASKMANAGER tasks[], int numTasks)
{
    char mark[100];
    int found = 0;

    showTasks(numTasks, tasks);
    printf("insert the name of the task you want to mark as completed :  ");
    scanf(" %99[^\n]", mark);

    for (int i = 0; i < numTasks; i++)
    {
        if (strcmp(mark, tasks[i].name) == 0 && tasks[i].status == 0)
        {
            tasks[i].status = 1;
            found = 1;
            printf("Task completed successfully\n");
            break;
        }
    }
    if (!found)
    {
        puts("The task may be already completed or the input was incorrect\n");
    }
}

int main(void)
{
    // numTasks tracks the current number of tasks
    // maxTasks is the maximum number of tasks allowed
    // choice stores the user's menu selection

    int numTasks = 0, choice, maxTasks = 20;
    TASKMANAGER tasks[maxTasks]; // Array of taskManager structs to store the tasks

    while (1)
    {
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
        while (scanf(" %d", &choice) != 1)
        {
            int c = 0;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("wrong format, try again : ");
        }
        puts(" \n");

        switch (choice)
        {
            case 1:
                showTasks(numTasks, tasks);
                break;

            case 2:
                showPendingTask(tasks, numTasks);
                break;

            case 3:
                showCompleteTask(tasks, numTasks);
                break;

            case 4:
                addTask(tasks, &numTasks, maxTasks);
                break;

            case 5:
                deleteTask(tasks, &numTasks);
                break;

            case 6:
                completeTask(tasks, numTasks);
                break;

            case 7:
                puts("leaving .....");
                exit(0);

            default:
                puts("... \n");
                puts("WARNING, INVALID CHOICE\n");
                break;
        }
    }

    return 0;
}