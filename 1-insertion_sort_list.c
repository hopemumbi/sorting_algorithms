#include "sort.h"
/**
 * swap - Swap two nodes in a listint_t doubly-linked list
 *
 * @h: A pointer to the head of the doubly linked list
 * @n1: A pointer to the first node to swap
 * @n2: A pointer to the seceond node
 */
void swap(listint_t **h, listint_t *n1, listint_t *n2)
{
	/* If n1 has a previous node*/
	if (n1->prev != NULL)
		/* Update the next point of n1's prev node to n2*/
		n1->prev->next = n2;
	else
		*h = n2;
	/* If n2 has a next node */
	if (n2->next != NULL)
		/* Update the prev pointer of n2's prev node to n1*/
		n2->next->prev = n1;

	/*Update the next pointer of n1 to n2's next pointer*/
	n1->next = n2->next;

	/*Update the prev pointer of n2 to n1's prev pointer*/
	n2->prev = n1->prev;

	n2->next = n1; /*Update next poiter of n2 to n1*/
	n1->prev = n2; /*Update prev pointer of n1 to n2*/
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order.
 *
 * @list: A doubly linked list of integers.
 * print_list - prints the list.
 */
void insertion_sort_list(listint_t **list)
{
	/**
	 * current - points to the current node being compared
	 * temp - a temporaty variable to store the next node of current
	 * previous - points to the node before the current node
	 */
	listint_t *current, *temp, *previous;

	if (list == NULL || *list == NULL)
		return;

	/*Start the loop from the second node*/
	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;

		previous = current->prev;
		/*Keep looping if current-n is less than previous-n */
		while (previous != NULL && current->n < previous->n)
		{
			swap(list, previous, current);
			print_list((const listint_t *)*list);
			previous = current->prev;
		}
	}
}
