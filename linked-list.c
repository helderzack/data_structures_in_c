#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node* next;
};

struct Node* head = NULL;
int counter = 0;

void reverseLinkedList() {
  if (head == NULL) {
    printf("There are no elements in the linked list\n");
    return;
  }

  struct Node* current = head;
  struct Node* previous = NULL;
  struct Node* next;

  while(current != NULL) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  head = previous;
}

void printLinkedListRecursively(struct Node* navigator) {
  if (navigator == NULL) return;
  printf("%d ", navigator->value);
  printLinkedListRecursively(navigator->next);
}

void printReversedLinkedListRecursively(struct Node* navigator) {
  if (navigator == NULL) return;
  printReversedLinkedListRecursively(navigator->next);
  printf("%d ", navigator->value);
}

void pushElementAtTheBeginningOfTheList(int value) {
  struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->value = value;
  newNode->next = head;
  head = newNode;
}

void pushElementInTheMiddleOfTheList(int position, int value) {
  int i;

  struct Node* navigator = head;

  for(i = 1; i < position - 1; i++) {
    navigator = navigator->next;
  }

  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 
  newNode->value = value;
  newNode->next = navigator->next;
  navigator->next = newNode;
}

void pushElementAtTheEndOfTheList(int value) {
  struct Node* navigator = head;

  while(navigator->next != NULL) {
    navigator = navigator->next;
  }

  struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->value = value;
  newNode->next = NULL;
  navigator->next = newNode;
}

void showAvailablePositions(int variable) {
  printf("Available positions:\n");
  int i;

  for(i = 1; i <= counter + variable; i++) {
    printf("Position %d\n", i);
  }
}

void insertElement() {
  int value;
  int position;

  printf("What's the value you want to add?\n");
  scanf("%d", &value);

  if (counter == 0) {
    head = (struct Node*) malloc (sizeof(struct Node));
    head->value = value;
    head->next = NULL;
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

  if (position == 1) {
    pushElementAtTheBeginningOfTheList(value);
    counter++;
    return;
  }

  if (position > counter) {
    pushElementAtTheEndOfTheList(value);
    counter++;
    return;
  }

  pushElementInTheMiddleOfTheList(position, value);

  counter++;
}

void removeElementAtTheBeginningOfTheList() {
  struct Node* firstElement = head;

  if (counter == 1) {
    head = NULL;
  } else {
    head = head->next;
  }

  free(firstElement);
}

void removeElementInTheMiddleOfTheList(int position) {
  struct Node* navigator = head;

  int i;

  for(i = 1; i < position - 1; i++) {
    navigator = navigator->next;
  }

  struct Node* removedNode = navigator->next;
  navigator->next = removedNode->next;
  free(removedNode);
}

void removeElementAtTheEndOfTheList() {
  struct Node* lastElement = head;
  struct Node* previous = NULL;

  while(lastElement->next != NULL) {
    previous = lastElement;
    lastElement = lastElement->next;
  }

  free(lastElement);
  previous->next = NULL;
}

void removeElement() {
  if (counter == 0) {
    printf("There are no elements to remove!\n");
    return;
  }

  if(counter == 1) {
    removeElementAtTheBeginningOfTheList();
    return;
  }

  int position;

  printf("Choose the position of the element you want to remove:\n");
  showAvailablePositions(0);
  
  scanf("%d", &position);

  if (position < 1 || position > counter) {
    printf("Invalid position!\n");
    return;
  }

  if (position == 1) {
    removeElementAtTheBeginningOfTheList();
    counter--;
    return;
  }

  if (position == counter) {
    removeElementAtTheEndOfTheList();
    counter--;
    return;
  }

  removeElementInTheMiddleOfTheList(position);
  counter--;
}

void freeUsedMemoryFromLinkedList() {
  if(head == NULL) {
    return;
  }
  struct Node* navigator = head;

  while(navigator->next != NULL) {
    struct Node* current = navigator;
    navigator = navigator->next;
    free(current);
  }

  free(navigator);
  printf("All cleared\n");
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
        removeElement();
        break;
      case 5:
        reverseLinkedList();
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

  freeUsedMemoryFromLinkedList();

  return EXIT_SUCCESS;
}