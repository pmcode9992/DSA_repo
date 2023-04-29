 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

  struct Node {
        char word[128], meaning[256];
        struct Node *left, *right;
  };

  struct Node *root = NULL;

  struct Node * CNode(char *word, char *meaning) {
        struct Node *newnode;
        newnode = (struct Node *)malloc(sizeof(struct Node));
        strcpy(newnode->word, word);
        strcpy(newnode->meaning, meaning);
        newnode->left = newnode->right = NULL;
        return newnode;
  }

  void insert(char *word, char *meaning) {
        struct Node *parent = NULL, *curr = NULL, *newnode = NULL;
        int res = 0;
        if (!root) {
                root = CNode(word, meaning);
                return;
        }
        for (curr = root; curr !=NULL;
           curr = (res > 0) ? curr->right : curr->left) {
                res = strcasecmp(word, curr->word);
                if (res == 0) {
                        printf("Duplicate entry!!\n");
                        return;
                }
                parent = curr;
        }
        newnode = CNode(word, meaning);
        res > 0 ? (parent->right = newnode) : (parent->left = newnode);
        return;
  }

  void delNode(char *str) {
        struct Node *parent = NULL, *curr = NULL, *temp = NULL;
        int flag = 0, res = 0;
        if (!root) {
                printf("BST is not present!!\n");
                return;
        }
        curr = root;
        while (1) {
                res = strcasecmp(curr->word, str);
                if (res == 0)
                        break;
                flag = res;
                parent = curr;
                curr = (res > 0) ? curr->left : curr->right;
                if (curr == NULL)
                        return;
        }
        if (curr->right == NULL) {
                if (curr == root && curr->left == NULL) {
                        free(curr);
                        root = NULL;
                        return;
                } else if (curr == root) {
                        root = curr->left;
                        free (curr);
                        return;
                }

                flag > 0 ? (parent->left = curr->left) :
                                (parent->right = curr->left);
        } else {
                temp = curr->right;
                if (!temp->left) {
                        temp->left = curr->left;
                        if (curr == root) {
                                root = temp;
                                free(curr);
                                return;
                        }
                        flag > 0 ? (parent->left = temp) :
                                        (parent->right = temp);
                } else {
                        struct Node *successor = NULL;
                        while (1) {
                                successor = temp->left;
                                if (!successor->left)
                                        break;
                                temp = successor;
                        }
                        temp->left = successor->right;
                        successor->left = curr->left;
                        successor->right = curr->right;
                        if (curr == root) {
                                root = successor;
                                free(curr);
                                return;
                        }
                        (flag > 0) ? (parent->left = successor) :
                                        (parent->right = successor);
                }
        }
        free (curr);
        return;
  }

  void Search(char *str) {
        struct Node *temp = NULL;
        int flag = 0, res = 0;
        if (root == NULL) {
                printf("Binary Search Tree is out of station!!\n");
                return;
        }
        temp = root;
        while (temp) {
                if ((res = strcasecmp(temp->word, str)) == 0) {
                        printf("Word   : %s", str);
                        printf("Meaning: %s", temp->meaning);
                        flag = 1;
                        break;
                }
                temp = (res > 0) ? temp->left : temp->right;
        }
        if (!flag)
                printf("Search Element not found in Binary Search Tree\n");
        return;
  }

  void IOTraversal(struct Node *myNode) {
        if (myNode) {
                IOTraversal(myNode->left);
                printf("Word    : %s", myNode->word);
                printf("Meaning : %s", myNode->meaning);
                printf("\n");
                IOTraversal(myNode->right);
        }
        return;
  }

  int main() {
        int ch;
        char str[128], meaning[256];
        while (1) {
                printf("\n1. Insertion\t2. Deletion\n");
                printf("3. Searching\t4. Traversal\n");
                printf("5. Exit\nEnter ur choice:");
                scanf("%d", &ch);
                getchar();
                switch (ch) {
                        case 1:
                                printf("Word to insert:");
                                fgets(str, 100, stdin);
                                printf("Meaning:");
                                fgets(meaning, 256, stdin);
                                insert(str, meaning);
                                break;
                        case 2:
                                printf("Enter the word to delete:");
                                fgets(str, 100, stdin);
                                delNode(str);
                                break;
                        case 3:
                                printf("Enter the search word:");
                                fgets(str, 100, stdin);
                                Search(str);
                                break;
                        case 4:
                                IOTraversal(root);
                                break;
                        case 5:
                                exit(0);
                        default:
                                printf("You have entered wrong option\n");
                                break;
                }
        }
        return 0;
  }