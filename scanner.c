#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    int sock;
    struct sockaddr_in target;

    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    target.sin_addr.s_addr = inet_addr(ip);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
        printf("Port %d is OPEN on %s\n", port, ip);
    } else {
        printf("Port %d is CLOSED on %s\n", port, ip);
    }

    close(sock);
    return 0;
}
