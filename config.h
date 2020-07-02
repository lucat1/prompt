#pragma once

#define DEBUG 1 // toggle debug logging

// by default we get the CWD from the PWD environment variable
// but we can also get it from the process' properties with getcwd(3)
#define CWD_FROM_PWD 1 

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
#define PWD_SEGMENT_COLOR BLU // try to use the $HOME variable by default or fallback to getpwuid 

#define GIT_SEGMENT 1 // display the git secment, as configured below 
#define GIT_SEGMENT_BRANCH 1 // display the branch name on the git segment 

#define LN_SEGMENT 1 // go to a new line before the status segment 

#define STATUS_SEGMENT 1 // display the status segment exit code != 0 -> red : green 
