#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void append(struct Node **pList, int data) {
  // Make new node
  struct Node *newNode =
      malloc(sizeof(*newNode)); // allocate memory in heap the size of a newNode
  if (newNode == NULL) {
    perror("Malloc failed.");
    exit(EXIT_FAILURE);
  }

  newNode->data = data;
  newNode->next = NULL;

  // Link into list
  // Find the end of list
  if (*pList == NULL) {
    // Make this the first element
    *pList = newNode;
  } else {
    // find the end
    struct Node *curr = *pList;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
  // Add our new node
}

void printList(struct Node *list) {
  printf("The list is: ");
  struct Node *curr = list;
  while (curr != NULL) {
    printf("%d, ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

void freeList(struct Node **pList) {
  struct Node *curr = *pList;
  while (curr != NULL) {
    struct Node *next = curr->next;
    free(curr);
    curr = next;
  }

  *pList = NULL;
}

int main() {
  // Welcome!
  printf("C Linked List Demo\n");

  // Create a linked list(head)
  struct Node *head = NULL;

  // Insert some data
  append(&head, 10);
  append(&head, 20);
  append(&head, 30);
  append(&head, 40);

  // Print list
  printList(head);
  // Free memory
  freeList(&head);
}
