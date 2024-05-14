#include "functions.h"
#include "variables.h"
#include "main.c"

void send_echo(char message[]) {
    printf("%s\n",message);
}

void testing_fetch() {
    /* this function is used to test fetch_in_file function by dynamically
       allocating a variable of type"user" and assigning its content
       with existing data in the fil and implement the fetch process */
    struct user *test = malloc(sizeof(struct user));
    if (test == NULL) {
        printf("Memory allocation failed!\n");
    }

    strcpy(test->username, "a"); // Copy "a" into username
    strcpy(test->password, "b"); // Copy "b" into password

    fetch_in_file(test);

    free(test); // Free allocated memory
}


FILE* write_in_file(const char* filename){
    FILE *fp;
    //open file in write mode
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return NULL; // Return NULL if file opening fails
    }
    return fp;
}

FILE* read_from_file(const char* filename) { //the parameter is declared as const char* to represent a string.
    FILE *fp;

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return NULL; // Return NULL if file opening fails

    }
    // Check if the file is empty
    if (fgetc(fp) == EOF) {
        printf("File is empty!\n");
        return NULL; // Return NULL if file opening fails
    }
    rewind(fp); // Reset file pointer to the beginning just after opening the file and checking if it's empty.
    return fp;
}

void add_user(struct user* user) {
    FILE *fp=write_in_file("users.txt");
    fprintf(fp,"%s %s\n",user->username,user->password);
}

void displayMainMenu() {

    int login_choice;
    printf("welcome to the bank application, how can we help you?\n");
    printf("1: login\n2: create new account\n");
    scanf("%d",&login_choice);
   // struct user* user;
    while (login_choice!=1||2) {
        switch (login_choice) {
            case 1:
                login();
                send_echo("login done!");
            break;
            case 2:
                signup();
                send_echo("signup done!");
                ;
            break;
            default:
                printf("please choose one of two options");
            break;
        }
        break;
        login_choice=0;
    }
}

 int fetch_in_file(struct user* user) {
    send_echo("autheticating");

    char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 2]; // Maximum length of a line in the file
    struct user stored_user;// user to be taken for comparison from the file

    // Open the file for readin
    send_echo("opening flie");
    FILE* fp=read_from_file("users.txt");

    // Read each line from the file
    while (fgets(line, sizeof(line), fp)) { //sizeof operator in fgets is used to specify the maximum number of characters to read from the file stream.
        send_echo("fetching users..");
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
                send_echo("user found!");
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

    struct user user;
    printf("username:\n");
    scanf("%s",user.username);
    printf("password:\n");
    scanf("%s",user.password);

    if(fetch_in_file(&user)==1) {
        send_echo("login succed");
    }
    else printf("failure login");

}

void signup() {
    struct user* new_user= malloc(sizeof(struct user));
    printf("type your username:\n");
    scanf("%s",new_user->username);
    printf("type your password:\n");
    scanf("%s",new_user->password);
    if(fetch_in_file(new_user)==0){
        send_echo("adding user");
        add_user(new_user);
    }
    else {
        printf("this username exists! try another one or login\n");
    }
    free(new_user);
}
