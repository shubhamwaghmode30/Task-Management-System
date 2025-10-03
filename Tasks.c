/* Building a Task Managing System */
/* Author : Shubham Waghmode */
/* Date : 22.07.2024 */

#include <stdio.h>
#include <string.h>

// Preprocessor Macros.
#define MAX_TASKS 100
#define MAX_LENGTH 100

// Defining the Task Structure.
struct Tasks 
{
    int TaskNumber;
    char TaskName[MAX_LENGTH];
    char TaskDesc[MAX_LENGTH];
    char TaskPriority[MAX_LENGTH];
    char TaskStatus[MAX_LENGTH];
    char Date[MAX_LENGTH];
    char Time[MAX_LENGTH];
};

// Global task list and counter.
struct Tasks T[MAX_TASKS];
int taskCount = 0;

// Function Adding new Task.
void AddTask()
{
    if (taskCount >= MAX_TASKS)
    {
        printf("Task list is full!\n");
        return;
    }

    struct Tasks newTask;
    newTask.TaskNumber = taskCount + 1; // Assigning a new task number.

    printf("Enter the Task Name : ");
    scanf(" %[^\n]", newTask.TaskName);

    printf("Enter Task Description : ");
    scanf(" %[^\n]", newTask.TaskDesc);

    printf("Enter Task Completion Date (YYYY-MM-DD) : ");
    scanf(" %[^\n]", newTask.Date);

    printf("Enter Task Completion Time (HH:MM) : ");
    scanf(" %[^\n]", newTask.Time);

    printf("Enter Task Priority (Low, Medium, High) : ");
    scanf(" %[^\n]", newTask.TaskPriority);

    strcpy(newTask.TaskStatus, "Not Completed"); // Default status.

    T[taskCount++] = newTask; // Adding the new Task and increment count.

    printf("Task Added Successfully!\n");
}

// Function searching Task by Name.
void SearchTask() 
{
    char name[MAX_LENGTH];
    int found = 0;

    printf("Enter the Task Name to Search : ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < taskCount; i++) 
    {
        if (strcmp(T[i].TaskName, name) == 0) 
        {
            // Table Header.
            printf("+----+---------------------+-------------------------------------------+------------+--------+----------+-----------------+\n");
            printf("| NO | TASK NAME           | DESCRIPTION                               | DATE       | TIME   | PRIORITY | STATUS          |\n");
            printf("+----+---------------------+-------------------------------------------+------------+--------+----------+-----------------+\n");

            // Table Data.
            printf("| %-2d | %-19s | %-41s | %-10s | %-5s | %-8s | %-15s |\n", 
                    T[i].TaskNumber, 
                    T[i].TaskName, 
                    T[i].TaskDesc, 
                    T[i].Date, 
                    T[i].Time, 
                    T[i].TaskPriority, 
                    T[i].TaskStatus);
            printf("+----+---------------------+-------------------------------------------+------------+--------+----------+-----------------+\n");
            
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("Task not found.\n");
    }
}

// Function changing status of a Task.
void ChangeTask() 
{
    int taskNumber;
    int found = 0;

    printf("Enter Task Number to Change Status : ");
    scanf("%d", &taskNumber);

    for (int i = 0; i < taskCount; i++)
    {
        if (T[i].TaskNumber == taskNumber) 
        {
            printf("Enter New Status (Completed/Not Completed) : ");
            scanf(" %[^\n]", T[i].TaskStatus);
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("Task not found.\n");
    } 

    else 
    {
        printf("Task status updated successfully!\n");
    }
}

// Function displaying all Tasks.
void ShowTask() 
{
    if (taskCount == 0) 
    {
        printf("No tasks to display.\n");
        return;
    }

    // Table Header.
    printf("+----+---------------------+-------------------------------------------+------------+--------+----------+-----------------+\n");
    printf("| SrNo. | TASK NAME           | DESCRIPTION                               | DATE       | TIME   | PRIORITY | STATUS          |\n");
    printf("+----+---------------------+-------------------------------------------+------------+--------+----------+-----------------+\n");

    // Table Data.
    for (int i = 0; i < taskCount; i++) 
    {
        printf("| %-2d | %-19s | %-41s | %-10s | %-5s | %-8s | %-15s |\n", 
                T[i].TaskNumber, 
                T[i].TaskName, 
                T[i].TaskDesc, 
                T[i].Date, 
                T[i].Time, 
                T[i].TaskPriority, 
                T[i].TaskStatus);
        printf("+----+---------------------+-------------------------------------------+------------+--------+----------+-----------------+\n");
    }
}

// Function to delete a Task.
void DeleteTask() 
{
    int taskNumber;
    int found = 0;

    printf("Enter Task Number to Delete : ");
    scanf("%d", &taskNumber);

    for (int i = 0; i < taskCount; i++) 
    {
        if (T[i].TaskNumber == taskNumber) 
        {
            for (int j = i; j < taskCount - 1; j++) 
            {
                T[j] = T[j + 1];
            }
            taskCount--;
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("Task not found.\n");
    }
    
    else 
    {
        printf("Task deleted successfully!\n");
    }
}

void DisplayMenu() 
{
    printf("+----+-----------------------------+\n");
    printf("| NO | OPTION                      |\n");
    printf("+----+-----------------------------+\n");
    printf("| 1  | Add Task                    |\n");
    printf("| 2  | Search Task by Name         |\n");
    printf("| 3  | Change Task Status          |\n");
    printf("| 4  | Display All Tasks           |\n");
    printf("| 5  | Delete Task                 |\n");
    printf("| 6  | Exit                        |\n");
    printf("+----+-----------------------------+\n");
}

int main() 
{
    int choice;

    // Endless Loop for seamless Experience.
    while (1) 
    {
        printf("\nWelcome to Task Management System!\n\n");
        DisplayMenu();

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        // Switch Case for clear responses.
        switch (choice) 
        {
            case 1:
                AddTask();
                break;
            
            case 2:
                SearchTask();
                break;

            case 3:
                ChangeTask();
                break;

            case 4:
                ShowTask();
                break;

            case 5:
                DeleteTask();
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

/*Presentation :- https://www.popai.pro/share.html?shareKey=e810f843c7669a461fde2bd23b3c8bc23f1adfead0361297c9392496c4e3bc0e&utm_source=presentationsharepage*/


