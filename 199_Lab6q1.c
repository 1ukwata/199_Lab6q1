#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int csum;
void *runner(void *param);

int main(int argc, char *argv[]){//parents

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    
    int upperP = atoi(argv[1]);
    int iP;
    
    int msum = 0;
    if(upperP > 0){
        for(iP = 0; iP <= upperP; iP++)
            msum += iP;
    }

    pthread_join(tid, NULL);
    //printf("child = %d\n",csum);
    //printf("parent = %d\n",msum);
    printf("csum - msum = %d\n",csum - msum);
    return 0;
    //2.5 พบ 2 แบบ 1.แม่เสร็จก่อนลูก 2.ลูกเสร็จก่อนแม่
}

void *runner(void *param){
    int upper = atoi(param);
    int i;

    csum = 0;
    if(upper > 0){
        for(i = 0; i<= upper*2; i++)
            csum+=i;
    }
    pthread_exit(0);
}