#include "../include/comman.h"
extern int server_run_flag;
void destroy(int signum)
{
    if(signum == SIGINT)
    {
        server_run_flag = 0;
        printf("server destroy started...");
    }
}
