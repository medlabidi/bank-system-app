#ifndef USER_H
#define USER_H

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_LINE_LENGTH 256

struct user {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

#endif /* USER_H */
