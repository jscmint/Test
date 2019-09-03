#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
int main(){
    //create socket

    //ask for IP/port to server
    struct sockaddr_in cli_addr;
    memset(&cli_addr,0,sizeof(cli_addr));
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    cli_addr.sin_port = htons(1234);

    //read the data of server and send to client
    char buff_send[40]={0};
    char buff_recv[40]={0};
    //while(1){
        int sock = socket(AF_INET,SOCK_STREAM,0);
        connect(sock,(struct sockaddr*)&cli_addr,sizeof(cli_addr));
        printf("Input a string: ");
        scanf("%s",buff_send);
        write(sock,buff_send,sizeof(buff_send));
        read(sock,buff_recv,sizeof(buff_recv)-1);
        printf("Message from server:%s\n",buff_recv);
        /* memset(buff_recv,0,40); */
        /* memset(buff_send,0,40); */
        close(sock);
    //}

    return 0;




}































