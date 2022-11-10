//1.编写一个C语言程序，实现在程序运行时通过系统调用fork()创建两个子进程
//（1）	使父、子、女三进程并发执行，父亲进程执行时屏幕显示“father”，儿子进程执行时屏幕显示“son”，女儿进程执行时屏幕显示“daughter”。
//（2）	修改程序，在父、子进程中分别使用wait、exit等系统调用“实现”其同步推进。

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t father = getpid(), son, daughter;
    son = fork();
    if(son == 0){
        puts("son");
        exit(0);
    }
    daughter = fork();
    if(daughter == 0){
        puts("daughter");
        exit(0);
    }
    wait(&son);
    wait(&daughter);
    if (getpid() == father) puts("father");
    return 0;
}

