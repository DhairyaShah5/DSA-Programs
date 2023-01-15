#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include"project.h"
int main()
{
    int n;
    system("cls");
    printf("INSTRUCTIONS\n");
    printf("\n");
    printf("1.Username should not have more then 20 characters\n");
    printf("2.DOB format : dd/mm/yy\n");
    printf("3.Password should not more than 20 characters\n");
    printf("\n");

    do
    {
        printf("Assigment for the operations\n");
        printf("Enter 1 for SignUp\n");
        printf("Enter 2 for Login\n");
        printf("Enter 3 for Edit\n");
        printf("Enter 4 for Delete\n");
        printf("Enter 5 for Exit\n");
        printf("\n");
        printf("What operation do you want to perform : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("You choose to do Signup.\n");
            SignUp();
            break;
        case 2:
            printf("You choose to Login.\n");
            Login();
            break;
        case 3:
            printf("You choose to Edit the account details.\n");
            Edit();
            break;
        case 4:
            printf("You choose to delete the account.\n");
            Delete();
            break;
        case 5:
            printf("Exited Succesfully!\n");
            break;
        default:
            printf("Enter a valid number!\n");
            break;
        }
    } while (n != 5);
    return 0;
}