/*
 * @File Name: 2.select.c
 * @Mail: 1.0
 * @Author: LH
 * @Created Time: Do not edit
 */
#include "head.h"

#define INS 5
#define MAX 100

int main (int argc, char **argv) {
    if (argv < 2) {
        fprintf(stderr, "Usage: %s port. \n", argv[0]);
        exit(1);
    }
    int server_listen, port, sockfd;
    pthread_t tid[INS];
    int cliens[MAX] = { 0 };
    char buff[MAX][1024];
    struct task_queue *taskQueue = (struct task_queue *)malloc(sizeof(struct task_queue));
    task_queue_init(taskQueue, MAX);
    for (int i = 0; i < INS; i ++) {
        pthread_create(&tid[i], NULL, thread_run, (void *)taskQueue);

    }
    port = atoi(argv[1]);
    if ((server_listen == socket_create(port)) < 0) {
        perror("server_listen");
        exit(1);
    }
    fd_set rfds;
    int max_fd;
    max_fd = server_listen;
    cliens[server_listen] = server_listen;
    while (1) {
        FD_ZERO(&rfds);
        FD_SET(server_listen, &rfds);
        for (int i = 3; i < max_fd + 1; i ++) {
            if (cliens[i] == -1) {
                continue;
            }
            FD_SET(cliens[i], &rfds);
        }
        int ret = select(max_fd + 1, &rfds, NULL, NULL, NULL);
        if (ret < 0) {
            perror("select");
            exit(1);
        }
        if (FD_ISSET(server_listen, &rfds)) {
            if (sockfd == accept(server_listen, NULL, NULL) < 0) {
                perror("accept");
                exit(1);
            }
            if (sockfd > max_fd) {
                max_fd = sockfd;
            }
            ret --;
            cliens[sockfd] = sockfd;
        }
        for (int i = 0; i < max_fd; i ++) {
            if (cliens[i] == server_listen) {
                continue;
            }
            if (FD_ISSET(cliens[i], &rfds)) {
                ret --;
                int rsize = recv(cliens[i], buff[i], 1024, 0);
                if (rsize <= 0) {
                    close(cliens[i]);
                    cliens[i] = -1;
                }
                else {
                    task_queue_push(taskQueue, buff[i]);
                }
                if (ret -- == 0) {
                    break;
                }
            }
        }
    }
}
