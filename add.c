#include "inventory.h"

void add_product(Product **head)
{
    Product *new_product;
    Product *temp;
    int id;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    /* Check for duplicate ID */
    temp = *head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("Product ID %d already exists!\n", id);
            return;
        }

        temp = temp->link;
    }

    new_product = (Product *)malloc(sizeof(Product));

    if (new_product == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    new_product->id = id;

    printf("Enter Product Name: ");
    scanf(" %49[^\n]", new_product->name);

    printf("Enter Quantity: ");
    scanf("%d", &new_product->quantity);

    printf("Enter Price: ");
    scanf("%f", &new_product->price);

    new_product->link = NULL;

    if (*head == NULL)
    {
        *head = new_product;
    }
    else
    {
        temp = *head;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = new_product;
    }

    printf("Product added successfully!\n");
}