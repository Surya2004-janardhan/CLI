#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "utils.h"

HANDLE hConsole = NULL;

void set_console_color(WORD color) {
    if (hConsole == NULL) {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    }
    SetConsoleTextAttribute(hConsole, color);
}

void reset_console_color() {
    set_console_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void print_banner() {
    set_console_color(FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("   ______            ______     _____ _      _____ _____ \n");
    printf("  / ____/___  ____  / / __ \\   / ___/(_)___ / ___/|__  /\n");
    printf(" / /   / __ \\/ __ \\/ / / / /   \\__ \\/ / __ \\\\__ \\  /_ < \n");
    printf("/ /___/ /_/ / / / / / /_/ /   ___/ / / / / /__/ /___/ / \n");
    printf("\\____/\\____/_/ /_/_/\\____/   /____/_/_/ /_//____//____/  \n");
    printf("                                                         \n");
    reset_console_color();
    set_console_color(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("Welcome to CoolCLI - Your Cool Command Line Interface!\n");
    reset_console_color();
}

void parse_command(char *input, char **command, char **args, int *arg_count) {
    char *token = strtok(input, " ");
    if (token == NULL) {
        *command = NULL;
        *arg_count = 0;
        return;
    }
    *command = strdup(token);
    *arg_count = 0;
    while ((token = strtok(NULL, " ")) != NULL && *arg_count < 10) {
        args[*arg_count] = strdup(token);
        (*arg_count)++;
    }
}

void log_command(char *cmd) {
    FILE *f = fopen("history.txt", "a");
    if (f) {
        fprintf(f, "%s\n", cmd);
        fclose(f);
    }
}