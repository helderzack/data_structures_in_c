#include <stdio.h>
#include <stdlib.h>

void printStack(int stack[], int top) {
  for (int i = 0; i <= top; i++) {
    printf("%d ", stack[i]);
  }
}

void push(int *array, int n, int *top) {
  if ((*top) == n - 1) {
    printf("There is no more space in the stack!");
    return;
  }
  int data;
  printf("What's the value you want to add?\n");
  scanf("%d", &data);

  (*top)++;
  array[(*top)] = data;
}

void pop(int* top) {
  if((*top) == -1) return;
  (*top)--;
}

void menu() {
  printf("1 - Print Elements\n");
  printf("2 - Push Element\n");
  printf("3 - Pop Element\n");
  printf("99 - EXIT!!!\n");
}

int main() {
  int n;
  printf("Type the size of the stack: ");
  scanf("%d", &n);

  int stack[n];
  int top = -1;
  int flag = 1;

  while(flag == 1) {
    menu();

    int option;
    scanf("%d", &option);

    switch(option) {
      case 1:
        printStack(stack, top);
        break;
      case 2:
        push(stack, n, &top);
        break;
      case 3:
        pop(&top);
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

  return EXIT_SUCCESS;
}