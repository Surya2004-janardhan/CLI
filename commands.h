#ifndef COMMANDS_H
#define COMMANDS_H

#include <windows.h>

// Command function type
typedef void (*CommandFunc)(char **args, int arg_count);

// Command structure
typedef struct {
    char *name;
    CommandFunc func;
} Command;

// Command declarations
void cmd_help(char **args, int arg_count);
void cmd_exit(char **args, int arg_count);
void cmd_about(char **args, int arg_count);
void cmd_credits(char **args, int arg_count);
void cmd_cls(char **args, int arg_count);
void cmd_sysinfo(char **args, int arg_count);
void cmd_dir(char **args, int arg_count);
void cmd_mem(char **args, int arg_count);
void cmd_cpu(char **args, int arg_count);
void cmd_os(char **args, int arg_count);
void cmd_add(char **args, int arg_count);
void cmd_sub(char **args, int arg_count);
void cmd_mul(char **args, int arg_count);
void cmd_div(char **args, int arg_count);
void cmd_prime(char **args, int arg_count);
void cmd_fibonacci(char **args, int arg_count);
void cmd_factorial(char **args, int arg_count);
void cmd_gcd(char **args, int arg_count);
void cmd_lcm(char **args, int arg_count);
void cmd_sort(char **args, int arg_count);
void cmd_upper(char **args, int arg_count);
void cmd_lower(char **args, int arg_count);
void cmd_reverse(char **args, int arg_count);
void cmd_count(char **args, int arg_count);
void cmd_search(char **args, int arg_count);
void cmd_replace(char **args, int arg_count);
void cmd_palindrome(char **args, int arg_count);
void cmd_joke(char **args, int arg_count);
void cmd_riddle(char **args, int arg_count);
void cmd_quiz(char **args, int arg_count);
void cmd_timer(char **args, int arg_count);
void cmd_beep(char **args, int arg_count);
void cmd_banner(char **args, int arg_count);
void cmd_colors(char **args, int arg_count);
void cmd_ping(char **args, int arg_count);
void cmd_ip(char **args, int arg_count);
void cmd_dns(char **args, int arg_count);
void cmd_netstat(char **args, int arg_count);
void cmd_calc(char **args, int arg_count);
void cmd_history(char **args, int arg_count);
void cmd_alias(char **args, int arg_count);
void cmd_power(char **args, int arg_count);
void cmd_sqrt(char **args, int arg_count);
void cmd_log(char **args, int arg_count);
void cmd_exp(char **args, int arg_count);
void cmd_sin(char **args, int arg_count);
void cmd_cos(char **args, int arg_count);
void cmd_tan(char **args, int arg_count);
void cmd_abs(char **args, int arg_count);
void cmd_round(char **args, int arg_count);
void cmd_ceil(char **args, int arg_count);
void cmd_floor(char **args, int arg_count);
void cmd_mod(char **args, int arg_count);
void cmd_len(char **args, int arg_count);
void cmd_substring(char **args, int arg_count);
void cmd_concat(char **args, int arg_count);
void cmd_split(char **args, int arg_count);
void cmd_join(char **args, int arg_count);
void cmd_trim(char **args, int arg_count);
void cmd_find(char **args, int arg_count);
void cmd_rfind(char **args, int arg_count);
void cmd_replaceall(char **args, int arg_count);
void cmd_isalpha(char **args, int arg_count);
void cmd_isdigit(char **args, int arg_count);
void cmd_date(char **args, int arg_count);
void cmd_time(char **args, int arg_count);
void cmd_hostname(char **args, int arg_count);
void cmd_uptime(char **args, int arg_count);
void cmd_disk(char **args, int arg_count);
void cmd_processes(char **args, int arg_count);
void cmd_kill(char **args, int arg_count);
void cmd_env(char **args, int arg_count);
void cmd_setenv(char **args, int arg_count);
void cmd_fortune(char **args, int arg_count);
void cmd_cow(char **args, int arg_count);
void cmd_figlet(char **args, int arg_count);
void cmd_game(char **args, int arg_count);
void cmd_weather(char **args, int arg_count);
void cmd_quote(char **args, int arg_count);
void cmd_traceroute(char **args, int arg_count);
void cmd_nslookup(char **args, int arg_count);
void cmd_wget(char **args, int arg_count);
void cmd_curl(char **args, int arg_count);
void cmd_ftp(char **args, int arg_count);
void cmd_telnet(char **args, int arg_count);
void cmd_echo(char **args, int arg_count);
void cmd_cat(char **args, int arg_count);
void cmd_head(char **args, int arg_count);
void cmd_tail(char **args, int arg_count);
void cmd_grep(char **args, int arg_count);
void cmd_wc(char **args, int arg_count);
void cmd_sortfile(char **args, int arg_count);
void cmd_uniq(char **args, int arg_count);
void cmd_diff(char **args, int arg_count);
void cmd_chmod(char **args, int arg_count);
void cmd_pwd(char **args, int arg_count);
void cmd_ls(char **args, int arg_count);
void cmd_cp(char **args, int arg_count);
void cmd_mv(char **args, int arg_count);
void cmd_rm(char **args, int arg_count);
void cmd_mkdir(char **args, int arg_count);
void cmd_rmdir(char **args, int arg_count);
void cmd_touch(char **args, int arg_count);
void cmd_which(char **args, int arg_count);
void cmd_type(char **args, int arg_count);
void cmd_findfile(char **args, int arg_count);
void cmd_placeholder(char **args, int arg_count);
void cmd_placeholder2(char **args, int arg_count);
void cmd_placeholder3(char **args, int arg_count);
// ... up to 100

// Command registry
extern Command commands[];
extern int command_count;

#endif