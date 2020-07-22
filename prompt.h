#ifndef PROMPT_H
#define PROMPT_H

extern char *prompt_cwd;

char *get_env(char *key);
int get_env_int(char *key);
void fail(const char *message, ...);

#endif // PROMPT_H
