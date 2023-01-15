#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
# define SIZE 5 //defining a constant

struct UserEntry { //creating a new structure for storing user info
    char Name[20];
    char Priority;
    int Number[12];
};
struct UserEntry Person[SIZE]; //declaring an array of structures

int arrVip[SIZE];
int arrNom[SIZE];
int arrList[SIZE];
int ind=0;

void Check(){
    FILE *fdata; //declaring a file pointer
    fdata = fopen("Data.txt","rb"); //opening a text file to 'read binary' 
    if(fdata==NULL){ //file doesn't exist
        printf("\nError cannot open the file");
    }
    fread(Person,sizeof(struct UserEntry),SIZE,fdata);
    int j=0,k=0;
    for(int i=0;i<SIZE;i++){
        char ask = Person[i].Priority; //storing user's priority in ask
        if(ask=='V'||ask=='v'){
            arrList[j] = i; //directly enqueue VIP members
            ind++;
            j++;
        }else if (ask=='N'||ask=='n'){
            arrNom[k] = i; //store 'N' priority members in different array
            k++;
        } 
    }
    int p = ind;
    for(int i=0;i<ind+1;i++){
        arrList[p] = arrNom[i]; //to enqueue all members in a single priority queue
        p++;
    }
    fclose(fdata);
}

void Display(){
    FILE *fdata;
    fdata = fopen("Data.txt","rb"); //opening a text file to 'read binary' 
    if(fdata==NULL){
        printf("\nError cannot open the file");
    }
    fread(Person,sizeof(struct UserEntry),SIZE,fdata);
    int i=0;
    while(i<SIZE){
        printf("\nEntry of Member %d",i+1);
        printf("\nName : %s",Person[arrList[i]].Name);
        printf("\nMobile Number : %s",Person[arrList[i]].Number);
        printf("\nPriority : %c",Person[arrList[i]].Priority);
        printf("\n");
        printf("Entry done sucessfully!!!\n");
        Sleep(2000); //to delay display of next member in queue by 2sec
        i++;
    }
    fclose(fdata);
}
void DataInput(){
    FILE *fdata;
    fdata = fopen("Data.txt","wb"); //opening a text file to 'write binary' 
    if(fdata==NULL){
        printf("\nError cannot open the file");
    }
    printf("\nEnter the Details of Members ");
    for(int i=0;i<SIZE;i++){
        printf("\nEnter the Name of %d Person : ",i+1);
        scanf("%s",&Person[i].Name);//storing user's name
        printf("Enter the Mobile Number of %d Person : ",i+1);
        scanf("%s",&Person[i].Number); //storing user's phone number
        printf("Enter the priority of %d Person written on the pass (V OR N): ",i+1);
        scanf("%s",&Person[i].Priority); //stating the priority
    }
    fwrite(Person,sizeof(struct UserEntry),SIZE,fdata);
    printf("\nAll the data stored sucessfully in file");
    fclose(fdata); //closing the file 
}