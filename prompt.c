#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <unistd.h>

#include "config.h"
#include "prompt.h"

#if PWD_SEGMENT
#include "modules/pwd.h"
#endif

#if GIT_SEGMENT
#include "modules/git.h"
#endif

#if GIT_SEGMENT
#include "modules/status.h"
#endif

char *prompt_cwd;

void leave() {
  // free any memory from modules
#if PWD_SEGMENT
  pwd_leave();
#endif
#if GIT_SEGMENT
  git_leave();
#endif
#if STATUS_SEGMENT
  status_leave();
#endif

  // free memory if these pointers are assigned
  if(prompt_cwd != NULL)
    free(prompt_cwd);
}

void fail(const char *message, ...) {
#if DEBUG
  printf("fatal: ");

  va_list args;
  va_start(args, message);
  vprintf(message, args);
  va_end(args);

  printf("\n");
#else
  // print a default simple prompt in production
  printf("$ ");
#endif

  // free the used memory
  leave();
  exit(1);
}

char *get_env(char *key) {
  char *res = NULL;
  const char *tmp = getenv(key);
  if(tmp == NULL)
    fail("could not get $%s enviroment variable", key);

  // make a copy of the global shared variable 
  // for the use in this tool
  res = strdup(tmp);
  if(res == NULL)
    fail("could not copy $%s environment variable into memory", key);

  return res;
}

#if CWD_FROM_PWD
void get_cwd() {
  prompt_cwd = get_env("PWD");
}
#else
void get_cwd() {
  long path_max;
  size_t size;
  char *ptr;

  path_max = pathconf(".", _PC_PATH_MAX);
  if (path_max == -1)
    size = 1024;
  else if (path_max > 10240)
    size = 10240;
  else
    size = path_max;

  for (prompt_cwd = ptr = NULL; ptr == NULL; size *= 2) {
    if ((prompt_cwd = realloc(prompt_cwd, size)) == NULL) {
      fail("could not realloc memory to get cwd (SYSCALL)");
    }

    ptr = getcwd(prompt_cwd, size);
    if (ptr == NULL && errno != ERANGE) {
      fail("insufficient permissions to get cwd (SYSCALL)");
    }
  }
}
#endif

int get_env_int(char *key) {
  char *endptr, *tmp;
  int res;

  tmp= get_env(key);
  errno = 0;
  res = strtol(tmp, &endptr, 10);

  if(errno == ERANGE || (errno != 0 && res == 0))
    fail("could not parse $%s enviroment variable, value: %s", key, tmp);

  if (endptr == tmp)
    fail("couldn't find an interger in the $%s variable, value: %s", key, tmp);

  // if everything went well we can discard the raw value
  free(tmp);
  return res;
}

int main() {
  // initialize variables used in all modules
  get_cwd();

#if PWD_SEGMENT
  pwd_enter();
#endif
#if GIT_SEGMENT
  git_enter();
#endif
#if STATUS_SEGMENT
  status_enter();
#endif
  printf("$ " RESET);

  leave();
  return 0;
}
