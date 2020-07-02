#pragma once

#define DEBUG 1 // toggle debug logging

// by default we get the CWD from the PWD environment variable
// but we can also get it from the process' properties with getcwd(3)
#define CWD_FROM_PWD 1 

#define LN_BEFORE 1 // add a new line before each prompt

/* * * * * * * * * * * * * */
//         COLORS 
/* * * * * * * * * * * * * */
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

/* * * * * * * * * * * * * */
//        SEGMENTS
/* * * * * * * * * * * * * */
#define PWD_SEGMENT 1 // display the current folder you're in (PWD) 
#define PWD_SEGMENT_ENV 0 // try to use the $HOME variable by default or fallback to getpwuid 
#define PWD_SEGMENT_COLOR BLU // the color for the path segment 

#define GIT_SEGMENT 1 // display the git segment, as configured below 
#define GIT_SEGMENT_BRANCH 1 // display the branch name on the git segment 

#define DURATION_SEGMENT 1 // display the previous command duration segment 
#define DURATION_SEGMENT_THRESHOLD 1000 // threshold after which we display the duration 
#define DURATION_SEGMENT_COLOR YEL // the color for the duration time value 

#define USER_SEGMENT 1 // display the git segment for the users defined below
#define USER_SEGMENT_USERS "root,admin" // display the users for which to show the user segment; SEPARATED BY A COMMA
#define USER_SEGMENT_COLOR RED // the color for the username inside this segment

#define LN_SEGMENT 1 // go to a new line before the status segment 

#define STATUS_SEGMENT 1 // display the status segment exit code != 0 -> red : green 
