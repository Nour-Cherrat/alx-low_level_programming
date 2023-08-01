#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - Deletes the node at a given index in the list.
 * @head: Pointer to a pointer to the head node of the list.
 * @index: Index of the node that should be deleted.
 *
 * Return: 1 if the deletion succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *temp, *prev = NULL;
    unsigned int count = 0;

    if (head == NULL || *head == NULL)
        return -1;

    temp = *head;
    while (temp != NULL)
    {
        if (count == index)
        {
            if (prev != NULL)
                prev->next = temp->next;
            else
                *head = temp->next;
            free(temp);
            return 1;
        }
        count++;
        prev = temp;
        temp = temp->next;
    }

    return -1;
}

