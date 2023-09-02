#include <stdio.h>
#include <stdlib.h>
/**
*@brief create runtime delay for countdown
*@param none
*@return none
**/
void delay()
{
    int i,j;
    for(i=0; i<22000; i++)
        for(j=0; j<21500; j++)
        {

        }
}
int main()
{
    int countDown;
    printf("Countdown Starts from: ");
    scanf("%d",&countDown);
    for(int i = countDown; i>0; i--)
    {
        printf("%d \n",i);
        delay();

    }
    printf("Blast off to the moon");
}
