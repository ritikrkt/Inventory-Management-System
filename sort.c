#include "inventory.h"

void sort_products(Product *head)
{
    Product *i;
    Product *j;

    int temp_id;
    int temp_quantity;
    float temp_price;
    char temp_name[50];

    if (head == NULL)
    {
        printf("\nInventory is empty!\n");
        return;
    }

    if (head->link == NULL)
    {
        printf("\nOnly one product available. No sorting required.\n");
        return;
    }

    for (i = head; i != NULL; i = i->link)
    {
        for (j = i->link; j != NULL; j = j->link)
        {
            if (i->id > j->id)
            {
                /* Swap ID */
                temp_id = i->id;
                i->id = j->id;
                j->id = temp_id;

                /* Swap Name */
                strcpy(temp_name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp_name);

                /* Swap Quantity */
                temp_quantity = i->quantity;
                i->quantity = j->quantity;
                j->quantity = temp_quantity;

                /* Swap Price */
                temp_price = i->price;
                i->price = j->price;
                j->price = temp_price;
            }
        }
    }

    printf("\nProducts sorted by ID successfully!\n");
}