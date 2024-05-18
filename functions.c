#include "functions.h"
#include "main.c"

/*flags functions*/

void set_flag(int* flags, UserFlags flag) {
    *flags |= flag;
}

void clear_flag(int *flags, UserFlags flag) {
    *flags &= ~flag;
}

int is_flag_set(int flags, UserFlags flag) {
    return (flags & flag) != 0;
}

/*testing functions*/
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
    fp = fopen(filename, "a");
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

char* generate_ID() {

    //generate timestamp-based unique ID
    time_t current_time;
    time(&current_time);
    char* time_stamp=malloc(MAX_ID_LENGTH*sizeof(char));
    sprintf(time_stamp,"%ld",current_time);

    //generate a random number
    char* random_str = malloc(MAX_ID_LENGTH * sizeof(char));
    sprintf(random_str, "%d", rand() % 1000); // Adjust range as needed

    //concatenate timestamp-based unique id with the random number to create unique ID
    char* unique_id=malloc(MAX_ID_LENGTH*sizeof(char));
    strcpy(unique_id,time_stamp);
    strcat(unique_id,random_str);

    // Free allocated memory for temporary strings
    free(time_stamp);
    free(random_str);

    return unique_id;
}

void add_user(struct user* user) {
    FILE *fp = write_in_file("users.txt");
    if (fp != NULL) {
        strcpy(user->id, generate_ID());
        fprintf(fp, "%s %s %s\n",user->id, user->username, user->password);
        fflush(fp); // Flush output buffer to ensure data is written immediately
        fclose(fp); // Close the file
        send_echo("User added successfully");
    } else {
        send_echo("Failed to open file for writing");
    }
}

void displayMainMenu() {
    int login_choice;
    printf("Welcome to the bank application. How can we help you?\n");
    // Continue displaying the main menu until a valid choice is made
    do {
        printf("1: Login\n2: Create new account\n");
        scanf("%d", &login_choice);

        // Process the chosen option
        switch (login_choice) {
            case 1:
                login();
            break;
            case 2:
                signup();
            // Reload file content after creating a new account
            send_echo("Reloading file content...");
            break;
            default:
                printf("Please choose one of the options (1 or 2).\n");
            break;
        }
    } while (login_choice != 1 && login_choice != 2);
}

 char* fetch_in_file(struct user* user) {
    send_echo("autheticating");

    char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 2]; // Maximum length of a line in the file
    struct user stored_user;// user to be taken for comparison from the file

    // Open the file for readin
    //send_echo("opening flie");
    FILE* fp=read_from_file("users.txt");

    // Read each line from the file
    while (fgets(line, sizeof(line), fp)) {
        //send_echo("fetching users..");
        // Extract username, password, and ID from the line
        if (sscanf(line, "%s %s %s", &stored_user.id, stored_user.username, stored_user.password) != 3) {
            printf("Error reading user data from file!\n");
            fclose(fp);
            return "E0F"; // Authentication fails
        }

        // Compare the provided username and password with the stored username and password
        if (strcmp(user->username, stored_user.username) == 0) {
            //send_echo("user found!");
            if (strcmp(user->password, stored_user.password) == 0) {
                //send_echo("password matched!");
                fclose(fp);
                //printf("%s %s %s correct\n",stored_user.username, stored_user.password, stored_user.id);
                return stored_user.id; // Authentication succeeds
            } else {
                printf("wrong password!\n");
                fclose(fp);
                return "E0F"; // Authentication fails
            }
        }
    }

    fclose(fp);

    // If the loop completes without finding a match, authentication fails
    // If the loop completes without finding a match, authentication fails
    send_echo("user not found!");
    return "E0F";
}

char* login() {
    char *user_id;
    struct user user;
    printf("username:\n");
    scanf("%s",user.username);
    printf("password:\n");
    scanf("%s",user.password);

    user_id=fetch_in_file(&user);
    if(user_id!="E0F") {
        set_flag(&user_flags,LOG_IN_AS_USER);
        send_echo("login succed");
        return user_id;
    }
    else printf("failure login\n");
    return "E0F";
}

void signup() {
    struct user* new_user= malloc(sizeof(struct user));
    printf("type your username:\n");
    scanf("%s",new_user->username);
    printf("type your password:\n");
    scanf("%s",new_user->password);
    if(fetch_in_file(new_user)=="E0F"){
        send_echo("adding user");
        add_user(new_user);
    }
    else {
        printf("this username exists! try another one or login\n");
    }
    free(new_user);
}
