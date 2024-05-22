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
                //send_echo("Reloading file content...");
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
                //send_echo("Check balance");
                CheckBalance(user);
                break;
            case 2:
                //send_echo("Transfer money");
                TransferMoney(user);
                break;
            case 3:
                //send_echo("Deposit");
                deposit(user);
                break;
            case 4:
                //send_echo("Withdraw");
                withdraw(user);
                break;
            case 5:
                send_echo("Logout");
                logout(user);
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

void deposit(struct user* user) {
    int amount;
    printf("enter the amount you want to deposit:\n");
    scanf("%d",&amount);
    FILE* fp=fopen("users.txt","r");
    //send_echo("user file opened");
    if(fp==NULL) {
        printf("error openig file!");
        return;
    }

    char line[MAX_LINE_LENGTH];
    char temp_filename[]="temp_users.txt";
    FILE* temp_fp=fopen(temp_filename,"w");
    //send_echo("temp file created");
    if (temp_fp == NULL) {
        printf("Error opening temporary file!\n");
        fclose(fp);
        return;
    }
    struct user* stored_user=malloc(sizeof(struct user));
    if (stored_user == NULL) {
        printf("Memory allocation failed!\n");
        fclose(fp);
        fclose(temp_fp);
        return;
    }

    int found= 0;
    while (fgets(line,sizeof(line),fp)) {
        //send_echo("fetching users");
        if(sscanf(line, "%19s %49s %49s %d", stored_user->id, stored_user->username, stored_user->password, &stored_user->balance) != 4) {
            fprintf(temp_fp, "%s", line);
            continue;
        }
        if(strcmp(stored_user->id,user->id)==0) {
            //send_echo("user found");
            found= 1;
            stored_user->balance+=amount;
            // Update the user's balance in the passed user struct
            user->balance = stored_user->balance;
        }

        // Ensure the ID, username, and password are null-terminated
        stored_user->id[MAX_ID_LENGTH - 1] = '\0';
        stored_user->username[MAX_USERNAME_LENGTH - 1] = '\0';
        stored_user->password[MAX_PASSWORD_LENGTH - 1] = '\0';

        fprintf(temp_fp, "%s %s %s %d\n", stored_user->id, stored_user->username, stored_user->password, stored_user->balance);
        //send_echo("user balance updated");
    }
    fclose(fp);
    fclose(temp_fp);
    if(found==1) {
        remove("users.txt");
        rename(temp_filename,"users.txt");
        send_echo("deposit done successfully.\n");
    }
    else {
        remove(temp_filename);
        send_echo("user not found!");
    }
    free(stored_user);
}

void withdraw(struct user* user) {
    int amount;
    printf("enter the amount you want to withdraw:\n");
    scanf("%d",&amount);
    FILE* fp=fopen("users.txt","r");
    //send_echo("user file opened");
    if(fp==NULL) {
        printf("error openig file!");
        return;
    }

    char line[MAX_LINE_LENGTH];
    char temp_filename[]="temp_users.txt";
    FILE* temp_fp=fopen(temp_filename,"w");
    //send_echo("temp file created");
    if (temp_fp == NULL) {
        printf("Error opening temporary file!\n");
        fclose(fp);
        return;
    }
    struct user* stored_user=malloc(sizeof(struct user));
    if (stored_user == NULL) {
        printf("Memory allocation failed!\n");
        fclose(fp);
        fclose(temp_fp);
        return;
    }

    int found= 0;
    while (fgets(line,sizeof(line),fp)) {
        //send_echo("fetching users");
        if(sscanf(line, "%19s %49s %49s %d", stored_user->id, stored_user->username, stored_user->password, &stored_user->balance) != 4) {
            fprintf(temp_fp, "%s", line);
            continue;
        }
        if(strcmp(stored_user->id,user->id)==0) {
            //send_echo("user found");
            found= 1;
            stored_user->balance-=amount;
            // Update the user's balance in the passed user struct
            user->balance = stored_user->balance;
        }

        // Ensure the ID, username, and password are null-terminated
        stored_user->id[MAX_ID_LENGTH - 1] = '\0';
        stored_user->username[MAX_USERNAME_LENGTH - 1] = '\0';
        stored_user->password[MAX_PASSWORD_LENGTH - 1] = '\0';

        fprintf(temp_fp, "%s %s %s %d\n", stored_user->id, stored_user->username, stored_user->password, stored_user->balance);
        //send_echo("user balance updated");
    }
    fclose(fp);
    fclose(temp_fp);
    if(found==1) {
        remove("users.txt");
        rename(temp_filename,"users.txt");
        send_echo("withdraw done.\n");
    }
    else {
        remove(temp_filename);
        send_echo("user not found!");
    }
    free(stored_user);
}

void TransferMoney(struct user* sender) {
    int amount=0;
    struct user receiver;
    char line[MAX_LINE_LENGTH];
    int sender_found=0, receiver_found=0;

    FILE* fp=fopen("users.txt", "r");
    //send_echo("user file opened");
    if(fp==NULL) {
        printf("error openig file!");
        return;
    }

    char temp_filename[]="temp_users.txt";
    FILE* temp_fp=fopen(temp_filename,"w");
    if(temp_fp==NULL) {
        printf("error openeing temporary users file!");
        return;
    }

    struct user* stored_user=malloc(sizeof(struct user));
    if (stored_user == NULL) {
        printf("Memory allocation failed!\n");
        fclose(fp);
        fclose(temp_fp);
        return;
    }

    printf("select the user you want to send:\n");
    scanf("%s",receiver.username);
    while(amount<=0){
        printf("select the amount you want to send:\n");
        scanf("%d",&amount);
        if(amount<0) {
            printf("invalid, please choose positive number.\n");
        }
    }

    while(fgets(line,sizeof(line),fp)) {
        //send_echo("fetching users..\n");
        if(sscanf(line, "%19s %49s %49s %d", stored_user->id, stored_user->username, stored_user->password, &stored_user->balance) != 4) {
            fprintf(temp_fp, "%s", line);
            continue;
        }
        //send_echo("User fetched. Checking conditions...\n");

        if(strcmp(stored_user->username,sender->username)==0) {
            if(stored_user->balance < amount) {
                printf("unsefficient balance! try again.\n");
                fclose(fp);
                fclose(temp_fp);
                free(stored_user);
                remove(temp_filename);
                return;
            }
            stored_user->balance-=amount;
            sender->balance=stored_user->balance;
            sender_found=1;
        }

        if(strcmp(stored_user->username,receiver.username)==0) {
            stored_user->balance+=amount;
            receiver_found=1;
        }
        // Ensure the ID, username, and password are null-terminated
        stored_user->id[MAX_ID_LENGTH - 1] = '\0';
        stored_user->username[MAX_USERNAME_LENGTH - 1] = '\0';
        stored_user->password[MAX_PASSWORD_LENGTH - 1] = '\0';

        fprintf(temp_fp, "%s %s %s %d\n", stored_user->id, stored_user->username, stored_user->password, stored_user->balance);
        //send_echo("user balance updated");
    }
    fclose(fp);
    fclose(temp_fp);
    free(stored_user);

    if(sender_found&&receiver_found) {
        remove("users.txt");
        rename(temp_filename,"users.txt");
        printf("trnasfer completed successfully!\n");
    }
    else {
        if (!sender_found) {
            printf("sender not found!\n");
        }
        if (!receiver_found) {
            printf("receiver not found!\n");
        }
        remove(temp_filename);
    }
}

void logout(struct user* user) {
    if(user!=NULL) {
        free(user);
    }
    clear_flag(&login_types,LOG_IN_AS_USER);
    set_flag(&login_types,LOG_OUT);
}

struct user* fetch_in_file(struct user* user) {
    char line[MAX_LINE_LENGTH];
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

    // Ensure the ID, username, and password are null-terminated
    stored_user->id[MAX_ID_LENGTH - 1] = '\0';
    stored_user->username[MAX_USERNAME_LENGTH - 1] = '\0';
    stored_user->password[MAX_PASSWORD_LENGTH - 1] = '\0';

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
    printf("This username exists! Try another one or login.\n");

    //free(new_user);
}
