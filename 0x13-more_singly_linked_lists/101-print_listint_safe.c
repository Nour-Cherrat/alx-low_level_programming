#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head node of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0;
    const listint_t *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        count++;
        slow = slow->next;
        fast = fast->next->next;

        /* Vérifier la présence d'un cycle dans la liste */
        if (slow == fast)
        {
            /* Déplacez Slow jusqu'au départ et faites avancer les deux pointeurs jusqu'à ce qu'ils se rencontrent à nouveau. */
            slow = head;
            while (slow != fast)
            {
                printf("[%p] %d\n", (void *)slow, slow->n);
                count++;
                slow = slow->next;
                fast = fast->next;
            }

            /* Imprimer les nœuds restants du cycle */
            printf("[%p] %d\n", (void *)slow, slow->n);
            count++;

            /* Exit */
            exit(98);
        }
    }

    /* imprimer les nœuds restants après le contrôle du cycle */
    while (slow != NULL)
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        count++;
        slow = slow->next;
    }

    return count;
}

