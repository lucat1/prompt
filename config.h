#pragma once

#define DEBUG 1 // toggle debug logging

// by default we get the CWD from the PWD environment variable
// but we can also get it from the process' properties with getcwd(3)
#define CWD_FROM_PWD 1 

/* * * * * * * * * * * * * */
//        SEGMENTS
/* * * * * * * * * * * * * */
#define PWD_SEGMENT 1 // display the current folder you're in (PWD) 

#define PWD_DEFAULT_ENV 1 // try to use the $HOME variable by default or fallback to getpwuid 


#define GIT_SEGMENT 1 // display the git secment, as configured below 

#define GIT_SEGMENT_BRANCH 1 // display the branch name on the git segment 


