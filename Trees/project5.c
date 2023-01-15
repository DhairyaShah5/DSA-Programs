#include "project5.h"

int main()
{
    system("cls");
    int value;
    int choice;
    char ans = 'N';

    printf("--------------------Welcome to POKEDEX!!--------------------\n\n");

    do
    {
        // Sleep(1000);
        printf("\nWhat would you like to perform?");
        printf("\n1.Add a pokemon to the list");
        printf("\n2.Search for the pokemon");
        printf("\n3.Look at your pokemon collection");
        printf("\n4.Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            do
            {
                tree *new_node;
                value = (rand() % (60 - 1 + 1)) + 1;
                searchNode(root, value);
                if (isTrue != 1)
                {
                    new_node = createNode(value);
                    printf("The pokemon is found\n");
                    printf("Pokemon number is %d\n", value);
                    if (root == NULL)
                    {
                        root = new_node;
                    } /* Tree is not Created */
                    else
                    {
                        insert(root, new_node);
                    }
                    printf("\nDo you wish to find new pokemon?(Yes(Y) / No(N))\n");
                    scanf("%s", &ans);
                }
                else
                {
                    printf("The pokemon is already discovered\n");
                    isTrue = 0;
                    break;
                }
            } while (ans == 'y');
            break;

        case 2:
            if(root == NULL){
                printf("\nYou haven't found any pokemon yet!\n\n");
                break;
            }
            printf("\nEnter the Pokenum of your Pokemon you want to look up for: ");
            scanf("%d", &value);
            searchNode(root, value);
            if (flag == true)
            {
                printf("\nRequired pokemon is Found and its PokeIndex is %d\n", value);
            }
            else
            {
                printf("\nYou haven't caught that pokemon yet!!\n");
            }
            break;

        case 3:
            printf("\nHere is the list of all the Pokemons you've caught: "); //Pokemon displayed in 'inorder' fashion
            inorder(root);
            printf("\n");
        }
    } while (choice != 4);

    return 0;
}