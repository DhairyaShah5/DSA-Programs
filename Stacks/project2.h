#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h> //used to assign random price of items 
#include<time.h> //used for printing time
int item;
int Main_Stack[100];
int top=-1;
int ask;
int a,b,o,k,p;

struct Item{ //creating a structure to store item details
    int Id[5];
    int price;
    int quantity;
}; 
struct Item c[10];//declaring array of structures of size 10

void askItem();
void InvoiceGenrator();
void SetItem();
void push(int item);
int pop();

int pushItem(int item){
    if(top==100-1){ //if there is an element on top of stack then stack is full
        printf("Stack is full");
        return 0;
    }
    Main_Stack[++top]=item; //incrementing and pushing item in stack
}
int popItem(void){
    if(top==-1){ //if top's value has not been increased, no item has been pushed so stack is empty
        printf("Stack is Empty"); 
        return 0;
    }
    item = Main_Stack[top--]; //decrementing top after popping item
    return item;
}
void SetItem(){
    for(int i=1;i<6;i++){
        c[i].price = (rand() % (100 - 10 + 1)) + 10; //setting 2 digit price of item as randomly generated by system 
    }
}
void askItem(){
    SetItem();
    printf("You have selected Item %d\n",ask); //printing user's choice

    for(int i=0;i<5;i++){
        c[ask].Id[i]=ask;
        pushItem(c[ask].Id[i]);
    }
    printf("Enter the quantity you would like to buy : ");
    scanf("%d",&c[ask].quantity); //storing quantity entered by user in structure
    switch (ask)
    {
    case 1: //printing user's selections
        printf("You have selected to buy apples of price %dRs\n",c[ask].price);
        printf("Quantity of apples bought is %d\n",c[ask].quantity);
        a=1;
        break;
    case 2:
        printf("You have selected to buy bananas of price %dRs\n",c[ask].price);
        printf("Quantity of bananas bought is %d\n",c[ask].quantity);
        b=1;
        break;
    case 3:
        printf("You have selected to buy oranges of price %dRs\n",c[ask].price);
        printf("Quantity of oranges bought is %d\n",c[ask].quantity);
        o=1;
        break;
    case 4:
        printf("You have selected to buy kiwis of price %dRs\n",c[ask].price);
        printf("Quantity of kiwis bought is %d\n",c[ask].quantity);
        k=1;
        break;
    case 5:
        printf("You have selected to buy pineapples of price %dRs\n",c[ask].price);
        printf("Quantity of pineapples bought is %d\n",c[ask].quantity);
        p=1;
        break;
    default:
        break;
    }
}
void InvoiceGenerator(){
    system("cls");
    struct bill{ //creating structure for bill
        int time;
    };
    time_t t;
    time(&t);
    int Totalbill = 0; //initializing total bill
    for(int i=1;i<=5;i++){
        Totalbill += (c[i].price)*(c[i].quantity); //calculating final amount by multiplying quantity and price of items bought
    }
    float CGST,SGST;
    CGST = (2.5*Totalbill)/100;
    SGST = (2.5*Totalbill)/100;
    printf("\n\n");
    printf("+-------------------------------------------------------------------------+\n");
    printf("|                              YOUR BILL                             \n");
    printf("+-------------------------------------------------------------------------+\n");
    printf("Time: %s", ctime(&t)); //to print the time and date when program was run
    printf("+-------------------------------------------------------------------------+\n");
    printf("| Name                         | Quantity        | Price        | Cost      \n");
    printf("+-------------------------------------------------------------------------+\n");
    //to print the items in the bill only if they are bought multiple if's are used
    if(a==1){
        printf("| Apple                        | %d               | %d           | %d            \n",c[1].quantity,c[1].price,(c[1].price)*(c[1].quantity));
    }
    if(b==1){
        printf("| Banana                       | %d               | %d           | %d            \n",c[2].quantity,c[2].price,(c[2].price)*(c[2].quantity));
    }
    if(o==1){
        printf("| Oranges                      | %d               | %d           | %d            \n",c[3].quantity,c[3].price,(c[3].price)*(c[3].quantity));
    }
    if(k==1){
        printf("| Kiwis                        | %d               | %d           | %d            \n",c[4].quantity,c[4].price,(c[4].price)*(c[4].quantity));
    }
    if(p==1){
        printf("| Pineapples                   | %d               | %d           | %d            \n",c[5].quantity,c[5].price,(c[5].price)*(c[5].quantity));
    }
    printf("+-------------------------------------------------------------------------+\n");
    printf("|                                               TOTAL BILL:     | %d       \n",Totalbill);
    printf("|                                               SGST:           | %.2f       \n",SGST);
    printf("|                                               CGST:           | %.2f       \n",CGST);
    printf("|                                               FINAL COST:     | %.2f       \n",(Totalbill + CGST + SGST)); //printing the final amount
    printf("+-------------------------------------------------------------------------+\n");
}