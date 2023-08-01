#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Pointer to the head node of the list.
 *
 * Return: The address of the node where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        /* Vérifier si Slow et Fast se rejoignent pour détecter un cycle */
        if (slow == fast)
        {
            /* Déplacer Slow vers le head et avancer les deux pointeurs jusqu'à ce qu'ils se rencontrent à nouveau. */
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; /* slow et fast seront au nœud de départ de la boucle */
        }
    }

    /* No cycle=> return NULL */
    return NULL;
}

