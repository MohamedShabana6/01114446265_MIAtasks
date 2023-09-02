#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define SIZE 50


char globalTasks[SIZE][100];//array of strings to store tasks
int globalCounter = 0; // counter to count tasks
int flag =0;


//FILE NAME used Tasks.txt
void displayMenu();
void menu();
void addTask();
void viewTask();
void removeTask();



int main()
{
    FILE *f = fopen("Tasks.txt","w");//delete garbage or previous tasks in file
    fclose(f);


    menu();

}

void displayMenu()
{
    printf("\n\nMinions Task Manager\n1.Add Task\n2.View Tasks\n3.Remove Task\n4.Exit\n");
}


void addTask()
{
    printf("\nEnter task description: ");

    gets(globalTasks[globalCounter]);


    FILE *f =fopen("Tasks.txt","a+");//append data to file
    fprintf(f,"%s\n",globalTasks[globalCounter]);
    fclose(f);
    globalCounter++;
    printf("Task added successfully");


}
void viewTask()
{
    int taskCounter = 0 ;//to traverse through globalTasks array
    if(flag ==1 && globalCounter == 0) // no tasks flag
    {
        printf("-----------------------------------------\n");
        printf("No Tasks\n");
        printf("-----------------------------------------\n");
        return;
    }

    FILE *f =fopen("Tasks.txt","r");


    while(!feof(f))
    {
        if(flag==0 && globalCounter == 0)//no tasks flag if first user input is "2"- view tasks
        {
            printf("-----------------------------------------\n");
            printf("No Tasks\n");
            printf("-----------------------------------------\n");
            flag=1;
            return;
        }

        fscanf(f,"%[^\n]\n",globalTasks[taskCounter]);//printing tasks
        printf("-----------------------------------------\n");
        printf("Task ID: %d\n",taskCounter+1);
        printf("description: %s\n",globalTasks[taskCounter]);
        printf("-----------------------------------------\n");
        taskCounter++;


    }


    fclose(f);

}
void removeTask()
{

    char del[20];
    int i=0;
    printf("Enter ID to delete: ");
    gets(del);
    if(atoi(del)>0 && atoi(del)<=globalCounter)//check validation of user input
    {


        if(atoi(del)==globalCounter)//if last task is to be removed
            globalCounter--;
        else
        {
            int AfterDel=atoi(del);
            while(AfterDel<=globalCounter) //delete in arrays
            {
                strcpy(globalTasks[AfterDel-1],globalTasks[AfterDel]);
                AfterDel++;
            }
            globalCounter--;
        }

        FILE *f = fopen("Tasks.txt","w");// print array in file after deletion
        while(i<globalCounter)
        {
            fprintf(f,"%s\n",globalTasks[i]);
            i++;
        }
        fclose(f);
        printf("Task removed successfully\n");
    }
    else
        printf("Invalid Input");

}
void menu()
{
    char choice[20];
    displayMenu();
    printf("\nSelect an option: ");
    gets(choice);
    if(strcmp(choice,"1")==0)
    {
        addTask();
        menu();
    }
    else if(strcmp(choice,"2")==0)
    {
        viewTask();
        menu();
    }
    else if(strcmp(choice,"3")==0)
    {
        removeTask();
        menu();
    }

    else if(strcmp(choice,"4")==0)
    {
        printf("Exiting minions Task Manager.Have a great day!\n");
        exit(0);
    }
    else
    {
        printf("Wrong Input!!!\n");
        menu();
    }




}
