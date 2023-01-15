#include "project4.h"

int main()
{

    system("cls");

    head = NULL;
    int choice;
    char name[50];
    char course[50];
    int rollnumber;
    int marks;
    while (choice != 5)
    {
        printf("\n\n1 to insert student details\n2 to search for student details\n3 to delete student details\n4 to display student details\n5 to exit\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter roll number: ");
            scanf("%d", &rollnumber);
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter Course: ");
            scanf("%s", course);
            printf("Enter marks: ");
            scanf("%d", &marks);
            insert(rollnumber, name, course, marks);
            break;
        case 2:
            printf("Enter roll number to search: ");
            scanf("%d", &rollnumber);
            search(rollnumber);
            break;
        case 3:
            printf("Enter roll number to delete: ");
            scanf("%d", &rollnumber);
            Delete(rollnumber);
            break;
        case 4:
            display();
            break;
        }
    }
}