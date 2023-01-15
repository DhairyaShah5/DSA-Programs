#include <stdio.h>
#include "project3.h" //including required header file

int main()
{
    system("cls");
    printf("Hello everyone, welcome to Rappozior Club...\n");
    printf("Please remain calm we are opening soon...\n\n");

    Sleep(2000); // to delay next display by 2 sec

    printf("We are now open !!!\n\n");
    printf("Everyone look at your passes and write down your Name, Number and the Priority as mentioned in the pass...");
    DataInput(); // invoking function to get input

    printf("\nNow we will arrange you as per your priority");
    Check(); // invoking function to check priority
    system("cls");

    printf("\nAll members arranged");
    printf("\n\nGet in a queue as per the display\n");
    Display(); // invoking function to display priority queue
    return 0;
}