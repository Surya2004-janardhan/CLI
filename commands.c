#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "commands.h"
#include "utils.h"
#include <math.h>

// Implementations

void cmd_help(char **args, int arg_count) {
    set_console_color(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("CoolCLI Help - Available Commands:\n\n");
    reset_console_color();

    // System
    set_console_color(FOREGROUND_GREEN);
    printf("System Commands:\n");
    reset_console_color();
    printf("  sysinfo, dir, mem, cls, cpu, os\n\n");

    // Math
    set_console_color(FOREGROUND_RED | FOREGROUND_GREEN);
    printf("Math Commands:\n");
    reset_console_color();
    printf("  add, sub, mul, div, prime, fibonacci, factorial, gcd, lcm, sort\n\n");

    // String
    set_console_color(FOREGROUND_RED | FOREGROUND_GREEN);
    printf("String/Text Commands:\n");
    reset_console_color();
    printf("  upper, lower, reverse, count, search, replace, palindrome\n\n");

    // Fun
    set_console_color(FOREGROUND_RED | FOREGROUND_BLUE);
    printf("Fun Commands:\n");
    reset_console_color();
    printf("  joke, riddle, quiz, timer, beep, banner, colors\n\n");

    // Network
    set_console_color(FOREGROUND_BLUE | FOREGROUND_GREEN);
    printf("Network Commands:\n");
    reset_console_color();
    printf("  ping, ip, dns, netstat\n\n");

    // Utility
    set_console_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("Utility Commands:\n");
    reset_console_color();
    printf("  calc, history, alias, help, exit, about, credits\n\n");

    printf("Total commands: 100+ (many placeholders)\n");
}

void cmd_exit(char **args, int arg_count) {
    exit(0);
}

void cmd_about(char **args, int arg_count) {
    set_console_color(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("CoolCLI - A Cool Command Line Interface\n");
    printf("Version 1.0\n");
    printf("Built with C11, Windows Console API\n");
    reset_console_color();
}

void cmd_credits(char **args, int arg_count) {
    set_console_color((FOREGROUND_RED | FOREGROUND_GREEN) | FOREGROUND_INTENSITY);
    printf("Credits:\n");
    printf("Developed by: Your Name\n");
    printf("Special thanks to: Open source community\n");
    reset_console_color();
}

void cmd_cls(char **args, int arg_count) {
    system("cls");
}

void cmd_sysinfo(char **args, int arg_count) {
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    printf("Processor Architecture: %d\n", si.wProcessorArchitecture);
    printf("Number of Processors: %d\n", si.dwNumberOfProcessors);
}

void cmd_dir(char **args, int arg_count) {
    system("dir");
}

void cmd_mem(char **args, int arg_count) {
    MEMORYSTATUSEX mem;
    mem.dwLength = sizeof(mem);
    GlobalMemoryStatusEx(&mem);
    printf("Total Physical Memory: %llu MB\n", mem.ullTotalPhys / (1024 * 1024));
    printf("Available Physical Memory: %llu MB\n", mem.ullAvailPhys / (1024 * 1024));
}

void cmd_cpu(char **args, int arg_count) {
    // Simple CPU info
    printf("CPU Info: Not fully implemented\n");
}

void cmd_os(char **args, int arg_count) {
    OSVERSIONINFO osvi;
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&osvi);
    printf("OS Version: %d.%d\n", osvi.dwMajorVersion, osvi.dwMinorVersion);
}

void cmd_add(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: add <num1> <num2>\n");
        return;
    }
    double a = atof(args[0]);
    double b = atof(args[1]);
    printf("%.2f + %.2f = %.2f\n", a, b, a + b);
}

void cmd_sub(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: sub <num1> <num2>\n");
        return;
    }
    double a = atof(args[0]);
    double b = atof(args[1]);
    printf("%.2f - %.2f = %.2f\n", a, b, a - b);
}

void cmd_mul(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: mul <num1> <num2>\n");
        return;
    }
    double a = atof(args[0]);
    double b = atof(args[1]);
    printf("%.2f * %.2f = %.2f\n", a, b, a * b);
}

void cmd_div(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: div <num1> <num2>\n");
        return;
    }
    double a = atof(args[0]);
    double b = atof(args[1]);
    if (b == 0) {
        printf("Division by zero!\n");
        return;
    }
    printf("%.2f / %.2f = %.2f\n", a, b, a / b);
}

void cmd_prime(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: prime <num>\n");
        return;
    }
    int n = atoi(args[0]);
    int is_prime = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            is_prime = 0;
            break;
        }
    }
    printf("%d is %s\n", n, is_prime ? "prime" : "not prime");
}

void cmd_fibonacci(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: fibonacci <n>\n");
        return;
    }
    int n = atoi(args[0]);
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        printf("%lld ", a);
        long long temp = a;
        a = b;
        b = temp + b;
    }
    printf("\n");
}

void cmd_factorial(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: factorial <n>\n");
        return;
    }
    int n = atoi(args[0]);
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("%d! = %lld\n", n, fact);
}

void cmd_gcd(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: gcd <a> <b>\n");
        return;
    }
    int a = atoi(args[0]);
    int b = atoi(args[1]);
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    printf("GCD: %d\n", a);
}

void cmd_lcm(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: lcm <a> <b>\n");
        return;
    }
    int a = atoi(args[0]);
    int b = atoi(args[1]);
    int gcd = a;
    int temp_b = b;
    while (temp_b != 0) {
        int t = temp_b;
        temp_b = gcd % temp_b;
        gcd = t;
    }
    printf("LCM: %d\n", a / gcd * b);
}

void cmd_sort(char **args, int arg_count) {
    // Simple bubble sort for numbers
    if (arg_count < 2) {
        printf("Usage: sort <num1> <num2> ...\n");
        return;
    }
    int nums[100];
    for (int i = 0; i < arg_count; i++) {
        nums[i] = atoi(args[i]);
    }
    for (int i = 0; i < arg_count - 1; i++) {
        for (int j = 0; j < arg_count - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < arg_count; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void cmd_upper(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: upper <string>\n");
        return;
    }
    char *str = args[0];
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
    printf("%s\n", str);
}

void cmd_lower(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: lower <string>\n");
        return;
    }
    char *str = args[0];
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
    printf("%s\n", str);
}

void cmd_reverse(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: reverse <string>\n");
        return;
    }
    char *str = args[0];
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("%s\n", str);
}

void cmd_count(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: count <string>\n");
        return;
    }
    printf("Length: %d\n", (int)strlen(args[0]));
}

void cmd_search(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: search <string> <substring>\n");
        return;
    }
    char *pos = strstr(args[0], args[1]);
    if (pos) {
        printf("Found at position: %d\n", (int)(pos - args[0]));
    } else {
        printf("Not found\n");
    }
}

void cmd_replace(char **args, int arg_count) {
    // Simple replace first occurrence
    if (arg_count < 3) {
        printf("Usage: replace <string> <old> <new>\n");
        return;
    }
    char *str = strdup(args[0]);
    char *old = args[1];
    char *new = args[2];
    char *pos = strstr(str, old);
    if (pos) {
        int len_old = strlen(old);
        int len_new = strlen(new);
        memmove(pos + len_new, pos + len_old, strlen(pos + len_old) + 1);
        memcpy(pos, new, len_new);
    }
    printf("%s\n", str);
    free(str);
}

void cmd_palindrome(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: palindrome <string>\n");
        return;
    }
    char *str = args[0];
    int len = strlen(str);
    int is_pal = 1;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            is_pal = 0;
            break;
        }
    }
    printf("%s is %s\n", str, is_pal ? "a palindrome" : "not a palindrome");
}

void cmd_joke(char **args, int arg_count) {
    printf("Why did the computer go to the doctor? Because it had a virus!\n");
}

void cmd_riddle(char **args, int arg_count) {
    printf("What has keys but can't open locks? A piano!\n");
}

void cmd_quiz(char **args, int arg_count) {
    printf("Quiz: What is 2+2? (Answer: 4)\n");
}

void cmd_timer(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: timer <seconds>\n");
        return;
    }
    int sec = atoi(args[0]);
    Sleep(sec * 1000);
    printf("Timer done!\n");
}

void cmd_beep(char **args, int arg_count) {
    Beep(800, 500);
}

void cmd_banner(char **args, int arg_count) {
    print_banner();
}

void cmd_colors(char **args, int arg_count) {
    for (int i = 1; i <= 15; i++) {
        set_console_color(i);
        printf("Color %d\n", i);
    }
    reset_console_color();
}

void cmd_ping(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: ping <host>\n");
        return;
    }
    char cmd[256];
    sprintf(cmd, "ping %s", args[0]);
    system(cmd);
}

void cmd_ip(char **args, int arg_count) {
    system("ipconfig");
}

void cmd_dns(char **args, int arg_count) {
    system("nslookup google.com");
}

void cmd_netstat(char **args, int arg_count) {
    system("netstat");
}

void cmd_calc(char **args, int arg_count) {
    // Simple calculator, assume expression like 2+3
    if (arg_count < 1) {
        printf("Usage: calc <expression>\n");
        return;
    }
    // For simplicity, just eval basic
    printf("Calc not fully implemented, use add/sub/mul/div\n");
}

void cmd_history(char **args, int arg_count) {
    FILE *f = fopen("history.txt", "r");
    if (!f) {
        printf("No history\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }
    fclose(f);
}

void cmd_alias(char **args, int arg_count) {
    printf("Alias not implemented yet\n");
}

// Placeholder
void cmd_placeholder(char **args, int arg_count) {
    printf("Command not implemented yet\n");
}

// Additional Math Implementations
void cmd_power(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: power <base> <exp>\n");
        return;
    }
    double base = atof(args[0]);
    double exp = atof(args[1]);
    printf("%.2f ^ %.2f = %.2f\n", base, exp, pow(base, exp));
}

void cmd_sqrt(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: sqrt <num>\n");
        return;
    }
    double num = atof(args[0]);
    printf("sqrt(%.2f) = %.2f\n", num, sqrt(num));
}

void cmd_log(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: log <num>\n");
        return;
    }
    double num = atof(args[0]);
    printf("log(%.2f) = %.2f\n", num, log(num));
}

void cmd_exp(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: exp <num>\n");
        return;
    }
    double num = atof(args[0]);
    printf("exp(%.2f) = %.2f\n", num, exp(num));
}

void cmd_sin(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: sin <angle in rad>\n");
        return;
    }
    double angle = atof(args[0]);
    printf("sin(%.2f) = %.2f\n", angle, sin(angle));
}

void cmd_cos(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: cos <angle in rad>\n");
        return;
    }
    double angle = atof(args[0]);
    printf("cos(%.2f) = %.2f\n", angle, cos(angle));
}

void cmd_tan(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: tan <angle in rad>\n");
        return;
    }
    double angle = atof(args[0]);
    printf("tan(%.2f) = %.2f\n", angle, tan(angle));
}

void cmd_abs(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: abs <num>\n");
        return;
    }
    int num = atoi(args[0]);
    printf("abs(%d) = %d\n", num, abs(num));
}

void cmd_round(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: round <num>\n");
        return;
    }
    double num = atof(args[0]);
    printf("round(%.2f) = %.0f\n", num, round(num));
}

void cmd_ceil(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: ceil <num>\n");
        return;
    }
    double num = atof(args[0]);
    printf("ceil(%.2f) = %.0f\n", num, ceil(num));
}

void cmd_floor(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: floor <num>\n");
        return;
    }
    double num = atof(args[0]);
    printf("floor(%.2f) = %.0f\n", num, floor(num));
}

void cmd_mod(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: mod <a> <b>\n");
        return;
    }
    int a = atoi(args[0]);
    int b = atoi(args[1]);
    if (b == 0) {
        printf("Mod by zero!\n");
        return;
    }
    printf("%d %% %d = %d\n", a, b, a % b);
}

// Additional String Implementations
void cmd_len(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: len <string>\n");
        return;
    }
    printf("Length: %d\n", (int)strlen(args[0]));
}

void cmd_substring(char **args, int arg_count) {
    if (arg_count < 3) {
        printf("Usage: substring <string> <start> <len>\n");
        return;
    }
    char *str = args[0];
    int start = atoi(args[1]);
    int len = atoi(args[2]);
    if (start < 0 || len < 0 || start + len > strlen(str)) {
        printf("Invalid range\n");
        return;
    }
    char sub[256];
    strncpy(sub, str + start, len);
    sub[len] = '\0';
    printf("%s\n", sub);
}

void cmd_concat(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: concat <str1> <str2>\n");
        return;
    }
    printf("%s%s\n", args[0], args[1]);
}

void cmd_split(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: split <string> <delim>\n");
        return;
    }
    char *str = args[0];
    char *delim = args[1];
    char *token = strtok(str, delim);
    while (token) {
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }
}

void cmd_join(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: join <delim> <str1> <str2> ...\n");
        return;
    }
    char *delim = args[0];
    for (int i = 1; i < arg_count; i++) {
        if (i > 1) printf("%s", delim);
        printf("%s", args[i]);
    }
    printf("\n");
}

void cmd_trim(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: trim <string>\n");
        return;
    }
    char *str = args[0];
    while (*str == ' ') str++;
    char *end = str + strlen(str) - 1;
    while (end > str && *end == ' ') end--;
    *(end + 1) = '\0';
    printf("%s\n", str);
}

void cmd_find(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: find <string> <substr>\n");
        return;
    }
    char *pos = strstr(args[0], args[1]);
    if (pos) {
        printf("Found at: %d\n", (int)(pos - args[0]));
    } else {
        printf("Not found\n");
    }
}

void cmd_rfind(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: rfind <string> <substr>\n");
        return;
    }
    char *str = args[0];
    char *substr = args[1];
    char *last = NULL;
    char *pos = strstr(str, substr);
    while (pos) {
        last = pos;
        pos = strstr(pos + 1, substr);
    }
    if (last) {
        printf("Last at: %d\n", (int)(last - str));
    } else {
        printf("Not found\n");
    }
}

void cmd_replaceall(char **args, int arg_count) {
    if (arg_count < 3) {
        printf("Usage: replaceall <string> <old> <new>\n");
        return;
    }
    char *str = strdup(args[0]);
    char *old = args[1];
    char *new = args[2];
    char *pos;
    while ((pos = strstr(str, old))) {
        int len_old = strlen(old);
        int len_new = strlen(new);
        memmove(pos + len_new, pos + len_old, strlen(pos + len_old) + 1);
        memcpy(pos, new, len_new);
    }
    printf("%s\n", str);
    free(str);
}

void cmd_isalpha(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: isalpha <string>\n");
        return;
    }
    int all = 1;
    for (char *p = args[0]; *p; p++) {
        if (!isalpha(*p)) all = 0;
    }
    printf("%s\n", all ? "All alphabetic" : "Not all alphabetic");
}

void cmd_isdigit(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: isdigit <string>\n");
        return;
    }
    int all = 1;
    for (char *p = args[0]; *p; p++) {
        if (!isdigit(*p)) all = 0;
    }
    printf("%s\n", all ? "All digits" : "Not all digits");
}

// Command registry
Command commands[] = {
    {"help", cmd_help},
    {"exit", cmd_exit},
    {"about", cmd_about},
    {"credits", cmd_credits},
    {"cls", cmd_cls},
    {"sysinfo", cmd_sysinfo},
    {"dir", cmd_dir},
    {"mem", cmd_mem},
    {"cpu", cmd_cpu},
    {"os", cmd_os},
    {"add", cmd_add},
    {"sub", cmd_sub},
    {"mul", cmd_mul},
    {"div", cmd_div},
    {"prime", cmd_prime},
    {"fibonacci", cmd_fibonacci},
    {"factorial", cmd_factorial},
    {"gcd", cmd_gcd},
    {"lcm", cmd_lcm},
    {"sort", cmd_sort},
    {"upper", cmd_upper},
    {"lower", cmd_lower},
    {"reverse", cmd_reverse},
    {"count", cmd_count},
    {"search", cmd_search},
    {"replace", cmd_replace},
    {"palindrome", cmd_palindrome},
    {"joke", cmd_joke},
    {"riddle", cmd_riddle},
    {"quiz", cmd_quiz},
    {"timer", cmd_timer},
    {"beep", cmd_beep},
    {"banner", cmd_banner},
    {"colors", cmd_colors},
    {"ping", cmd_ping},
    {"ip", cmd_ip},
    {"dns", cmd_dns},
    {"netstat", cmd_netstat},
    {"calc", cmd_calc},
    {"history", cmd_history},
    {"alias", cmd_alias},
    // Placeholders for the rest
    {"placeholder1", cmd_placeholder},
    {"placeholder2", cmd_placeholder},
    // ... up to 100+
};

int command_count = sizeof(commands) / sizeof(Command);

// Additional System Implementations
void cmd_date(char **args, int arg_count) {
    system("date /t");
}

void cmd_time(char **args, int arg_count) {
    system("time /t");
}

void cmd_hostname(char **args, int arg_count) {
    system("hostname");
}

void cmd_uptime(char **args, int arg_count) {
    printf("Uptime: Not implemented\n");
}

void cmd_disk(char **args, int arg_count) {
    system("wmic logicaldisk get size,freespace,caption");
}

void cmd_processes(char **args, int arg_count) {
    system("tasklist");
}

void cmd_kill(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: kill <pid>\n");
        return;
    }
    char cmd[256];
    sprintf(cmd, "taskkill /PID %s", args[0]);
    system(cmd);
}

void cmd_env(char **args, int arg_count) {
    system("set");
}

void cmd_setenv(char **args, int arg_count) {
    if (arg_count < 2) {
        printf("Usage: setenv <var> <value>\n");
        return;
    }
    char cmd[256];
    sprintf(cmd, "set %s=%s", args[0], args[1]);
    system(cmd);
}

// Additional Fun Implementations
void cmd_fortune(char **args, int arg_count) {
    printf("Fortune: You will have a great day!\n");
}

void cmd_cow(char **args, int arg_count) {
    printf("Cow says: Moo!\n");
}

void cmd_figlet(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: figlet <text>\n");
        return;
    }
    // Simulate figlet
    printf("FIGLET: %s\n", args[0]);
}

void cmd_game(char **args, int arg_count) {
    printf("Simple game: Guess a number between 1-10: 5\nYou win!\n");
}

void cmd_weather(char **args, int arg_count) {
    printf("Weather: Sunny, 25°C\n");
}

void cmd_quote(char **args, int arg_count) {
    printf("Quote: \"The only way to do great work is to love what you do.\" - Steve Jobs\n");
}

// Additional Network Implementations
void cmd_traceroute(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: traceroute <host>\n");
        return;
    }
    char cmd[256];
    sprintf(cmd, "tracert %s", args[0]);
    system(cmd);
}

void cmd_nslookup(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: nslookup <host>\n");
        return;
    }
    char cmd[256];
    sprintf(cmd, "nslookup %s", args[0]);
    system(cmd);
}

void cmd_wget(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: wget <url>\n");
        return;
    }
    char cmd[256];
    sprintf(cmd, "powershell Invoke-WebRequest -Uri %s -OutFile download.txt", args[0]);
    system(cmd);
}

void cmd_curl(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: curl <url>\n");
        return;
    }
    char cmd[256];
    sprintf(cmd, "curl %s", args[0]);
    system(cmd);
}

void cmd_ftp(char **args, int arg_count) {
    printf("FTP: Not implemented\n");
}

void cmd_telnet(char **args, int arg_count) {
    if (arg_count < 1) {
        printf("Usage: telnet <host> <port>\n");
        return;
    }
    char cmd[256];
    sprintf(cmd, "telnet %s %s", args[0], args[1] ? args[1] : "23");
    system(cmd);
}