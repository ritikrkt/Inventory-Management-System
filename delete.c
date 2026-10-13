#include "inventory.h"

void delete_product(Product **head)
{
    int id;
    Product *temp;
    Product *prev;

    if (*head == NULL)
    {
        printf("\nInventory is empty!\n");
        return;
    }

    printf("\nEnter Product ID to delete: ");
    scanf("%d", &id);

    temp = *head;
    prev = NULL;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            /* If first node is to be deleted */
            if (prev == NULL)
            {
                *head = temp->link;
            }
            else
            {
                prev->link = temp->link;
            }

            free(temp);

            printf("\nProduct deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->link;
    }

    printf("\nProduct with ID %d not found!\n", id);
}