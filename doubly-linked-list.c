#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* previous;
  struct Node* next;
};

struct Node* head = NULL;
int counter = 0;

void printLinkedListRecursively(struct Node* current) {
  if (current == NULL) return;
  printf("%d ", current->data);
  printLinkedListRecursively(current->next);
}

void printReversedLinkedListRecursively(struct Node* current) {
  if (current == NULL) return;
  printLinkedListRecursively(current->next);
  printf("%d ", current->data);
}

void showAvailablePositions(int variable) {
  printf("Available positions:\n");

  int i;
  for(i = 1; i <= counter + variable; i++) {
    printf("Position %d\n", i);
  }
}

void pushElement(int position, int data) {
  struct Node* current = head;
  struct Node* previous = NULL;

  int i;

  for(i = 1; i < position; i++) {
    previous = current;
    current = current->next;
  }

  struct Node* newNode = (struct Node *) malloc(sizeof(struct Node));
  newNode->data = data;

  newNode->previous = previous;
  newNode->next = current;

  if (previous != NULL) {
    previous->next = newNode;
  } else {
    head = newNode;
  }
  current->previous = newNode;
}

void pushElementAtTheEnd(int data) {
  struct Node* current = head;

  while(current->next != NULL) {
    current = current->next;
  }

  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  current->next = newNode;
  newNode->previous = current;
  newNode->next = NULL;
}

void insertElement() {
  int data;
  int position;

  printf("What's the value you want to add?\n");
  scanf("%d", &data);

  if (head == NULL) {
    head = (struct Node*) malloc (sizeof(struct Node));
    head->data = data;
    head->next = NULL;
    head->previous = NULL;
    counter++;
    return;
  }

  printf("Choose the position of the new element!\n");
  showAvailablePositions(1);

  scanf("%d", &position);

  if (position < 1 || position > counter + 1) {
    printf("Invalid position!\n");
    return;
  }

  if (position > counter) {
    pushElementAtTheEnd(data);
    counter++;
    return;
  }

  pushElement(position, data);

  counter++;
}

void freeAllocatedMemoryToList() {
  if (head == NULL) {
    return;
  }

  struct Node* current = head;

  while(head->next != NULL) {
    head = head->next;
    free(current);
    current = head;
  }

  free(head);
}

void menu() {
  printf("1 - Print Elements\n");
  printf("2 - Prints Elements in Reverse\n");
  printf("3 - Insert Element\n");
  printf("4 - Remove Element\n");
  printf("5 - Reverse Linked List\n");
  printf("99 - EXIT!!!\n");
}

int main() {
  int flag = 1;

  while(flag == 1) {
    menu();

    int option;
    scanf("%d", &option);

    switch(option) {
      case 1:
        printLinkedListRecursively(head);
        break;
      case 2:
        printReversedLinkedListRecursively(head);
        break;
      case 3:
        insertElement();
        break;
      case 4:
        // removeElement();
        break;
      case 5:
        // struct Node* previous = NULL;
        // reverseLinkedListRecursively(head, previous);
        break;
      case 99:
        flag = 0;
        break;
      default:
        printf("This option is not available!\n");
        break;
    }

    printf("\n");
  }

  freeAllocatedMemoryToList();

  return EXIT_SUCCESS;
}