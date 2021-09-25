#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void printQueue(struct Node* current) {
  if(current == NULL) return;
  printf("%d ", current->data);
  printQueue(current->next);
}

void enqueue(struct Node** head) {
  int data;
  printf("What's the value you want to add?\n");
  scanf("%d", &data);

  if ((*head) == NULL) {
    (*head) = (struct Node*) malloc(sizeof(struct Node));
    (*head)->data = data;
    (*head)->next = NULL;
    return;
  };

  struct Node* current = (*head);

  while(current->next != NULL) {
    current = current->next;
  }

  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  current->next = newNode;
  newNode->next = NULL;
}

void dequeue(struct Node** head) {
  if((*head) == NULL) return;
  struct Node* deletedNode = *head;
  *head = (*head)->next;
  free(deletedNode);
}

void freeAllocatedMemoryForQueue(struct Node** head) {
  if((*head) == NULL) return;
  struct Node *current = (*head);

  while(current->next != NULL) {
    struct Node* temp = current;
    current = current->next;
    free(temp);
  }

  free(current);
}

void menu() {
  printf("1 - Print Queue\n");
  printf("2 - Enqueue\n");
  printf("3 - Dequeue\n");
  printf("99 - EXIT!!!\n");
}

int main() {
  struct Node* head = NULL;

  int flag = 1;

  while(flag == 1) {
    menu();

    int option;
    scanf("%d", &option);

    switch(option) {
      case 1:
        printQueue(head);
        break;
      case 2:
        enqueue(&head);
        break;
      case 3:
        dequeue(&head);
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

  freeAllocatedMemoryForQueue(&head);

  return EXIT_SUCCESS;
}