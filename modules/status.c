#include <stdio.h>
#include <stdlib.h>

#include "../config.h"
#include "../prompt.h"

int prompt_status;

void status_enter() {
  prompt_status = get_env_int("PROMPT_STATUS");

  printf(prompt_status != 0 ? RED : GRN);
}

void status_leave() {}
