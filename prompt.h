#pragma once

char *prompt_cwd;

char *get_env(char *key);
void fail(const char *message, ...);
