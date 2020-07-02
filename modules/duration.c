#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "../config.h"
#include "../prompt.h"

#define TIME_SECOND 1000 
#define TIME_MINUTE TIME_SECOND * 60
#define TIME_HOUR TIME_MINUTE * 60

void duration_enter() {
  int dur;
  char *fmt;
  dur = get_env_int("PROMPT_DURATION");

  // the duration is in milliseconds. So we apply a threshold
  // before outputting its value
  if (dur < DURATION_SEGMENT_THRESHOLD)
    return;

  if(dur < TIME_MINUTE)
    // print seconds 
    asprintf(&fmt, "%ds", dur / TIME_SECOND);

  if(dur < TIME_HOUR && dur > TIME_MINUTE) {
    // print minutes 
    int secs = dur % TIME_MINUTE;
    asprintf(&fmt, "%dm %ds", dur / TIME_MINUTE, secs / TIME_SECOND);
  }

  if(dur >= TIME_HOUR && dur > TIME_MINUTE) {
    // print hours 
    int mins = dur % TIME_HOUR;
    asprintf(&fmt, "%dh %dm", dur / TIME_HOUR, mins / TIME_MINUTE);
  }

  printf("took " DURATION_SEGMENT_COLOR "%s" RESET, fmt);
  free(fmt);
}

void duration_leave() {}
