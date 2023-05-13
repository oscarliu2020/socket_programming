#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
    struct addrinfo* addrinfo;
    getaddrinfo("127.0.0.1","443",0,&addrinfo);
    printf("addrinfo: %d\n", addrinfo->ai_addrlen);
    printf("addrinfo: %d\n", addrinfo->ai_family==AF_INET6);
    struct sockaddr_in6 *addr=(void*)addrinfo->ai_addr;
    char buf[10000];
    inet_ntop(AF_INET6,(void*)(&addr->sin6_addr),buf,INET6_ADDRSTRLEN);
    printf("%s",buf);

    return 0;
}