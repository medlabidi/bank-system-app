#ifndef FUNCTION_H
#define FUNCTION_H
#include "variables.h"
#include "flags.h"
#include <stdio.h>
#include <time.h>

/*testing functions declarations*/

/* Authenticate the user's login attempt by comparing
 the entered username and password with the data stored in the file.*/
char* fetch_in_file(struct user* user);
void send_echo(char message[]);

FILE* write_in_file(const char* filename);
FILE* read_from_file(const char* filename);

/*flags functions declarations*/

void set_flag(int *flags, logintypes flag);
void clear_flag(int *flags, logintypes flag);
int is_flag_set(int flags, logintypes flag);

//generate a unique ID based on the current timestamp and a random number.
char* generate_ID();

void add_user();
/*testing functions declarations*/

void testing_fetch();

/*When the program starts, it displays a main menu with two options: "Login" and "Signup".*/
void displayMainMenu();

char* login();
void signup();

#endif /*FUNCTION_H*/