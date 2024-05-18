#ifndef FLAG_H
#define FLAG_H
#include "variables.h"

/*intialize flags*/

typedef enum {
    LOG_IN_AS_USER = 1 << 0,  // 1 in binary
    // Other flags can be defined here
} UserFlags;
int user_flags=0; //initalize the user flags



#endif /* FLAG_H */
