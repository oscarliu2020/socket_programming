#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
char buf[1000];
size_t len=1000;
void print(struct sockaddr_in conn){
    printf("address: %#x\n",ntohl(conn.sin_addr.s_addr));
    printf("port: %d\n",ntohs(conn.sin_port));
}
int main(){
    int server;
    server=socket(AF_INET,SOCK_DGRAM,0);
    if(server<0){
        perror("socket fail");
        return 0;
    }
    struct sockaddr_in sock;
    sock.sin_family=AF_INET;
    sock.sin_port=htons(8888);
    sock.sin_addr.s_addr=INADDR_ANY;
    if(bind(server,(const struct sockaddr*)&sock,sizeof sock)<0){
        perror("bind error");
    }
    while(1){
        struct sockaddr_in conn;
        socklen_t connl=sizeof conn;
        recvfrom(server,buf,len,0,(struct sockaddr*)&conn,&connl);
        print(conn);
        puts(buf);
        if(strcmp(buf,"end")==0)break;
        memset(buf,0,sizeof buf);
    }
    close(server);
    return 0;
}