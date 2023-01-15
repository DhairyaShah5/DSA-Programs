#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<windows.h>

struct Student
{
    int rollnumber;
    char name[100];
    char course[100];
    int marks;
    struct Student *next;
    
}* head;

int count = 0;
void insert(int rollnumber, char* name, char* course, float marks){
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->rollnumber = rollnumber;
    strcpy(student->name, name);
    strcpy(student->course, course);
    student->marks = marks;
    student->next = NULL;
    
    if(head==NULL){
        // if head is NULL
        // set student as the new head
        head = student;
    }
    else{
        // if list is not empty
        // insert student in beginning of head
        student->next = head;
        head = student;
    }
    count++;
}
void search(int rollnumber){
    struct Student * temp = head;
    printf("Searching for roll number %d is found and details are as follows:\n\n",rollnumber);
    while(temp!=NULL){
        if(temp->rollnumber==rollnumber){
            printf("Roll Number: %d\n", temp->rollnumber);
            printf("Name: %s\n", temp->name);
            printf("Course: %s\n", temp->course);
            printf("Marks: %d\n", temp->marks);
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}
void Delete(int rollnumber){
    struct Student * temp1 = head;
    struct Student * temp2 = head; 
    while(temp1!=NULL){
        if(temp1->rollnumber==rollnumber){
            printf("Record with roll number %d Found !!!\n", rollnumber);
            if(temp1==temp2){
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1); 
            }
            printf("Record Successfully Deleted !!!\n");
            return; 
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}
void display(){
    struct Student * temp = head;
    int i = count;
    printf("The Student details are as follows:\n\n");
    while(temp!=NULL){
        Sleep(3000);
        printf("Student %d:\n", i);
        printf("Roll Number: %d\n", temp->rollnumber);
        printf("Name: %s\n", temp->name);
        printf("course: %s\n", temp->course);
        printf("Marks: %d\n\n", temp->marks);
        temp = temp->next; 
        i--;
    }
}