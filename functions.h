#ifndef FUNCTION_H
#define FUNCTION_H
#include "variables.h"
#include <stdio.h>

FILE* write_in_file(const char* filename);
FILE* read_from_file(const char* filename);

//generate a unique ID based on the current timestamp and a random number.
char* generate_ID();

void add_user();

void testing_fetch();

/*When the program starts, it displays a main menu with two options: "Login" and "Signup".*/
void displayMainMenu();

char* login();
void signup();

/* Authenticate the user's login attempt by comparing
 the entered username and password with the data stored in the file.*/
char* fetch_in_file(struct user* user);

/*testing steps by printing a message in choice*/
void send_echo(char message[]);




#endif /*FUNCTION_H*/