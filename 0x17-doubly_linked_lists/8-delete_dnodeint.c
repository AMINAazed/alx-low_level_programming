#include <stdio.h>
#include <stdlib.h>

typedef struct dlistint_s {
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index) {
    if (head == NULL || *head == NULL)
        return -1;  // Return -1 if head is NULL or the list is empty

    dlistint_t *current = *head;

    // Traverse to the node at the given index
    for (unsigned int i = 0; i < index && current != NULL; i++)
        current = current->next;

    if (current == NULL)
        return -1;  // Return -1 if the index is out of range

    if (current->prev != NULL)
        current->prev->next = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    if (index == 0)
        *head = current->next;

    free(current);  // Free the memory of the deleted node
    return 1;       // Return 1 to indicate success
}

// Function to print the linked list (for testing purposes)
void printList(dlistint_t *head) {
    while (head != NULL) {
        printf("%d ", head->n);
        head = head->next;
    }
    printf("\n");
}

int main() {
    dlistint_t *head = NULL;

    // Add nodes to the linked list (for testing purposes)
    for (int i = 1; i <= 5; i++) {
        dlistint_t *newNode = malloc(sizeof(dlistint_t));
        newNode->n = i;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
    }

    printf("Original List: ");
    printList(head);

    // Delete node at index 2 (third node)
    int result = delete_dnodeint_at_index(&head, 2);

    if (result == 1) {
        printf("List after deletion: ");
        printList(head);
    } else {
        printf("Deletion failed.\n");
    }

    return 0;
}
