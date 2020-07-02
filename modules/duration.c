#include <stdio.h>
#include <stdlib.h>

#include "../config.h"
#include "../prompt.h"

#define TIME_SECOND 1000 
#define TIME_MINUTE TIME_SECOND * 60
#define TIME_HOUR TIME_MINUTE * 60


void duration_enter() {
  int prompt_duration;
  /* char *fmt; */
  prompt_duration = get_env_int("PROMPT_DURATION");

  // the duration is in milliseconds. So we apply a threshold
  // before outputting its value
  if (prompt_duration > DURATION_SEGMENT_THRESHOLD)
    printf("took " DURATION_SEGMENT_COLOR "%ds" RESET, prompt_duration/TIME_SECOND);
}

void duration_leave() {}
