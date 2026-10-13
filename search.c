#include "inventory.h"

void search_product(Product *head)
{
    int id;
    Product *temp;

    if (head == NULL)
    {
        printf("\nInventory is empty!\n");
        return;
    }

    printf("\nEnter Product ID to search: ");
    scanf("%d", &id);

    temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("\nProduct Found!\n");
            printf("-----------------------------\n");
            printf("ID       : %d\n", temp->id);
            printf("Name     : %s\n", temp->name);
            printf("Quantity : %d\n", temp->quantity);
            printf("Price    : %.2f\n", temp->price);
            printf("-----------------------------\n");

            return;
        }

        temp = temp->link;
    }

    printf("\nProduct with ID %d not found!\n", id);
}