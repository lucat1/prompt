#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../config.h"
#include "../prompt.h"

char *user, *users;

void user_enter() {
  char *local_users, *part;

  user = get_env("USER");
  users = local_users = strdup(USER_SEGMENT_USERS);

  while ((part = strsep(&local_users, ",")) != NULL) {
    if (strcmp(user, part) == 0) {
      printf(USER_SEGMENT_COLOR "%s" RESET " in ", user);
      break;
    }
  }
}

void user_leave() {
  if (user != NULL)
    free(user);

  if (users != NULL)
    free(users);
}
