#include "br_fix_od.h"

#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")

/*
 * defalut config
 */
char *d_conf[] = {
    "program", 
    "-d", "C:\\Users\\br\\OneDrive",       
    "-t", "30",      
    "-m", "C:\\Users\\br\\OneDrive\\cloud"
};

void br_exit(int val)
{
    getchar();
    getchar();
    exit(val);
}

int br_parse_ini(char *file)
{
    int count = 0;

    FILE *fd = fopen(file, "r");
    if (NULL != fd) {
        char data[MAX_FLODER_LENGHT];
        fread(data, 1, MAX_FLODER_LENGHT, fd);
        count = atoi(data);
        fclose(fd);
    }

    return count;
}

void br_write_ini(char *file, int count)
{
    FILE *fd = fopen(file, "w");
    if (NULL != fd) {
        char data[MAX_FLODER_LENGHT];

        memset(data, 0, MAX_FLODER_LENGHT);
        sprintf(data, "%d", count);
        fwrite(data, 1, MAX_FLODER_LENGHT, fd);
        fclose(fd);
    }
}

config *br_parse_cmd(int argc, char **args)
{
    //
    config *cfg = NULL;
    cfg = malloc(sizeof(config));
    if (cfg == NULL) {
        printf("[%s] %s\n", PARSE, "config object malloc error");
        br_exit(0);
    }

    switch (argc) {
    case 1:
        /* defalut config */
        break;
    case 2:
        /*print help info*/
        printf("[%s] %s\n", PARSE, HELP_INFO);
    default:
        int cnt = 1;
        while (cnt < argc) {
            if (0 == strcmp(args[cnt], "-d")) {
                strcpy(cfg->onedirve, args[cnt + 1]);

                strcpy(cfg->hidden_floder, cfg->onedirve);
                strcat(cfg->hidden_floder, "\\.br_fix");

                // getcwd(cfg->ini_file, MAX_FLODER_LENGHT);
                strcpy(cfg->ini_file, cfg->hidden_floder);
                strcat(cfg->ini_file, "\\br.ini");

                printf("[%s] generate ini file: %s\n", PARSE, cfg->ini_file);
                printf("[%s] get root OneDrive path: %s\n", PARSE,
                       cfg->onedirve);
                printf("[%s] generate hidden path: %s\n", PARSE,
                       cfg->hidden_floder);
            } else if (0 == strcmp(args[cnt], "-t")) {
                int delay = atoi(args[cnt + 1]);
                cfg->delay_time = delay * 1000;
                printf("[%s] set loop time : %ds\n", PARSE, delay);
            } else if (0 == strcmp(args[cnt], "-m")) {
                strcpy(cfg->track_floder, args[cnt + 1]);
                printf("[%s] set track floder : %ds\n", PARSE,
                       cfg->track_floder);
            } else {
                printf("[%s] %s\n", PARSE, HELP_INFO);
            }

            cnt += 2;
        }
    }

    return cfg;
}

void br_reopen_stdout(void)
{
    char log[MAX_FLODER_LENGHT];
    getcwd(log, MAX_FLODER_LENGHT);
    strcat(log, LOG_NAME);
    if (NULL == freopen(log, "w", stdout)) {
        // fprintf(stderr, "freopen file open error");
        // printf("%s\n", "freopen file open error");
        MessageBox(0, "freopen file open error", "error", 0);
        br_exit(0);
    } else {
        printf("[%s] %s\n", INIT, "stdout reopen success");
    }
}

void br_init(void)
{
    //
    br_reopen_stdout();
}

int br_create_floder(char *path)
{
    //
    if (0 != access(path, 0)) {
        // create hidden floder
        if (0 == mkdir(path)) {
            // create success
#ifndef FLODER_MODE
            printf("[%s] hidden floder create in :%s\n", FLODER, path);
#endif
        } else {
            printf("[%s] hidden floder create error with %d\n", FLODER, errno);
#ifndef FLODER_MODE
            br_exit(0);
#else
            return -1;
#endif
        }
    } else {
        printf("[%s] hidden floder already exist\n", FLODER);
    }

    return 0;
}

int br_create_hidden_floder(config *cfg)
{
    int ret = 0;

    ret = br_create_floder(cfg->hidden_floder);
    // ret = br_create_floder(cfg->alive_floder);

    return 0;
}

int br_remove_hidden_floder(config *cfg)
{
    if (0 == access(cfg->hidden_floder, 0)) {
        // remove hidden floder
        if (0 == remove(cfg->hidden_floder)) {
            // remove success
#ifndef FLODER_MODE
            printf("[%s] hidden floder remove success\n", FLODER);
#endif
        } else {
            printf("[%s] hidden floder remove error with %d\n", REMOVE, errno);
            return -1;
        }
    } else {
        printf("[%s] hidden floder not find\n", REMOVE);
    }

    return 0;
}

int br_rename_hidden_floder(config *cfg)
{
    static int count = -1;
    if (-1 == count) {
        count = br_parse_ini(cfg->ini_file);
        sprintf(cfg->alive_floder, "%s\\alive", cfg->hidden_floder, count);
        sprintf(cfg->cur_alive_floder, "%s\\alive_%d", cfg->hidden_floder,
                count);

        printf("[%s] generate alive file path: %s\n", RENAME,
               cfg->alive_floder);

        br_create_floder(cfg->cur_alive_floder);
    } else if (0 == access(cfg->cur_alive_floder, 0)) {
        // generate new hidden floder name
        char new_floder[MAX_FLODER_LENGHT];
        memset(new_floder, 0, MAX_FLODER_LENGHT);

        count += 1;
        count %= MAX_COUNT;
        sprintf(new_floder, "%s_%d", cfg->alive_floder, count);

        // rename hidden floder
        if (0 == rename(cfg->cur_alive_floder, new_floder)) {
            // rename success
#ifndef FLODER_MODE
            printf("[%s] hidden floder remove success\n", FLODER);
#endif
            strcpy(cfg->cur_alive_floder, new_floder);
        } else {
            count -= 1;
            if (count < 0) {
                count = MAX_COUNT;
            }
            printf("[%s] hidden floder rename error with %d\n", RENAME, errno);
            return -1;
        }
    } else {
        br_create_floder(cfg->cur_alive_floder);
        printf("[%s] hidden floder not find\n", RENAME);
    }

    br_write_ini(cfg->ini_file, count);

    return 0;
}

int br_run(config *cfg)
{
#ifndef TRACK_MODE
    while (1) {
        br_rename_hidden_floder(cfg);

        Sleep(cfg->delay_time);

		fflush(stdout);
    }
#else
    HANDLE hChangeHandle = FindFirstChangeNotification(
        cfg->track_floder, 1,
        FILE_NOTIFY_CHANGE_LAST_WRITE | FILE_NOTIFY_CHANGE_FILE_NAME |
        FILE_NOTIFY_CHANGE_DIR_NAME | FILE_NOTIFY_CHANGE_ATTRIBUTES |
        FILE_NOTIFY_CHANGE_SIZE | FILE_NOTIFY_CHANGE_SECURITY
    );

    if (INVALID_HANDLE_VALUE == hChangeHandle) {
        MessageBox(0, "track target floder error", "error", 0);
        br_exit(GetLastError());
    }

    int log_count = 0;

    while (1) {
        if (WaitForSingleObject(hChangeHandle, INFINITE)) {
            br_rename_hidden_floder(cfg);

            Sleep(cfg->delay_time);
            
            log_count += 1;
            printf("[%s] monitor a file change\n", RUN);
            fflush(stdout);

            if (log_count > MAX_LOG_LENGHT) {
                log_count = 0;
                fclose(stdout);
                br_reopen_stdout();
                printf("[reopen] stdout reopen\n");
            }
        }

        if (!FindNextChangeNotification(hChangeHandle)) {
            break;
        }
    }

	FindCloseChangeNotification(hChangeHandle);
    fclose(stdout);
#endif

    return 0;
}

int main(int argc, char **args)
{
    br_init();

    if (1 == argc) {
        argc = DEFLAUT_ARGC;
        args = d_conf;
    }

    config *cfg = br_parse_cmd(argc, args);

    br_create_hidden_floder(cfg);

    br_run(cfg);
}