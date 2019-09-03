#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
int main(){
    //create socket
    int serv_sock = socket(AF_INET,SOCK_STREAM,0);

    //bind socket with IP/port
    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);
    bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    //get into listen.wait for user request
    listen(serv_sock,20);

    //recevie the request from client
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    char buff[40];
    while(1){
        int clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_addr_size);
        //send the data to client
        read(clnt_sock,buff,sizeof(buff)-1);
        printf("Message from client:%s\n",buff);
        write(clnt_sock,buff,sizeof(buff));
        memset(buff,0,40);
        close(clnt_sock);
    }
    close(serv_sock);

    return 0;




}































