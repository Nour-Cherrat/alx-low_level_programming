#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Pointer to the head node of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *slow = *h, *fast = *h, *temp;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        /* verifier le cycle */
        if (slow == fast)
        {
            /* Déplacer Slow au départ et avancer les deux pointeurs jusqu'à ce qu'ils se rencontrent à nouveau. */
            slow = *h;
            while (slow != fast)
            {
                count++;
                temp = fast;
                fast = fast->next;
                free(temp);
            }

            /* Avancer les deux pointeurs pour libérer les nœuds à l'intérieur du cycle */
            do
            {
                count++;
                temp = fast->next;
                free(fast);
                fast = temp;
            } while (slow != fast);

            /* Mettre head à NULL pour indiquer que la liste est libérée */
            *h = NULL;
            return count;
        }
    }

    /* Libérer les nœuds après le contrôle du cycle */
    while (*h != NULL)
    {
        count++;
        temp = *h;
        *h = (*h)->next;
        free(temp);
    }

    return count;
}

