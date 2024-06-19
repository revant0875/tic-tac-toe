#include "../include/utils.h"
#include "../include/comman.h"
#include "../include/server_functions.h"
#define ALLOCATE (client *)malloc(sizeof(client))

static player *head = NULL;

void add_player(player *user)
{

    if (head == NULL)
    {
        head = user;
        head->next = NULL;
        printf(RED "\nFirst player is successfully added" RESET);
    }
    else
    {
        user->next = head;
        head = user;
        printf(RED "\nplayer is successfully added" RESET);
    }
}
void remove_player(player *user)
{
    if (head == user)
    {
        head = head->next;
        free(user);
        printf(RED "\nplayer is successfully removed" RESET);
    }
    else
    {
        player *temp = head;
        while (temp->next != user)
        {
            temp = temp->next;
        }
        temp->next = user->next;
        free(user);
        printf(RED "\nplayer is successfully removed" RESET);
    }
}
void close_list()
{
    player *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        free(temp);
    }
}

void close_threads()
{
    player *temp = head;
    while (temp != NULL)
    {
        // printf("\ndestroing threads ...");
        // _SEND(temp->player_sockfd, "close");
        // pthread_join(temp->tid, NULL);
        // temp = temp->next;
    }
}
void close_players()
{
    // player *temp = head;
    // while (temp != NULL)
    // {
    //     close(temp->player_sockfd);
    //     temp = temp->next;
    // }
}
void unset_thread_run()
{

    // player *temp = head;
    // while (temp != NULL)
    // {
    //     temp->run_flag = 0;
    //     temp = temp->next;
    // }
}
