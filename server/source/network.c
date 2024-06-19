#include "../include/comman.h"
#include "../include/server_functions.h"

int connect_server(int *fd)
{
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_UNSPEC;       // AF_INET for IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // inet_addr(SERVER_IP) this will not work
    server_addr.sin_port = htons(PORT);

    if ((bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in))) == -1)
    {
        perror("server bind failed.");
        exit(EXIT_FAILURE);
    }
    if (listen(sock, BACKLOG) == -1)
    {
        perror("failed to listen ...");
        exit(EXIT_FAILURE);
    }
    *fd = sock;
    return CONNECTION_ESTABLISHED;
}
