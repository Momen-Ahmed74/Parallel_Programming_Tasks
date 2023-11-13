#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef enum {
    ACTIVATED_USER,
    NOT_ACTIVATED_USER
} UserType;

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    bool flag[0];
    UserType userType;
} User;

User users[MAX_USERS];
int numUsers = 0;

typedef union {
    bool activatedUserFlag;
    bool notActivatedUserFlag;
} UserFlag;

void signUp() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    User newUser;
	UserFlag userFlag;
    printf("Enter username: ");
    scanf("%s", newUser.username);

    printf("Enter password: ");
    scanf("%s", newUser.password);
    
	printf("Enter flag (0/1): ");
    scanf("%s", newUser.flag);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists. Please choose a different username.\n");
            return;
        }
    }

    newUser.userType = ACTIVATED_USER;
    users[numUsers] = newUser;
    numUsers++;

    printf("Sign-up successful!\n");
}

void login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    bool flag[0];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            UserFlag userFlag;
            userFlag.activatedUserFlag = 1;

            switch (users[i].userType) {
                case ACTIVATED_USER:
                    userFlag.activatedUserFlag = 1;
                    printf("Activated user login successful!\n");
                    break;
                case NOT_ACTIVATED_USER:
                    printf("Not activated user login successful!\n");
                    break;
            }

            return;
        }
    }

    printf("Invalid username or password.\n");
}

int main() {
    int choice;

    while (1) {
        printf("1. Sign up\n");
        printf("2. Login\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signUp();
                break;
            case 2:
                login();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}
