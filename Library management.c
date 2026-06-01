#include <stdio.h>

struct Book {
    int id;
    char title[50];
    int issued;
};

int main() {
    struct Book books[100];
    int count = 0;
    int choice, searchId;
    int i;

    while (1) {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &books[count].id);

                printf("Enter Book Title: ");
                scanf("%s", books[count].title);

                books[count].issued = 0;
                count++;

                printf("Book Added Successfully!\n");
                break;

            case 2:
                for(i = 0; i < count; i++) {
                    printf("\nID: %d", books[i].id);
                    printf("\nTitle: %s", books[i].title);
                    printf("\nStatus: %s\n",
                           books[i].issued ? "Issued" : "Available");
                }
                break;

            case 3:
                printf("Enter Book ID: ");
                scanf("%d", &searchId);

                for(i = 0; i < count; i++) {
                    if(books[i].id == searchId) {
                        printf("Book Found: %s\n", books[i].title);
                    }
                }
                break;

            case 4:
                printf("Enter Book ID: ");
                scanf("%d", &searchId);

                for(i = 0; i < count; i++) {
                    if(books[i].id == searchId) {
                        books[i].issued = 1;
                        printf("Book Issued!\n");
                    }
                }
                break;

            case 5:
                printf("Enter Book ID: ");
                scanf("%d", &searchId);

                for(i = 0; i < count; i++) {
                    if(books[i].id == searchId) {
                        books[i].issued = 0;
                        printf("Book Returned!\n");
                    }
                }
                break;

            case 6:
                return 0;
        }
    }
}