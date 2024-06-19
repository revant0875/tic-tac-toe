/**
 * @file main.c
 * @author Revant Koriya (revant.koriya.dev@gmail.com)
 * @brief tic-tac-toe networked game
 * @version 0.1
 * @date 2024-06-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/comman.h"
#include "../include/server_functions.h"

/**********************************/
/*           GLOBAL               */
/**********************************/
int server_run_flag = 1;
/**********************************/
/*          GLOBAL END            */
/**********************************/

int main()
{
    int serverfd;
    struct sockaddr_in client_addr;
    socklen_t clientlen = sizeof(client_addr);
    signal(SIGINT, destroy);    

    if (connect_server(&serverfd) != CONNECTION_ESTABLISHED)
        exit(EXIT_FAILURE);

    struct pollfd fds[1];
    fds[0].fd = serverfd;
    fds[0].events = POLLIN;

    printf("Server SetUp Complete...");
    printf("Server is running...\n");
    printf("Server is waiting for client to connect...\n");
    printf("Server is listening on port %d" YELLOW "\342\230\272\n" RESET, PORT);
    printf(GREEN "press ctrl+c to destroy server.\n" RESET);

    while (server_run_flag)
    {
        int poll_ret = poll(fds, 1, -1);
        if (poll_ret == -1)
        {
            perror("poll");
            exit(EXIT_FAILURE);
        }
        else if (poll_ret > 0)
        {
            if (fds[0].revents & POLLIN)
            {
                int *clientfd = (int *)malloc(sizeof(int));
                *clientfd = accept(serverfd, (struct sockaddr *)&client_addr, &clientlen);

                printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));
                pthread_t tid;
                if (pthread_create(&tid, NULL, player_thread, (void *)clientfd) != 0)
                {
                    perror("client thread creation failed");
                    free(clientfd);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    printf("server destroyed...\n");
    close(serverfd);
    return EXIT_SUCCESS;
}
