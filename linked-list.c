#include <stdio.h>
#include <stdlib.h>

struct slnode {
    int val;
    struct slnode * next;
} node;

node * head = NULL;
head = malloc(sizeof(node));
head->val = 1;
head->next = malloc(sizeof(node));
head->next->val = 2;
head->next->next = NULL;

void print_list(node * head) {
    node * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}
void push_to_end(node * head, int val) {
    node * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(node));
    current->next->val = val;
    current->next->next = NULL;
}

void push_to_start(node ** head, int val) {
    node * new_node;
    new_node = malloc(sizeof(node));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}
int pop_start(node ** head) {
    int retval = -1;
    node * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}
int pop_end(node * head) {
    int retval = 0;
    if (head->next == NULL) {
        head->val
        free(head);
        head = NULL;
        return retval;
    }
    node * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
}

int pop_at_spec(node ** head, int n) {
    int i = 0;
    int retval = -1;
    node * current = *head;
    node * temp_node = NULL;

    if (n == 0) {
        return pop(head);
    }

    for (int i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;

}
