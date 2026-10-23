#include <stdio.h>
#include <stdlib.h>

/*
 * Represents a node in a singly linked list.
 * Each node stores an integer and a pointer to the next node.
 */
struct node {
    int data;
    struct node *next;
};

/* Function declarations */
void printList(struct node *head);
struct node *appendNode(struct node *head, int data);
void freeList(struct node *head);
int searchList(struct node *head, int target);
struct node *deleteNode(struct node *head, int target);

int main(void) {
    struct node *head = NULL;
    int number;

    /* Read three integers and append each one to the list. */
    for (int i = 0; i < 3; i++) {
        printf("Enter number %d: ", i + 1);

        /* Stop if the input cannot be read as an integer. */
        if (scanf("%d", &number) != 1) {
            printf("Wrong input\n");
            freeList(head);
            return 1;
        }

        head = appendNode(head, number);
    }

    /* Search for a value and report its zero-based index. */
    int target;
    printf("Enter number to search: ");

    if (scanf("%d", &target) != 1) {
        printf("Wrong input\n");
        freeList(head);
        return 1;
    }

    int result = searchList(head, target);

    if (result != -1) {
        printf("%d found at index %d\n\n", target, result);
    } else {
        printf("%d not found\n\n", target);
    }

    /* Ask the user which value should be deleted. */
    int num;
    printf("Enter number to delete from the list: ");

    if (scanf("%d", &num) != 1) {
        printf("Wrong input\n");
        freeList(head);
        return 1;
    }

    /*
     * Deleting the first node can change the head pointer,
     * so store the returned pointer back in head.
     */
    head = deleteNode(head, num);

    /* Display the list after the deletion attempt. */
    printList(head);

    /* Release all remaining nodes before exiting. */
    freeList(head);

    return 0;
}

/*
 * Print the data stored in each node, in order.
 * An empty list produces only a newline.
 */
void printList(struct node *head) {
    struct node *ptr = head;

    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

/*
 * Allocate a new node and append it to the end of the list.
 * Return the head pointer, which changes if the list is empty.
 */
struct node *appendNode(struct node *head, int data) {
    struct node *newNode = malloc(sizeof(struct node));

    /* Stop the program if memory allocation fails. */
    if (newNode == NULL) {
        printf("Not enough space\n");
        freeList(head);
        exit(EXIT_FAILURE);
    }

    /* Initialize the new node's data and next pointer. */
    newNode->data = data;
    newNode->next = NULL;

    /* The new node becomes the head if the list is empty. */
    if (head == NULL) {
        return newNode;
    }

    /* Traverse the list to find its last node. */
    struct node *ptr = head;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    /* Link the last node to the new node. */
    ptr->next = newNode;

    return head;
}

/*
 * Free every node in the list.
 * The caller's head pointer is not changed by this function.
 */
void freeList(struct node *head) {
    while (head != NULL) {
        struct node *temp = head;

        /* Save the next node before freeing the current one. */
        head = head->next;

        free(temp);
    }
}

/*
 * Search for the first occurrence of target.
 * Return its zero-based index, or -1 if it is not found.
 */
int searchList(struct node *head, int target) {
    struct node *ptr = head;
    int index = 0;

    while (ptr != NULL) {
        if (ptr->data == target) {
            return index;
        }

        ptr = ptr->next;
        index++;
    }

    return -1;
}

/*
 * Delete the first node whose data equals target.
 * Return the updated head pointer.
 * If target is absent, leave the list unchanged.
 */
struct node *deleteNode(struct node *head, int target) {
    int index = searchList(head, target);

    /* Keep the list unchanged if the target does not exist. */
    if (index == -1) {
        printf("Element not found\n");
        return head;
    }

    struct node *current = head;
    struct node *previous = NULL;

    /*
     * Handle deletion of the head separately because
     * the head pointer must advance to the next node.
     */
    if (index == 0) {
        struct node *deletedNode = head;
        head = head->next;

        printf("%d deleted from the list.\n", deletedNode->data);

        free(deletedNode);

        return head;
    }

    /* Find the target node and its predecessor. */
    for (int i = 1; i <= index; i++) {
        previous = current;
        current = current->next;
    }

    /* Unlink the target node from the list. */
    previous->next = current->next;

    /* Report the deleted value and release the node's memory. */
    printf("%d deleted from the list.\n", current->data);
    free(current);

    return head;
}
