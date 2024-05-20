#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "flags.h"
#include "functions.h"




int main() {
    struct user* user;
    while(!is_flag_set(login_types,LOG_IN_AS_USER) && !is_flag_set(signup_flag,SIGNUP_DONE) ){
        user=displayMainMenu();
    }
    while(1) {
        DisplayUserOptionsMenu(user);
    }
}
