#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
};
struct Node* current = NULL;
struct Node* createNode(char* url) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void openPage(char* url) {
    struct Node* newNode = createNode(url);
    if (current != NULL) {
        struct Node* temp = current->next;
        while (temp != NULL) {
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        current->next = newNode;
        newNode->prev = current;
    }
    current = newNode;
    printf("Opened: %s\n", current->url);
}

// Go back
void goBack() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Back to: %s\n", current->url);
    } else {
        printf("No previous page!\n");
    }
}

// Go forward
void goForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Forward to: %s\n", current->url);
    } else {
        printf("No forward page!\n");
    }
}

// Display current page
void displayCurrent() {
    if (current != NULL) {
        printf("Current page: %s\n", current->url);
    } else {
        printf("No page opened!\n");
    }
}

// Main function
int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\n--- Browser Menu ---\n");
        printf("1. Open New Page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Current Page\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                openPage(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayCurrent();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
