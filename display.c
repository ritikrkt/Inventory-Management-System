#include "inventory.h"

void display_products(Product *head)
{
    Product *temp;

    if (head == NULL)
    {
        printf("\nInventory is empty!\n");
        return;
    }

    temp = head;

    printf("\n====================================================\n");
    printf("                 INVENTORY DETAILS\n");
    printf("====================================================\n");
    printf("%-10s %-20s %-10s %-10s\n",
           "ID", "Product", "Quantity", "Price");
    printf("----------------------------------------------------\n");

    while (temp != NULL)
    {
        printf("%-10d %-20s %-10d %-10.2f\n",
               temp->id,
               temp->name,
               temp->quantity,
               temp->price);

        temp = temp->link;
    }

    printf("====================================================\n");
}