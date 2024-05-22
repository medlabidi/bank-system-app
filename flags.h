#ifndef FLAG_H
#define FLAG_H

/*intialize flags*/

typedef enum {
    LOG_IN_AS_USER = 1 << 0,  // 1 in binary
    LOG_IN_AS_ADMIN = 1 << 1,  // 2 in binary
    LOG_OUT = 1 << 2            // 3 in binary
    // Other flags can be defined here
} logintypes;
int login_types=0; //initalize the login user flags
typedef enum {
    SIGNUP_DONE = 1 << 0, // 1 in binary
}signupflag;
int signup_flag=0; //initiate the signup flag


#endif /* FLAG_H */
