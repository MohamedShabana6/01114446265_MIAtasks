#include <stdio.h>
#include <stdlib.h>
/**
*@brief Function to print in stars for letters in 5 lines in this case
*@param str string for user input
*@return none
**/
void printWithStars(char str[30])
{
    int i=0,line;
    for(line =1 ; line <=5 ; line ++)
    {
        i=0;
        while(str[i]!='\0')
        {
            switch(tolower(str[i]))
            {
            case 'a':
            {
                A(line);
                break;
            }
            case 'b':
            {
                B(line);
                break;
            }
            case 'c':
            {
                C(line);
                break;
            }
            case 'd':
            {
                D(line);
                break;
            }
            case 'g':
            {
                G(line);
                break;
            }
            case 'r':
            {
                R(line);
                break;
            }
            case 'u':
            {
                U(line);
                break;
            }
            default :
                printf("     ");

            }
            i++;

        }
        printf("\n");

    }


}
void A(int line)// character conversion to star on A , B , C ,D , G , R , U sample
{

    switch(line)
    {
    case 1:
    case 3:
    {
        printf("*****   ");
        break;
    }
    case 2:
    case 4:
    case 5:
    {
        printf("*   *   ");
        break;
    }


    }
}
void B(int line)
{

    switch(line)
    {
    case 1:
    case 3:
    case 5:

    {
        printf("*****   ");
        break;
    }
    case 2:
    case 4:

    {
        printf("*    *  ");
        break;
    }

    }
}
void C(int line)
{

    switch(line)
    {
    case 1:
    case 5:
    {
        printf("*****  ");
        break;
    }
    case 2:
    case 3:
    case 4:
    {
        printf("*      ");
        break;
    }


    }
}
void D(int line)
{

    switch(line)
    {
    case 1:
    case 5:
    {
        printf("****   ");
        break;
    }
    case 2:
    case 3:
    case 4:
    {
        printf("*   *  ");
        break;
    }


    }
}

void G(int line)
{

    switch(line)
    {
    case 1:
    {
        printf("*****  ");
        break;
    }
    case 2:
    {
        printf("*      ");
        break;
    }
    case 3:
    {
        printf("*  **  ");
        break;
    }
    case 4:
    {
        printf("*   *  ");
        break;
    }
    case 5:
    {
        printf("*****  ");
        break;
    }
    }
}
void R(int line)
{

    switch(line)
    {
    case 1:
    {
        printf("****   ");
        break;
    }
    case 2:
    {
        printf("*   *  ");
        break;
    }
    case 3:
    {
        printf("****   ");
        break;
    }
    case 4:
    {
        printf("*   *  ");
        break;
    }
    case 5:
    {
        printf("*    * ");
        break;
    }
    }
}

void U(int line)
{

    switch(line)
    {
    case 1:
    {
        printf("*   *  ");
        break;
    }
    case 2:
    {
        printf("*   *  ");
        break;
    }
    case 3:
    {
        printf("*   *  ");
        break;
    }
    case 4:
    {
        printf("*   *  ");
        break;
    }
    case 5:
    {
        printf("*****  ");
        break;
    }
    }
}


int main()
{
    char string[30];
    printf("Enter your name(A ,B ,C ,D ,R ,U ,G ) Dr:");
    gets(string);

    printWithStars(string);






    return 0;
}
