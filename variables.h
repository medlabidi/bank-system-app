#ifndef USER_H
#define USER_H

#define MAX_USERNAME_LENGTH     20
#define MAX_PASSWORD_LENGTH     20
#define MAX_LINE_LENGTH         256
#define MAX_ID_LENGTH           10

struct user {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char id[MAX_ID_LENGTH];
};

#endif /* USER_H */
