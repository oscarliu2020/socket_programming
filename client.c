#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

int main(){
    int fd;
    struct sockaddr_in address;
    fd=socket(PF_INET,SOCK_STREAM,0);
    struct sockaddr_in dest;
    dest.sin_family=AF_INET;
    dest.sin_port=htons(9099);
    dest.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(connect(fd,(struct sockaddr*)&dest,sizeof dest)<0){
        puts("connect failed");
        return 0;
    };
    char buff[1000]={0};
    size_t len=100;
    int count=recv(fd,buff,len,0);
    if(count)puts(buff);
    send(fd,buff,len,0);
}