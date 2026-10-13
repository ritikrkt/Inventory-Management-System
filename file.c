#include "inventory.h"

void save_database(Product *head)
{
    FILE *fp;
    Product *temp;

    fp = fopen("inventory.dat", "wb");

    if (fp == NULL)
    {
        printf("\nUnable to open database file!\n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        fwrite(temp, sizeof(Product), 1, fp);
        temp = temp->link;
    }

    fclose(fp);

    printf("\nDatabase saved successfully!\n");
}

void load_database(Product **head)
{
    FILE *fp;
    Product *new_product;
    Product *temp;

    fp = fopen("inventory.dat", "rb");

    if (fp == NULL)
    {
        return;
    }

    while (1)
    {
        new_product = (Product *)malloc(sizeof(Product));

        if (new_product == NULL)
        {
            printf("Memory allocation failed!\n");
            fclose(fp);
            return;
        }

        if (fread(new_product, sizeof(Product), 1, fp) != 1)
        {
            free(new_product);
            break;
        }

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
    }

    fclose(fp);

    printf("Database loaded successfully!\n");
}