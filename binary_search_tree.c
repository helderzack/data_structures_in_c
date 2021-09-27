#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* leftChild;
  struct Node* rightChild;
};

void inOrderTraversal(struct Node* current) {
  if (current == NULL) return;
  inOrderTraversal(current->leftChild);
  printf("%d ", current->data);
  inOrderTraversal(current->rightChild);
}

void insertNode(struct Node** current, int data) {
  if((*current) == NULL) {
    (*current) = (struct Node*) malloc(sizeof(struct Node));
    (*current)->data = data;
    (*current)->leftChild = NULL;
    (*current)->rightChild = NULL;
    return;
  }
  if(data >= (*current)->data) {
    insertNode(&(*current)->rightChild, data);
  } else {
    insertNode(&(*current)->leftChild, data);
  };
}

void removeNode() {

}

void freeAllocatedMemoryForTree() {
  
}

void menu() {
  printf("1 - In Order Traversal\n");
  printf("2 - Insert Node\n");
  printf("3 - Remove Node\n");
  printf("99 - EXIT!!!\n");
}

int main() {
  struct Node* root =  NULL;
  int flag = 1;

  while(flag == 1) {
    menu();

    int option;
    scanf("%d", &option);

    switch(option) {
      case 1:
        inOrderTraversal(root);
        break;
      case 2:
        int data;
        printf("Enter the value you want to add to the tree: ");
        scanf("%d", &data);
        insertNode(&root, data);
        break;
      case 3:
        removeNode();
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

  // freeAllocatedMemoryForTree();

  return EXIT_SUCCESS;
}