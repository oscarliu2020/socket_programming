#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
int main(){
    struct sockaddr_in serv_addr;
    socklen_t len=sizeof(struct sockaddr_in);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(9000);
    int fd = socket(AF_INET, SOCK_DGRAM,0);
    if(fd<0){
        perror("socket");
    }
    const char* buf="Hello,world!";
    sendto(fd, "Hello",sizeof(buf),0,(struct sockaddr*)&serv_addr,len);
    char in[1024];
    recvfrom(fd,in,sizeof(in),0,(struct sockaddr*)&serv_addr,&len);
    puts(in);
    close(fd);
    return 0;
}