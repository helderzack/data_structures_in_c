#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 20

void reverseStringWithStack(char* string, int n) {
  char stack[n];
  int top;

  for(top = 0; top < n; top++) {
    stack[top] = string[top];
  }

  top--;
  int current = 0;
  while(top >= 0) {
    string[current] = stack[top];
    current++;
    top--;
  }
}

int main() {
  char string[MAX_STRING_SIZE];
  printf("Enter a string with size less or equal to %d: ", MAX_STRING_SIZE);
  fgets(string, MAX_STRING_SIZE, stdin);
  reverseStringWithStack(string, strlen(string) - 1);
  printf("\nString: %s\n", string);
  return EXIT_SUCCESS;
}