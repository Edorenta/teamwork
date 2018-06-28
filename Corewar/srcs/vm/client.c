#include "corewar.h"

void send_to_socket(t_vm *vm, char *payload, int len)
{
	(void)len;
	send(vm->sock, payload, strlen(payload), 0);
}

int init_socket(void)
{
    char                *payload = "Here is the payload, over.";
    int                 sock = 0;
    int                 handler;
    struct sockaddr_in  serv_addr;
    char                buf[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket creation error\n");//
        exit(EXIT_FAILURE);
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("Invalid address/ Address not supported\n");//
        exit(EXIT_FAILURE);
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Connection Failed\n");//
        exit(EXIT_FAILURE);
    }
    return sock;
}
