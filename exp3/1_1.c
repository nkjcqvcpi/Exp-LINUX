#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t father = getpid(), son, daughter;
    son = fork();
    if(son == 0){
        puts("son");
        return 0;
    }
    daughter = fork();
    if(daughter == 0){
        puts("daughter");
        return 0;
    }
    if (getpid() == father) puts("father");
    return 0;
}
