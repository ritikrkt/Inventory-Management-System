#include <stdio.h>
#include "inventory.h"

int main()
{
    Product *head = NULL;
    int choice;

    load_database(&head);

    while (1)
    {
        printf("\n========== INVENTORY MANAGEMENT ==========\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Sort Products\n");
        printf("7. Save Database\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_product(&head);
                break;

            case 2:
                display_products(head);
                break;

            case 3:
                search_product(head);
                break;

            case 4:
                update_product(head);
                break;

            case 5:
                delete_product(&head);
                break;

            case 6:
                sort_products(head);
                break;

            case 7:
                save_database(head);
                break;

            case 8:
                printf("Exiting Inventory Management System...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}