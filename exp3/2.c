//2.编写一个C语言程序，实现父进程等待子进程的功能。
//要求：
//（1）	子进程创建完毕之后调用getpid( )函数返回子进程ID。
//（2）	子进程执行完毕后，调用sleep（）函数睡眠10s
//（3）	父进程用wait（）函数等待子进程执行结束

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t father = getpid(), son;
    son = fork();
    printf("%d: ", getpid());
    if(son == 0){
        puts("son");
        sleep(10);
        exit(0);
    }
    wait(&son);
    if (getpid() == father) puts("father");
    return 0;
}

