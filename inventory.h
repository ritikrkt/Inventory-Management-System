#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product
{
    int id;
    char name[50];
    int quantity;
    float price;
    struct Product *link;
} Product;

/* Function Prototypes */

void add_product(Product **head);
void display_products(Product *head);
void search_product(Product *head);
void update_product(Product *head);
void delete_product(Product **head);
void sort_products(Product *head);
void save_database(Product *head);
void load_database(Product **head);

#endif