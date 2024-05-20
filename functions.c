#include "functions.h"
#include "main.c"

/* Flags functions */

void set_flag(int* flags, logintypes flag) {
    *flags |= flag;
}

void clear_flag(int *flags, logintypes flag) {
    *flags &= ~flag;
}

int is_flag_set(int flags, logintypes flag) {
    return (flags & flag) != 0;
}

/* Testing functions */

void send_echo(char message[]) {
    printf("%s\n", message);
}

/*void testing_fetch() {
    struct user *test = malloc(sizeof(struct user));
    if (test == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(test->username, "a");
    strcpy(test->password, "b");

    fetch_in_file(test);

    free(test);
}*/

FILE* write_in_file(const char* filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return NULL;
    }
    return fp;
}

FILE* read_from_file(const char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return NULL;
    }
    if (fgetc(fp) == EOF) {
        printf("File is empty!\n");
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    return fp;
}

char* generate_ID() {
    time_t current_time;
    time(&current_time);
    char* time_stamp = malloc(MAX_ID_LENGTH * sizeof(char));
    sprintf(time_stamp, "%ld", current_time);

    char* random_str = malloc(MAX_ID_LENGTH * sizeof(char));
    sprintf(random_str, "%d", rand() % 1000);

    char* unique_id = malloc(MAX_ID_LENGTH * sizeof(char));
    strcpy(unique_id, time_stamp);
    strcat(unique_id, random_str);

    free(time_stamp);
    free(random_str);

    return unique_id;
}

void add_user(struct user* user) {
    FILE *fp = write_in_file("users.txt");
    if (fp != NULL) {
        strcpy(user->id, generate_ID());
        user->balance=0;
        fprintf(fp, "%s %s %s %d\n", user->id, user->username, user->password, user->balance);
        fflush(fp);
        fclose(fp);
    } else {
        send_echo("Failed to open file for writing");
    }
}

struct user* displayMainMenu() {
    int login_choice;
    struct user *user=NULL;
    printf("Welcome to the bank application. How can we help you?\n");
    do {
        printf("1: Login\n2: Create new account\n");
        scanf("%d", &login_choice);

        switch (login_choice) {
            case 1:
                user=login();
                break;
            case 2:
                user=signup();
                send_echo("Reloading file content...");
                break;
            default:
                printf("Please choose one of the options (1 or 2).\n");
                break;
        }
    } while (login_choice != 1 && login_choice != 2);
    return user;
}

void DisplayUserOptionsMenu(struct user* user) {
    int user_options_choice;
    printf("Welcome to the user panel! How can we help you?\n");
    do {
        printf("1: Check balance\n2: Transfer money\n3: Deposit\n4: Withdraw\n5: Logout\n");
        scanf("%d", &user_options_choice);

        switch (user_options_choice) {
            case 1:
                send_echo("Check balance");
                CheckBalance(user);
                break;
            case 2:
                send_echo("Transfer money");
                break;
            case 3:
                send_echo("Deposit");
                break;
            case 4:
                send_echo("Withdraw");
                break;
            case 5:
                send_echo("Logout");
                break;
            default:
                printf("Please choose one of the options.\n");
                break;
        }
    } while (user_options_choice != 5);
}

void CheckBalance(struct user* user) {
    printf("your cash balance is %d\n",user->balance);
}

struct user* fetch_in_file(struct user* user) {
    char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 50];
    struct user *stored_user = malloc(sizeof(struct user));
    if (stored_user == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    FILE* fp = read_from_file("users.txt");
    if (fp == NULL) {
        free(stored_user);
        return NULL;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%s %s %s %d", stored_user->id, stored_user->username, stored_user->password, &(stored_user->balance)) != 4) {
            printf("Error reading user data from file!\n");
            fclose(fp);
            free(stored_user);
            return NULL;
        }

        if (strcmp(user->username, stored_user->username) == 0) {
            if (strcmp(user->password, stored_user->password) == 0) {
                fclose(fp);
                return stored_user;
            } else {
                printf("Wrong password!\n");
                fclose(fp);
                free(stored_user);
                return NULL;
            }
        }
    }

    fclose(fp);
    send_echo("User not found!");
    free(stored_user);
    return NULL;
}

struct user* login() {
    struct user *user;
    struct user loginuser;
    printf("Username:\n");
    scanf("%s", loginuser.username);
    printf("Password:\n");
    scanf("%s", loginuser.password);

    user = fetch_in_file(&loginuser);
    if (user != NULL) {
        set_flag(&login_types, LOG_IN_AS_USER);
        send_echo("Login succeeded");
        return user;
    }
    printf("Login failed\n");
    return NULL;
}

struct user* signup() {
    struct user* new_user = malloc(sizeof(struct user));
    printf("Type your username:\n");
    scanf("%s", new_user->username);
    printf("Type your password:\n");
    scanf("%s", new_user->password);
    if (fetch_in_file(new_user) == NULL) {
        add_user(new_user);
        set_flag(&signup_flag, SIGNUP_DONE);
        return new_user;
    }
    else {
        printf("This username exists! Try another one or login.\n");
    }
    //free(new_user);
}
