/*
 * @File Name: test.c
 * @Mail: 1.0
 * @Author: LH
 * @Created Time: Do not edit
 */
#include "head.h"

#define INS 5
#define MAX 100

int main() {
    FILE *fp;
    pthread_t tid[INS];
    char buff[MAX][1024];
    struct task_queue *taskQueue = (struct task_queue *)malloc(sizeof(struct task_queue));
    task_queue_init(taskQueue, MAX);
    
    for (int  i = 0; i < INS; i ++) {
        pthread_create(&tid[i], NULL, thread_run, (void *)taskQueue);
    }
    while (1) {
        int sub = 0;
        if ((fp = fopen("../a.txt", "r")) == NULL) {
            perror("fopen");
            exit(1);
        }
        while (fgets(buff[sub], 1024, fp) != NULL) {
            task_queue_push(taskQueue, buff[sub]);
            sleep(1);
            if (++ sub == MAX) {
                sub = 0;
            }
        }
        fclose(fp);
    }
    return 0;
}
