// https://vcansimplify.wordpress.com/2013/03/14/c-socket-tutorial-echo-server/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>

int main(int argc,char **argv)
{
    int sockfd,n;
    char sendline[100];
    char recvline[100];
    struct sockaddr_in servaddr;
    
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof servaddr);
    
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(22000);
    
    //    This function converts the character string src into a network
    //    address structure in the af address family, then copies the network
    //    address structure to dst.  The af argument must be either AF_INET or
    //    AF_INET6.  dst is written in network byte order.
    inet_pton(AF_INET,"127.0.0.1",&(servaddr.sin_addr));
//    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");    ok
    
    connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    
    while(1)
    {
        bzero( sendline, 100);
        bzero( recvline, 100);
        fgets(sendline,100,stdin); /*stdin = 0 , for standard input */
        // fgets() reads in at most one less than size characters from stream and stores them into the buffer pointed to by s. Reading stops after an EOF or a newline. If a newline is read, it is stored into the buffer. A terminating null byte (aq\0aq) is stored after the last character in the buffer.
        
        // printf("strlen(sendline) = %d\n", strlen(sendline));

        // write(sockfd,sendline,strlen(sendline)+1);
        write(sockfd,sendline,100);
        read(sockfd,recvline,100);
        printf("%s",recvline);
    }
    
}
