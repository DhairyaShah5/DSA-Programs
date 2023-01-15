#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct userName
{
    char name[30];
    char dob[12];
    char username[20];
    char password[20];
    char email[20];
    int mobNum[10];
};
struct userName user[10];
int count;
int delete = 0;

void Display(int n);
void SignUp();
void Login();
void Edit();
int Check();
void Delete();

void Display(int count)
{
    printf("User details are as follow :\n");
    printf("Name : %s \n", user[count].name);
    printf("Dob : %s \n", user[count].dob);
    printf("Gmail : %s \n", user[count].email);
    printf("Mobile Number : %s \n", user[count].mobNum);
}
void SignUp()
{
    int i = 0;
    do
    {
        if (i != count)
        {
            i = count;
        }
        printf("Enter your Name :");
        scanf("%s", &user[i].name);
        printf("Enter your DOB :");
        scanf("%s", &user[i].dob);
        printf("Enter your Username :");
        scanf("%s", &user[i].username);
        printf("Enter your Password :");
        scanf("%s", &user[i].password);
        printf("Enter your Email address :");
        scanf("%s", &user[i].email);
        printf("Enter your Number :");
        scanf("%s", &user[i].mobNum);
        printf("Successfully Registered");
        printf("\n");
        i++;
        count += i;
        printf("\n");
    } while (0);
}
int Check()
{
    char usr[20], pas[20];
    int j = 0, k = 0, check = 0, flag;
    int i = 0;
    printf("Enter your Username :");
    scanf("%s", &usr);
    printf("Enter your Password :");
    scanf("%s", &pas);
    while (i < 10)
    {
        for (int i = 0; i < 10; i++)
        {
            if (strlen(usr) == strlen(user[i].username))
            {
                for (int j = 0; j < strlen(usr); j++)
                {
                    if (usr[j] != user[i].username[j])
                    {
                        check = 1;
                        break;
                    }
                    else
                    {
                        flag = i;
                    }
                }
            }
            else
            {
                if (i < 9)
                {
                    if (check == 0)
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
        if (check == 0)
        {
            for (i = 0; i < 10; i++)
            {
                if (strlen(pas) == strlen(user[i].password))
                {
                    for (int k = 0; k < strlen(pas); k++)
                    {
                        if (pas[k] != user[i].password[k])
                        {
                            check = 1;
                            break;
                        }
                        else
                        {
                            flag = i;
                        }
                    }
                }
                else
                {
                    if (i < 9)
                    {
                        if (check == 0)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }
        if (check == 0)
        {
            return flag;
            break;
        }
        else
        {
            return -1;
        }
        i++;
    }
}
void Login()
{
    int loginAcc = Check();
    if (loginAcc == -1)
    {
        if(delete==1){
            printf("Account has been deleted");
        }
        printf("Incorrect Username or Password");
    }
    else
    {
        Display(loginAcc);
    }
    printf("\n");
}
void Edit()
{
    int editAcc = Check();
    int n;
    if (editAcc == -1)
    {
        printf("Incorrect Username or Password");
    }
    else
    {
        do
        {
            printf("\n");
            printf("Enter 1 to edit Name\n");
            printf("Enter 2 to edit DOB\n");
            printf("Enter 3 to edit username\n");
            printf("Enter 4 to edit password\n");
            printf("Enter 5 to edit email\n");
            printf("Enter 6 to edit mobile number\n");
            printf("Enter 7 to exit editing\n");
            printf("What do you want to Edit : ");
            scanf("%d", &n);
            switch (n)
            {
             case 1:
                printf("You choose to do Edit Name.\n");
                printf("Enter your New Name :");
                scanf("%s", user[editAcc].name);
                printf("Name updated succesfully ");
                break;
            case 2:
                printf("You choose to Edit DOB.\n");
                printf("Enter your New DOB :");
                scanf("%s", user[editAcc].dob);
                printf("DOB updated succesfully ");
                break;
            case 3:
                printf("You choose to Edit to Edit username.\n");
                printf("Enter your New Username :");
                scanf("%s", user[editAcc].username);
                printf("Username updated succesfully ");
                break;
            case 4:
                printf("You choose to Edit password.\n");
                printf("Enter your New password :");
                scanf("%s", user[editAcc].password);
                printf("Password updated succesfully ");
                break;
            case 5:
                printf("You choose to Edit Email-id.\n");
                printf("Enter your New Email-id :");
                scanf("%s", user[editAcc].email);
                printf("Email-Id updated succesfully ");
                break;
            case 6:
                printf("You choose to Edit Number.\n");
                printf("Enter your New number :");
                scanf("%s", user[editAcc].mobNum);
                printf("Number updated succesfully ");
                break;
            case 7:
                printf("You Sucessfully Edited your details.\n");
                break;
            default:
                printf("Enter a valid number!\n");
                break;
            }
        } while (n != 7);
    }
}
void Delete()
{
    int index = Check();
    if (index < 0 || index > 10)
    {
        printf("No deletion can be done \n");
    }
    else
    {
        for (int i = index; i < 10; i++)
        {
            user[i] = user[i + 1];
        }
        printf("\nYour Account has been deleted \n\n");
        delete =1;
    }
}