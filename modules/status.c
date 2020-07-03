#include <stdio.h>
#include <stdlib.h>

#include "../config.h"
#include "../prompt.h"

void status_enter() {
  int status;

  status = get_env_int("PROMPT_STATUS");
  printf(status != 0 ? RED : GRN);
}

void status_leave() {}
