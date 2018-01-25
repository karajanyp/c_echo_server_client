// https://vcansimplify.wordpress.com/2013/03/14/c-socket-tutorial-echo-server/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include <unistd.h>

int main()
{
    char str[100];
    int listen_fd, comm_fd;
    
    struct sockaddr_in servaddr;
    
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    bzero( &servaddr, sizeof(servaddr));
    
    servaddr.sin_family = AF_INET;
    //The htons() function converts the unsigned short integer hostshort from host byte order to network byte order.
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);   //bind to all interfaces
    //The inet_addr() function converts the Internet host address cp from IPv4 numbers-and-dots notation into binary data in network byte order. 
    //servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(22000);
    
    int opt_val = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof opt_val);
    
    // int setsockopt(int s, int level, int optname, const void *optval, socklen_t optlen);
    
    // As for parameters, s is the socket you're talking about, level should be set to SOL_SOCKET. Then you set the optname to the name you're interested in. Again, see your man page for all the options, but here are some of the most fun ones:

    // SO_BINDTODEVICE

    // Bind this socket to a symbolic device name like eth0 instead of using bind() to bind it to an IP address. Type the command ifconfig under Unix to see the device names.

    // SO_REUSEADDR

    // Allows other sockets to bind() to this port, unless there is an active listening socket bound to the port already. This enables you to get around those "Address already in use" error messages when you try to restart your server after a crash.

    // SO_BROADCAST

    // Allows UDP datagram (SOCK_DGRAM) sockets to send and receive packets sent to and from the broadcast address. Does nothing—NOTHING!!—to TCP stream sockets! Hahaha!

    // As for the parameter optval, it's usually a pointer to an int indicating the value in question. For booleans, zero is false, and non-zero is true. And that's an absolute fact, unless it's different on your system. If there is no parameter to be passed, optval can be NULL.

    // The final parameter, optlen, should be set to the length of optval, probably sizeof(int), but varies depending on the option. Note that in the case of getsockopt(), this is a pointer to a socklen_t, and it specifies the maximum size object that will be stored in optval (to prevent buffer overflows). And getsockopt() will modify the value of optlen to reflect the number of bytes actually set.
   
    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    
    listen(listen_fd, 10);
    
    comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
    
    while(1)
    {
        
        bzero( str, 100);
        
        read(comm_fd,str,100);
        
        printf("Echoing back - %s",str);
        
        write(comm_fd, str, strlen(str)+1);
        
    }
}
