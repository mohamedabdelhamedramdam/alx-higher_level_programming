#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer to the head of the list
 *
 * Return: 0 if not a palindrome, 1 if a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *prev = NULL, *tmp;

    /* empty list or single node list is a palindrome */
    if (*head == NULL || (*head)->next == NULL)
        return (1);

    /* find the middle node of the list */
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        tmp = slow;
        slow = slow->next;
        tmp->next = prev;
        prev = tmp;
    }

    /* if the list has odd number of nodes, skip the middle node */
    if (fast != NULL)
        slow = slow->next;

    /* compare the first half of the list with the reversed second half */
    while (slow != NULL && prev != NULL)
    {
        if (slow->n != prev->n)
            return (0);
        slow = slow->next;
        prev = prev->next;
    }

    return (1);
}
