#include "inventory.h"

void update_product(Product *head)
{
    int id;
    Product *temp;

    if (head == NULL)
    {
        printf("\nInventory is empty!\n");
        return;
    }

    printf("\nEnter Product ID to update: ");
    scanf("%d", &id);

    temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("\nProduct Found!\n");

            printf("Enter new Product Name: ");
            scanf(" %49[^\n]", temp->name);

            printf("Enter new Quantity: ");
            scanf("%d", &temp->quantity);

            printf("Enter new Price: ");
            scanf("%f", &temp->price);

            printf("\nProduct updated successfully!\n");

            return;
        }

        temp = temp->link;
    }

    printf("\nProduct with ID %d not found!\n", id);
}