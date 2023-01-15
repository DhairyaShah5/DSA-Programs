#include<stdio.h>
#include"project2.h" //including user defined library

int main(){
    system("cls"); //clears the terminal before running the code

    printf("*****Welcome Customer*****\n");
    printf("Press 1 to buy Apples \n");
    printf("Press 2 to buy Bananas \n");
    printf("Press 3 to buy Oranges \n");
    printf("Press 4 to buy Kiwis \n");
    printf("Press 5 to buy Pineapples \n");
    
    while (ask!=6){ //it will exit the program when 6 is entered
        printf("Enter from 1 to 5 to continue shopping or 6 to Print the bill : ");
        scanf("%d",&ask);//storing itemID in 'ask'

        if(ask==6){
            printf("Your Bill\n");
            InvoiceGenerator();//invoking this method to print the invoice
            break;
        }
        askItem(); //invoking this method to take input of users preferences
    }
    return 0;
}