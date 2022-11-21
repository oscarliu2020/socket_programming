#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
int main(){
    int server_fd;
    struct sockaddr_in address,cl;
    server_fd=socket(AF_INET,SOCK_STREAM,0);
    if(server_fd<0){
        puts("socket failed");
        return 0;
    }
    address.sin_family=AF_INET;
    address.sin_port=htons(9099);
    address.sin_addr.s_addr=INADDR_ANY;
    if(bind(server_fd,(const struct sockaddr*)&address,sizeof(address))==-1){
        puts("bind failed");
        return 0;
    }
    if(listen(server_fd,10)<0)
        puts("listen failed");
    socklen_t len;
    int s=accept(server_fd,(struct sockaddr*)&cl,&len);
    if(s<0){
        puts("accept failed");
    }
    const char* h="hello";
    if(send(s,h,strlen(h),0)!=strlen(h)){
        puts("send fail");
    };
    char buf[100]={0};
    size_t ll=100;
    int count=recv(s,buf,ll,0);
    if(count)puts(buf);
}