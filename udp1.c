#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
int main(){
    int client;
    client=socket(AF_INET,SOCK_DGRAM,0);
    if(client<0){
        perror("socket error");
        return 0;
    }
    short port;
    scanf("%hd",&port);
    struct sockaddr_in sock,dest;
    sock.sin_family=AF_INET;
    sock.sin_port=htons(port);
    sock.sin_addr.s_addr=inet_addr("127.0.0.1");
    dest.sin_family=AF_INET;
    dest.sin_port=htons(8888);
    dest.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(bind(client,(const struct sockaddr*)&sock,sizeof sock)<0){
        perror("bind error");
        return 0;
    }
    char s[100];
    while(~scanf("%s",s)){
        sendto(client,s,strlen(s),0,(const struct sockaddr *)&dest,sizeof dest);
        memset(s,0,sizeof s);
    }
    close(client);
    return 0;
}