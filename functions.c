#include "functions.h"
#include "variables.h"
#include "main.c"

void send_echo(char message[]) {
    printf("%s\n",message);
}

void displayMainMenu() {

    int login_choice;
    printf("welcome to the bank application, how can we help you?\n");
    printf("1: login\n2: create new account\n");
    scanf("%d",&login_choice);
    struct user* user;
    while (login_choice!=1||2) {
        switch (login_choice) {
            case 1:
                send_echo("signup done!");            //        signup();
            break;
            case 2:
                login();
            break;
            default:
                printf("please choose one of two options");
            break;
        }
        break;
    }
}

 int authenticate(struct user* user) {

    FILE *fp;
    char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 2]; // Maximum length of a line in the file
    struct user stored_user;// user to be taken for comparison from the file

    // Open the file for reading
    fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 0; // Authentication fails
    }
    // Read each line from the file
    while (fgets(line, sizeof(line), fp)) { //sizeof operator in fgets is used to specify the maximum number of characters to read from the file stream.

        // Extract username and password from the line
        if (sscanf(line, "%s %s", stored_user.username, stored_user.password) != 2) {
            printf("Error reading user data from file!\n");
            fclose(fp);
            return 0; // Authentication fails
        }

        // Compare the provided username and password with the stored username and password
        if (strcmp(user->username, stored_user.username) == 0) {
            if (strcmp(user->password, stored_user.password) == 0) {
                fclose(fp);
                return 1; // Authentication succeeds
            }
            else if (strcmp(user->password, stored_user.password) !=0 ) {
                printf("wrong password!");
                return 0;
            }
        }
    }

    fclose(fp);

    // If the loop completes without finding a match, authentication fails
    return 0;
}

void login() {

    FILE *fp;
    // Open the file in append mode
    fp = fopen("users.txt", "a");
    if (fp == NULL) {
        printf("Error opening file %s!\n","users");
        return;
    }

    struct user user;
    printf("username:\n");
    scanf("%s",user.username);
    printf("password:\n");
    scanf("%s",user.password);

    authenticate(&user);

}
