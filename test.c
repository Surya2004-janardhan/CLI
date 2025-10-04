#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "commands.h"
#include "utils.h"

#define MAX_INPUT 1024

int main() {
    set_console_color(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    print_banner();
    reset_console_color();

    char input[MAX_INPUT];
    char *command;
    char *args[10];
    int arg_count;

    while (1) {
        set_console_color((FOREGROUND_BLUE | FOREGROUND_GREEN) | FOREGROUND_INTENSITY);
        printf("CoolCLI> ");
        reset_console_color();

        if (fgets(input, MAX_INPUT, stdin) == NULL) {
            break;
        }

        // Remove newline
        input[strcspn(input, "\n")] = 0;

        // Log to history
        log_command(input);

        // Parse command
        parse_command(input, &command, args, &arg_count);

        if (command == NULL) continue;

        // Find and execute command
        int found = 0;
        for (int i = 0; i < command_count; i++) {
            if (strcmp(commands[i].name, command) == 0) {
                commands[i].func(args, arg_count);
                found = 1;
                break;
            }
        }

        if (!found) {
            set_console_color(FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("Unknown command: %s\n", command);
            reset_console_color();
        }

        free(command);
        for (int i = 0; i < arg_count; i++) {
            free(args[i]);
        }
    }

    set_console_color((FOREGROUND_RED | FOREGROUND_GREEN) | FOREGROUND_INTENSITY);
    printf("Goodbye! Thanks for using CoolCLI.\n");
    reset_console_color();

    return 0;
}