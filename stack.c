#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node *head = NULL;
struct Node* tail = NULL;

void printStack(struct Node* current) {
  if(current == NULL) return;
  printf("%d ", current->data);
  printStack(current->next);
}

void push() {
  int data;
  printf("What's the value you want to add?\n");
  scanf("%d", &data);

  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if(head == NULL) {
    head = newNode;
    tail = head;
    return;
  }

  tail->next = newNode;
  tail = tail->next;
}

void pop() {
  if (head == NULL) return;

  struct Node* current = head;
  struct Node* previous = NULL;

  while(current->next != NULL) {
    previous = current;
    current = current->next;
  }

  free(current);
  if (previous == NULL) {
    head = NULL;
    tail = NULL;
    return;
  }

  previous->next = NULL;
  tail = previous;
}

void menu() {
  printf("1 - Print Elements\n");
  printf("2 - Push Element\n");
  printf("3 - Pop Element\n");
  printf("99 - EXIT!!!\n");
}

void freeAllocatedMemoryForStack() {
  if(head == NULL) return;
  struct Node *current = head;

  while(current->next != NULL) {
    struct Node* temp = current;
    current = current->next;
    free(temp);
  }

  free(current);
}

int main() {
  int flag = 1;

  while(flag == 1) {
    menu();

    int option;
    scanf("%d", &option);

    switch(option) {
      case 1:
        printStack(head);
        break;
      case 2:
        push();
        break;
      case 3:
        pop();
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

  freeAllocatedMemoryForStack();

  return EXIT_SUCCESS;
}