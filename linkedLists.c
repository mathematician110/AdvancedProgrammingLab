#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *create() {
    struct node * const head = malloc(sizeof(struct node));
    head->next = NULL;
    return head;
}

void append(struct node * const head, int data) {
    struct node *current, *new;
    for (current = head; current->next != NULL; current = current->next) {}
    new = malloc(sizeof(struct node));
    new->value = data;
    new->next = NULL;
    current->next = new;
}

void pop(struct node * const head) {
    struct node *previous;
    for (previous = head; previous->next != NULL; previous = previous->next) {
        if (previous->next->next == NULL)
            break; // This would cause the loop to terminate right before the last node
    }
    if (previous == head) {
        printf("%s\n", "List is empty!");
        return;
    }
    free(previous->next);
    previous->next = NULL;
}

void insert(struct node * const head, int index, int value) {
    struct node *previous = head, *new;
    int i;
    for (i = 0; i < index; i++) {
        if (previous->next == NULL) {
            printf("%s\n", "Index is out of range.");
            return;
        }
        previous = previous->next;
    }
    new = malloc(sizeof(struct node));
    new->value = value;
    new->next = previous->next;
    previous->next = new;
}

void delete(struct node * const head, int index) { // It seems there's already a function named remove in the libraries so I had t use delete as the name
    if (head->next == NULL) {
        printf("%s\n", "List is empty.");
        return;
    }
    struct node *previous = head, *toBeFreed;
    int i;
    for (i = 0; i < index; i++) {
        if (previous->next == NULL) {
            printf("%s\n", "Index is out of range.");
            return;
        }
        previous = previous->next;
    }
    if (previous->next == NULL) {
        printf("%s\n", "Index is out of range.");
        return;
    }
    toBeFreed = previous->next;
    previous->next = previous->next->next;
    free(toBeFreed);
}

int search(struct node * const head, int value) {
    if (head->next == NULL) {
        printf("%s\n", "List is empty.");
        return -1;
    }
    struct node *current;
    int index = 0;
    for (current = head->next; current != NULL; current = current->next) {
        if (current->value == value)
            return index;
        index++;
    }
    return -1;
}

int main() {
    struct node * const head = create();
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    pop(head);
    insert(head, 0, 0);
    delete(head, 2);
    printf("Found 3 at %d.\n", search(head, 3));
    return 0;
}