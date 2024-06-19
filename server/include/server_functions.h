#ifndef SERVER_FUNCTIONS_H
#define SERVER_FUNCTIONS_H
/********************************/
/*   MACROS                     */
/********************************/
#define PORT 2003
#define BROADCAST "192.168.7.255"
#define BACKLOG 5
typedef struct player
{
    char name[20];
    int score;
    int socket;
    int player2sock;
    struct player *next;
}player;


typedef enum 
{
    SUCCESS,
    FAILURE,
    GAME_OVER,
    CONNECTION_ESTABLISHED
}status;


void destroy(int signum);
void *player_thread();
int connect_server(int *fd);
#endif // SERVER_FUNCTIONS_H
