#ifndef FUNCTION_H
#define FUNCTION_H
#include "variables.h"


/*When the program starts, it displays a main menu with two options: "Login" and "Signup".*/
void displayMainMenu();

void login();
void signup();

/* Authenticate the user's login attempt by comparing
 the entered username and password with the data stored in the file.*/
int authenticate(struct user* user);

/*testing steps by printing a message in choice*/
void send_echo(char message[]);




#endif /*FUNCTION_H*/