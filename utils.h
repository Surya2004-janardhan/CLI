#ifndef UTILS_H
#define UTILS_H

#include <windows.h>

// Console color functions
void set_console_color(WORD color);
void reset_console_color();

// Banner
void print_banner();

// Command parsing
void parse_command(char *input, char **command, char **args, int *arg_count);

// Logging
void log_command(char *cmd);

#endif