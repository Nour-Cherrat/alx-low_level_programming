#include "lists.h"
#include <stdlib.h>

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to the head node of the list.
 * @index: Index of the node (starting at 0).
 *
 * Return: The nth node, or NULL if the node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int count = 0;

    while (head != NULL)
    {
        if (count == index)
            return head;
        count++;
        head = head->next;
    }

    return NULL;
}

