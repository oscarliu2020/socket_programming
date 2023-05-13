#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
int main(){
    struct sockaddr_in serv_addr;
    struct sockaddr_in connect_addr;
    socklen_t serv_addr_len,conn;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9000);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr_len = sizeof(serv_addr);
    int fd = socket(AF_INET, SOCK_DGRAM,0);
    if(fd<0){
        perror("socket");
    }
    if(bind(fd, (struct sockaddr *)&serv_addr, serv_addr_len)<0){
        perror("bind");
    }
    char buf[1000];
    conn=sizeof(connect_addr);
    recvfrom(fd,buf, sizeof(buf),0,(struct sockaddr *)&connect_addr,&conn);
    puts(buf);
    connect_addr.sin_port=htons(9001);
    sendto(fd, buf,sizeof(buf),0,(struct sockaddr *)&connect_addr,conn);
    return 0;
}