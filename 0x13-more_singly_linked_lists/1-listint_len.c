#include "lists.h"

/**
 * listint_len - Returns the number of elements in a listint_t list.
 * @h: Pointer to the head node of the list.
 *
 * Return: The number of elements in the list.
 */
size_t listint_len(const listint_t *h)
{
    size_t x = 0;

    while (h != NULL)
    {
        h = h->next;
        x++;
    }

    return x;
}
