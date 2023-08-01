#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: Pointer to a pointer to the head node of the list.
 *
 * Return: The head node's data (n), or 0 if the linked list is empty.
 */
int pop_listint(listint_t **head)
{
    int x;
    listint_t *temp;

    if (head == NULL || *head == NULL)
        return 0;

    x = (*head)->n;
    temp = *head;
    *head = (*head)->next;
    free(temp);

    return x;
}

