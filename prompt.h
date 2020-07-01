#pragma once

char *prompt_cwd;

char *get_env(char *key);
int get_env_int(char *key);
void fail(const char *message, ...);
