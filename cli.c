#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
void error_handling(char *message);

int main(int argc, char* argv[]) {
    int sock;
    struct sockaddr_in serv_addr;

    int str_len;

    if(argc!=3) {
        printf("Usage : %s <IP> <port>\n",argv[0]);
        exit(1);
    }
    int count = 0;
    while (1) {
        time_t start = time(NULL);
        //printf("start : %ld\n",start);

        sock=socket(PF_INET, SOCK_STREAM, 0);
        if(sock==-1) error_handling("spclet() error");

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family=AF_INET;
        serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
        serv_addr.sin_port=htons(atoi(argv[2]));
        int userans = 1;

        char message[30];
        //printf("11\n");
        //printf("userans : ");
        //scanf("%d",&userans);
        //printf("time(NULL) : %ld\n",time(NULL));
        //printf("- : %d\n",(int)(time(NULL) - start));
        while (1) {

            if ((int)(time(NULL) - start) > 1 && count < 10) {
                count++;
                break;
            }
        }
        if(userans == 0) {
            break;
        }

        if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) error_handling("connect() error!");

        //printf("12\n");
        str_len=read(sock, message, sizeof(message)-1);
        //printf("13\n");
        if(str_len==-1) error_handling("read() error!");
        //printf("14\n");

        printf("<essage from server: %s \n",message);
        close(sock);
    }

    return 0;

}

void error_handling(char *message) {
    fputs(message,stderr);
    fputc('\n',stderr);
    //exit(1);
}
