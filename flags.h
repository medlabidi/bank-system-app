#ifndef FLAG_H
#define FLAG_H

/*intialize flags*/

typedef enum {
    LOG_IN_AS_USER = 1 << 0,  // 1 in binary
    LOG_IN_AS_ADMIN = 1 << 1,  // 2 in binary
    // Other flags can be defined here
} logintypes;
int login_types=0; //initalize the user flags



#endif /* FLAG_H */
