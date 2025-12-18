#### REMEmBER, ##### 
### A simple TCP port scanner written in C.  
####Educational project to learn about sockets, networking, and concurrency.

###### Usage
gcc scanner.c -o scanner
./scanner <IP> <start_port> <end_port>

    Ex: ./scanner 192.168.1.1 443
    Port 443 is OPEN on 192.168.1.1


    
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



###########
# ok, this is very basic code. so i am not going to explain every line. but a little that i know, here goes:
###########

>>Prog. begining entry point: 
    int main(int argc, char *argv[]) {         << Two arguments)
            
>>Validate argument count:
    if (argc != 3) {
    Make surE the user provided exactly two arguments: <<< IP and port >>>.

>>Usage message on error:
    printf("Usage: %s <IP> <port>\n", argv[0]);
    Prints the program, using argv[0]

>>Exit with error code:
    return 1;
    Stops the program if they are incorrect.

        
>>Read IP argument:
     char *ip = argv[1];
     Extracts the IP address string from the second argument.

>>Convert the value string to integer:
     int port = atoi(argv[2]);
     Converts the port from text to an integer.

>>Declare socket descriptor:
     int sock;
     Will hold the file descriptor for the network socket.

>>Declare target address structure:
     struct sockaddr_in target;   <<IPv4)
     target.sin_family = AF_INET;
     target.sin_port = htons(port);
     target.sin_addr.s_addr = inet_addr(ip);

>>Create TCP socket:
     sock = socket(AF_INET, SOCK_STREAM, 0);
    
>> Try to attempt connection:
     if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
          printf("Port %d is OPEN on %s\n", port, ip);
     } else {

>>Closed message:
    printf("Port %d is CLOSED on %s\n", port, ip);

>>Close the socket:
     close(sock);

>>>>>>Releases the socket resource regardless of whatever.  
    return 0;


