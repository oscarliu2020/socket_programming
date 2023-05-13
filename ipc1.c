#include<sys/socket.h>
#include<sys/types.h>
#include<sys/un.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
    struct sockaddr_un sock;
    sock.sun_family=AF_UNIX;
    strcpy(sock.sun_path,"tempfile");
    sock.sun_len=sizeof(struct sockaddr_un);
    int fd;
    fd=socket(PF_LOCAL,SOCK_STREAM,0);
    if(fd<0)perror("Socket error");
    if(bind(fd,(const struct sockaddr*)&sock,sizeof (socklen_t))<0)perror("bind error");
    printf("%s\n", sock.sun_path);
    close(fd);
    if(unlink(sock.sun_path)<0)perror("unlink error");
    return 0;
}