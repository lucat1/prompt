#include <stdio.h>
#include <sys/time.h>

int main() {
  struct timeval time;
  gettimeofday(&time, NULL);
  long ms = (((long long)time.tv_sec)*1000)+(time.tv_usec/1000);
  printf("%li\n", ms);

  return 0;
}
