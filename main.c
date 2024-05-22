#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "flags.h"
#include "functions.h"




int main() {

    struct user* user;
    do{
        while(!is_flag_set(login_types,LOG_IN_AS_USER) && !is_flag_set(signup_flag,SIGNUP_DONE) ){
            user=displayMainMenu();
            // Clear the LOG_OUT flag to re-enter the menu loop
            clear_flag(&login_types, LOG_OUT);
        }
        if (user!=NULL) {
            DisplayUserOptionsMenu(user);
        }
    } while(1);
    return 0;
}
