#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct node
{
    int data;
    struct node *next;
};
void read_graph(struct node *adj_list[], int no_of_vertices);
void print_graph(struct node *adj_list[], int no_of_vertices);\

int main()
{
    system("cls");
    printf("\t\t\t\t\t*******Foodex*******\n");
    printf("\t\t\t\t\tThe Restaurant Finders\n");
    printf("\nEnter the sector numbers and let us find the best nearest restaurant for you!!\n\n");
    int i, j, k, nodes;
    printf("Enter the number of sectors in the city: ");
    scanf("%d", &nodes);
    struct node *adj_list[nodes];
    for (i = 1; i <= nodes; i++)
    {
        adj_list[i] = NULL;
    }
    read_graph(adj_list, nodes);
    printf("\nList of Restaurants nearest to the entered sectors are : \n");
    print_graph(adj_list, nodes);
    return 0;
}

void read_graph(struct node *adj_list[], int no_of_vertices)
{
    int i, j, k, no_of_edges, v1, v2;
    struct node *new_node;
    printf("Enter the number of ways: ");
    scanf("%d", &no_of_edges);
    for (i = 0; i < no_of_edges; i++)
    {
        printf("Enter the sectors for road %d: ", i + 1);
        scanf("%d %d", &v1, &v2);
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = v2;
        new_node->next = adj_list[v1];
        adj_list[v1] = new_node;
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = v1;
        new_node->next = adj_list[v2];
        adj_list[v2] = new_node;
    }
}

void print_graph(struct node *adj_list[], int no_of_vertices)
{
    int i;
    struct node *ptr;
    for (i = 1; i <= no_of_vertices; i++)
    {
        printf("Restaurant nearest to the sector %d are: ", i);
        ptr = adj_list[i];
        while (ptr != NULL)
        {
            int choice = ptr->data;
            switch (choice)
            {
            case 1:
                printf(" Burger King ");
                break;
            case 2:
                printf(" McDonalds ");
                break;
            case 3:
                printf(" KFC ");
                break;
            case 4:
                printf(" Pizza Hut ");
                break;
            case 5:
                printf(" Dominos ");
                break;

            default:
                break;
            }
            ptr = ptr->next;
        }
        printf("\n\n");
        Sleep(1000);
    }
}