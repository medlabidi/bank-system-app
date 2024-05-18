#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "flags.h"
#include "functions.h"




int main() {

    while(is_flag_set(login_types,LOG_IN_AS_USER)==0){
        displayMainMenu();
    }
    return 0;
}
