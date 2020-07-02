#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#include "../prompt.h"
#include "../config.h"

char *home, *homeless_cwd;

char *get_home() {
#if PWD_SEGMENT_ENV
  return get_env("HOME");
#else
  struct passwd *pw = getpwuid(getuid());
  return strdup(pw->pw_dir);
#endif
}

void pwd_enter() {
  char *substr;
  int index, diff;

  // get the home directory
  home = get_home();
  substr = strstr(prompt_cwd, home);
  if (substr == NULL) {
    // outside of a home directory, just print the directory entirely
    printf("%s ", prompt_cwd);
    return;
  }
  index = (int) (strchr(home, *(substr+strlen(substr)))- home);

  diff = strlen(prompt_cwd) - strlen(home) + 1;
  homeless_cwd = malloc(diff); 
  strncpy(homeless_cwd, prompt_cwd+index, diff);

  printf("~%s ", homeless_cwd);
}

void pwd_leave() {
  if(home != NULL)
    free(home);
  
  if(homeless_cwd != NULL)
    free(homeless_cwd);
}
