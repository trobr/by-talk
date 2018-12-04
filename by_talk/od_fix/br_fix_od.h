#ifndef _BR_FIX_OD_H_
#define _BR_FIX_OD_H_

#include <Windows.h>
#include <direct.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_NAME "\\log.txt"
#define INIT "init"
#define PARSE "parse"
#define FLODER "floder"
#define REMOVE "remove"
#define RENAME "rename"
#define RUN "run"

#define DEFLAUT_ARGC 7

#define BUFF_SIZE 128
#define MAX_COUNT 5
#define MAX_FLODER_LENGHT 256
#define MAX_LOG_LENGHT 10000

#define FLODER_MODE
//#define TRACK_MODE
/*
 * help info
 */
#define HELP_INFO "br_fix_od.exe -d /path/to/onedrive"

typedef struct _config {
    int delay_time;
    FILE *cfd;
    char ini_file[MAX_FLODER_LENGHT];
    char onedirve[MAX_FLODER_LENGHT];
    char track_floder[MAX_FLODER_LENGHT];
    char hidden_floder[MAX_FLODER_LENGHT];
    char alive_floder[MAX_FLODER_LENGHT];
    char cur_alive_floder[MAX_FLODER_LENGHT];
} config;

#endif