#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Inserts a new node at a given position in the list.
 * @head: Pointer to a pointer to the head node of the list.
 * @idx: Index of the list where the new node should be added.
 * @n: Value of the new node to be added.
 *
 * Return: The address of the new node, or NULL if it failed.
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node, *temp = *head;
    unsigned int count = 0;

    if (head == NULL)
        return NULL;

    /* insert at start */
    if (idx == 0)
    {
        new_node = malloc(sizeof(listint_t));
        if (new_node == NULL)
            return NULL;

        new_node->n = n;
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    /* insert in the middle */
    while (temp != NULL)
    {
        if (count == idx - 1)
        {
            new_node = malloc(sizeof(listint_t));
            if (new_node == NULL)
                return NULL;

            new_node->n = n;
            new_node->next = temp->next;
            temp->next = new_node;
            return new_node;
        }
        count++;
        temp = temp->next;
    }

    /* if it does not exist */
    return NULL;
}

