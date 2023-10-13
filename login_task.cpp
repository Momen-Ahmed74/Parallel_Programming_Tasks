#include <stdio.h>
#include <string.h>

#define USERS_NUMBER 50
#define MAX_LETTERS_OF_USER 30
#define MAX_LETTERS_OF_PASSWORD 20

typedef struct {
	char username[MAX_LETTERS_OF_USER];
	char password[MAX_LETTERS_OF_PASSWORD];
} User;

User users[USERS_NUMBER] = {
    {"Tom", "1234"},
    {"Tomas", "5678"},
    {"Darin", "91011"},
};

int main() {

    char username[MAX_LETTERS_OF_USER];
    char password[MAX_LETTERS_OF_PASSWORD];
    int isCertificatedUser = 0;

    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    for (int i = 0; i < USERS_NUMBER; i++) {
	    if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
		    isCertificatedUser = 1;
		    break;
    	}
    }

    if (isCertificatedUser) {
    	printf("Certificated user.\n");
    } 
	else {
    	printf("Uncertificated user.\n");
    }

}
